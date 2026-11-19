#include "tapo_server.h"

#include <Arduino.h>
#include <WiFi.h>
#include <esp_random.h>
#include <string.h>

#include <vector>

#include "config.h"
#include "klap.h"
#include "secrets.h"
#include "tapo_device.h"

namespace tapo_server {
namespace {

constexpr uint16_t kPort = 80;
constexpr int kMaxSessions = 4;
constexpr size_t kMaxBody = 4096;
constexpr uint32_t kIoTimeoutMs = 3000;
constexpr uint32_t kPendingTimeoutMs = 30 * 1000;  // handshake1 -> handshake2

struct Session {
  bool used = false;
  bool established = false;
  char cookie[33] = {};  // 32 hex chars
  uint8_t local[16];
  uint8_t remote[16];
  klap::Cipher cipher;
  int32_t lastSeq = 0;
  uint32_t createdMs = 0;
  uint32_t lastUseMs = 0;
};

Session s_sessions[kMaxSessions];
uint8_t s_auth[32];
WiFiServer s_server(kPort);

struct Request {
  String method;
  String path;
  String cookie;  // TP_SESSIONID value
  std::vector<uint8_t> body;
};

bool expired(const Session &s, uint32_t now) {
  if (!s.used) return true;
  if (!s.established) return now - s.createdMs > kPendingTimeoutMs;
  return now - s.createdMs > TAPO_SESSION_TIMEOUT_S * 1000UL;
}

Session *find(const String &cookie) {
  const uint32_t now = millis();
  for (Session &s : s_sessions) {
    if (s.used && !expired(s, now) && cookie == s.cookie) return &s;
  }
  return nullptr;
}

Session &allocate() {
  const uint32_t now = millis();
  Session *victim = &s_sessions[0];
  for (Session &s : s_sessions) {
    if (expired(s, now)) {
      victim = &s;
      break;
    }
    if (now - s.lastUseMs > now - victim->lastUseMs) victim = &s;  // least recently used
  }
  *victim = Session{};
  victim->used = true;
  victim->createdMs = victim->lastUseMs = now;
  uint8_t r[16];
  esp_fill_random(r, sizeof(r));
  for (int i = 0; i < 16; ++i) snprintf(victim->cookie + 2 * i, 3, "%02X", r[i]);
  return *victim;
}

bool readLine(WiFiClient &c, String &line, uint32_t deadline) {
  line = "";
  while (static_cast<int32_t>(millis() - deadline) < 0) {
    while (c.available()) {
      const char ch = static_cast<char>(c.read());
      if (ch == '\n') {
        if (line.endsWith("\r")) line.remove(line.length() - 1);
        return true;
      }
      line += ch;
      if (line.length() > 1024) return false;
    }
    if (!c.connected()) return false;
    delay(1);
  }
  return false;
}

bool readRequest(WiFiClient &c, Request &req) {
  const uint32_t deadline = millis() + kIoTimeoutMs;
  String line;
  if (!readLine(c, line, deadline)) return false;
  const int sp1 = line.indexOf(' ');
  const int sp2 = line.indexOf(' ', sp1 + 1);
  if (sp1 < 0 || sp2 < 0) return false;
  req.method = line.substring(0, sp1);
  req.path = line.substring(sp1 + 1, sp2);

  long contentLength = 0;
  while (readLine(c, line, deadline) && line.length()) {
    String lower = line;
    lower.toLowerCase();
    if (lower.startsWith("content-length:")) {
      contentLength = line.substring(15).toInt();
    } else if (lower.startsWith("cookie:")) {
      const int sid = line.indexOf("TP_SESSIONID=");
      if (sid >= 0) {
        int end = line.indexOf(';', sid);
        req.cookie = end > 0 ? line.substring(sid + 13, end) : line.substring(sid + 13);
        req.cookie.trim();
      }
    }
  }
  if (contentLength < 0 || contentLength > static_cast<long>(kMaxBody)) return false;
  req.body.resize(contentLength);
  size_t got = 0;
  while (got < req.body.size() && static_cast<int32_t>(millis() - deadline) < 0) {
    const int n = c.read(req.body.data() + got, req.body.size() - got);
    if (n > 0) got += n;
    else if (!c.connected()) break;
    else delay(1);
  }
  return got == req.body.size();
}

void respond(WiFiClient &c, int status, const uint8_t *body = nullptr, size_t len = 0,
             const char *setCookie = nullptr) {
  const char *reason = status == 200 ? "OK" : status == 403 ? "Forbidden" : status == 404 ? "Not Found" : "Bad Request";
  char hdr[256];
  int n = snprintf(hdr, sizeof(hdr),
                   "HTTP/1.1 %d %s\r\nContent-Type: application/octet-stream\r\nContent-Length: %u\r\n",
                   status, reason, static_cast<unsigned>(len));
  if (setCookie) n += snprintf(hdr + n, sizeof(hdr) - n, "Set-Cookie: %s\r\n", setCookie);
  n += snprintf(hdr + n, sizeof(hdr) - n, "Connection: close\r\n\r\n");
  c.write(reinterpret_cast<const uint8_t *>(hdr), n);
  if (len) c.write(body, len);
}

void handshake1(WiFiClient &c, const Request &req) {
  if (req.body.size() != 16) return respond(c, 400);
  Session &s = allocate();
  memcpy(s.local, req.body.data(), 16);
  esp_fill_random(s.remote, 16);
  uint8_t out[48];
  memcpy(out, s.remote, 16);
  klap::handshake1Hash(s.local, s.remote, s_auth, out + 16);
  char cookie[80];
  snprintf(cookie, sizeof(cookie), "TP_SESSIONID=%s;TIMEOUT=%d", s.cookie, TAPO_SESSION_TIMEOUT_S);
  respond(c, 200, out, sizeof(out), cookie);
}

void handshake2(WiFiClient &c, const Request &req) {
  Session *s = find(req.cookie);
  if (!s || s->established || req.body.size() != 32) return respond(c, 403);
  uint8_t expect[32];
  klap::handshake2Hash(s->local, s->remote, s_auth, expect);
  if (memcmp(expect, req.body.data(), 32) != 0) {
    // The client's credentials differ from ours (or it's not a KLAP client).
    Serial.printf("[tapo] %s: handshake2 rejected (credentials mismatch?)\n",
                  c.remoteIP().toString().c_str());
    s->used = false;
    return respond(c, 403);
  }
  s->cipher.init(s->local, s->remote, s_auth);
  s->lastSeq = s->cipher.initialSeq();
  s->established = true;
  s->lastUseMs = millis();
  Serial.printf("[tapo] %s: session established\n", c.remoteIP().toString().c_str());
  respond(c, 200);
}

void request(WiFiClient &c, const Request &req) {
  Session *s = find(req.cookie);
  if (!s || !s->established) return respond(c, 403);
  const int q = req.path.indexOf("seq=");
  if (q < 0) return respond(c, 400);
  const int32_t seq = static_cast<int32_t>(strtol(req.path.c_str() + q + 4, nullptr, 10));
  // Reject replays: seq must move forward (wrap-aware, like the device's int32 counter).
  if (static_cast<int32_t>(static_cast<uint32_t>(seq) - static_cast<uint32_t>(s->lastSeq)) <= 0) {
    return respond(c, 403);
  }
  std::string plain;
  if (!s->cipher.open(seq, req.body.data(), req.body.size(), plain)) return respond(c, 403);
  s->lastSeq = seq;
  s->lastUseMs = millis();

  const std::string reply = tapo_device::handle(plain.data(), plain.size());
  std::vector<uint8_t> body;
  s->cipher.seal(seq, reinterpret_cast<const uint8_t *>(reply.data()), reply.size(), body);
  respond(c, 200, body.data(), body.size());
}

void serve(WiFiClient &c) {
  c.setNoDelay(true);
  Request req;
  if (!readRequest(c, req)) return;
  if (req.method != "POST") return respond(c, 404);
  if (req.path == "/app/handshake1") return handshake1(c, req);
  if (req.path == "/app/handshake2") return handshake2(c, req);
  if (req.path.startsWith("/app/request")) return request(c, req);
  respond(c, 404);
}

void task(void *) {
  bool listening = false;
  for (;;) {
    if (WiFi.status() != WL_CONNECTED) {
      vTaskDelay(pdMS_TO_TICKS(200));
      continue;
    }
    if (!listening) {
      s_server.begin();
      s_server.setNoDelay(true);
      listening = true;
      Serial.printf("[tapo] KLAP server on %s:%u\n", WiFi.localIP().toString().c_str(), kPort);
    }
    WiFiClient c = s_server.accept();
    if (c) {
      serve(c);
      c.stop();
    } else {
      vTaskDelay(pdMS_TO_TICKS(5));
    }
  }
}

}  // namespace

void begin() {
  klap::authHash(TAPO_EMAIL, TAPO_PASSWORD, s_auth);
  xTaskCreate(task, "tapo", 8192, nullptr, 3, nullptr);
}

}  // namespace tapo_server
