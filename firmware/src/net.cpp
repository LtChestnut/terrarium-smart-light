#include "net.h"

#include <Arduino.h>
#include <WiFi.h>
#include <string.h>

#include "config.h"
#include "secrets.h"

namespace net {

bool begin() {
  if (strcmp(WIFI_SSID, "your-ssid") == 0) {
    Serial.println("[net] include/secrets.h has placeholder values; Wi-Fi disabled");
    return false;
  }
  WiFi.onEvent([](WiFiEvent_t event, WiFiEventInfo_t info) {
    switch (event) {
      case ARDUINO_EVENT_WIFI_STA_GOT_IP:
        Serial.printf("[net] online: %s  RSSI %d dBm  MAC %s\n", WiFi.localIP().toString().c_str(),
                      WiFi.RSSI(), WiFi.macAddress().c_str());
        break;
      case ARDUINO_EVENT_WIFI_STA_DISCONNECTED:
        Serial.printf("[net] disconnected, reason %u\n", info.wifi_sta_disconnected.reason);
        break;
      default:
        break;
    }
  });
  WiFi.persistent(false);
  WiFi.mode(WIFI_STA);
  WiFi.setHostname(DEVICE_HOSTNAME);
  WiFi.setSleep(false);  // modem sleep adds 100+ ms to every request from the knob
  WiFi.setAutoReconnect(true);
#ifdef LIGHT_IP
  {
    IPAddress ip, gw, mask, dns;
    ip.fromString(LIGHT_IP);
    gw.fromString(LIGHT_GATEWAY);
    mask.fromString(LIGHT_SUBNET);
    dns.fromString(LIGHT_DNS);
    WiFi.config(ip, gw, mask, dns);
  }
#endif
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.printf("[net] connecting to \"%s\"\n", WIFI_SSID);
  return true;
}

bool online() { return WiFi.status() == WL_CONNECTED; }

}  // namespace net
