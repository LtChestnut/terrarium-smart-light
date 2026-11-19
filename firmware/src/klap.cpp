#include "klap.h"

#include <mbedtls/aes.h>
#include <mbedtls/sha1.h>
#include <mbedtls/sha256.h>
#include <string.h>

namespace klap {
namespace {

struct Sha256 {
  mbedtls_sha256_context ctx;
  Sha256() {
    mbedtls_sha256_init(&ctx);
    mbedtls_sha256_starts(&ctx, 0);
  }
  ~Sha256() { mbedtls_sha256_free(&ctx); }
  Sha256 &add(const void *p, size_t n) {
    mbedtls_sha256_update(&ctx, static_cast<const uint8_t *>(p), n);
    return *this;
  }
  void finish(uint8_t out[32]) { mbedtls_sha256_finish(&ctx, out); }
};

void be32(int32_t v, uint8_t out[4]) {
  const uint32_t u = static_cast<uint32_t>(v);
  out[0] = u >> 24;
  out[1] = u >> 16;
  out[2] = u >> 8;
  out[3] = u;
}

}  // namespace

void authHash(const char *email, const char *password, uint8_t out[32]) {
  uint8_t h[40];
  mbedtls_sha1(reinterpret_cast<const uint8_t *>(email), strlen(email), h);
  mbedtls_sha1(reinterpret_cast<const uint8_t *>(password), strlen(password), h + 20);
  Sha256().add(h, sizeof(h)).finish(out);
  memset(h, 0, sizeof(h));
}

void handshake1Hash(const uint8_t local[16], const uint8_t remote[16], const uint8_t auth[32], uint8_t out[32]) {
  Sha256().add(local, 16).add(remote, 16).add(auth, 32).finish(out);
}

void handshake2Hash(const uint8_t local[16], const uint8_t remote[16], const uint8_t auth[32], uint8_t out[32]) {
  Sha256().add(remote, 16).add(local, 16).add(auth, 32).finish(out);
}

void Cipher::init(const uint8_t ls[16], const uint8_t rs[16], const uint8_t ah[32]) {
  uint8_t d[32];
  Sha256().add("lsk", 3).add(ls, 16).add(rs, 16).add(ah, 32).finish(d);
  memcpy(key_, d, 16);
  Sha256().add("iv", 2).add(ls, 16).add(rs, 16).add(ah, 32).finish(d);
  memcpy(iv_, d, 12);
  seq0_ = static_cast<int32_t>((uint32_t(d[28]) << 24) | (uint32_t(d[29]) << 16) |
                               (uint32_t(d[30]) << 8) | uint32_t(d[31]));
  Sha256().add("ldk", 3).add(ls, 16).add(rs, 16).add(ah, 32).finish(d);
  memcpy(sig_, d, 28);
}

void Cipher::ivFor(int32_t seq, uint8_t iv[16]) const {
  memcpy(iv, iv_, 12);
  be32(seq, iv + 12);
}

void Cipher::signature(int32_t seq, const uint8_t *ct, size_t len, uint8_t out[32]) const {
  uint8_t s[4];
  be32(seq, s);
  Sha256().add(sig_, 28).add(s, 4).add(ct, len).finish(out);
}

void Cipher::seal(int32_t seq, const uint8_t *plain, size_t len, std::vector<uint8_t> &out) const {
  const size_t pad = 16 - (len % 16);
  const size_t ctLen = len + pad;
  out.assign(32 + ctLen, 0);
  uint8_t *ct = out.data() + 32;
  memcpy(ct, plain, len);
  memset(ct + len, static_cast<int>(pad), pad);

  uint8_t iv[16];
  ivFor(seq, iv);
  mbedtls_aes_context aes;
  mbedtls_aes_init(&aes);
  mbedtls_aes_setkey_enc(&aes, key_, 128);
  mbedtls_aes_crypt_cbc(&aes, MBEDTLS_AES_ENCRYPT, ctLen, iv, ct, ct);
  mbedtls_aes_free(&aes);

  signature(seq, ct, ctLen, out.data());
}

bool Cipher::open(int32_t seq, const uint8_t *body, size_t len, std::string &out, bool checkSig) const {
  if (len < 32 + 16 || (len - 32) % 16 != 0) return false;
  const uint8_t *ct = body + 32;
  const size_t ctLen = len - 32;

  if (checkSig) {
    uint8_t expect[32];
    signature(seq, ct, ctLen, expect);
    uint8_t diff = 0;  // constant time
    for (int i = 0; i < 32; ++i) diff |= expect[i] ^ body[i];
    if (diff) return false;
  }

  std::vector<uint8_t> pt(ctLen);
  uint8_t iv[16];
  ivFor(seq, iv);
  mbedtls_aes_context aes;
  mbedtls_aes_init(&aes);
  mbedtls_aes_setkey_dec(&aes, key_, 128);
  mbedtls_aes_crypt_cbc(&aes, MBEDTLS_AES_DECRYPT, ctLen, iv, ct, pt.data());
  mbedtls_aes_free(&aes);

  const uint8_t pad = pt[ctLen - 1];
  if (pad == 0 || pad > 16) return false;
  for (size_t i = ctLen - pad; i < ctLen; ++i)
    if (pt[i] != pad) return false;
  out.assign(reinterpret_cast<const char *>(pt.data()), ctLen - pad);
  return true;
}

}  // namespace klap
