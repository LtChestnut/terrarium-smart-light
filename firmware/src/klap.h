// TP-Link Tapo KLAP v2 crypto, device (server) side.
//
// The derivation is the one the tapo_light_display knob's client uses (verified against
// python-kasa's KlapTransportV2 / KlapEncryptionSession):
//   auth_hash  = SHA256(SHA1(email) || SHA1(password))
//   handshake1 = client sends local_seed(16); device answers
//                remote_seed(16) || SHA256(local || remote || auth)
//   handshake2 = client sends SHA256(remote || local || auth)
//   x = local || remote || auth
//   key = SHA256("lsk"||x)[:16], ivseq = SHA256("iv"||x), iv = ivseq[:12],
//   seq0 = int32_be(ivseq[28:32]), sig = SHA256("ldk"||x)[:28]
//   message for seq n: AES-128-CBC/PKCS7 with IV = iv || be32(n),
//                      body = SHA256(sig || be32(n) || ct) || ct  (both directions)
#pragma once

#include <stddef.h>
#include <stdint.h>

#include <string>
#include <vector>

namespace klap {

void authHash(const char *email, const char *password, uint8_t out[32]);
void handshake1Hash(const uint8_t local[16], const uint8_t remote[16], const uint8_t auth[32], uint8_t out[32]);
void handshake2Hash(const uint8_t local[16], const uint8_t remote[16], const uint8_t auth[32], uint8_t out[32]);

class Cipher {
 public:
  void init(const uint8_t local[16], const uint8_t remote[16], const uint8_t auth[32]);

  // The client's seq before its first request (it pre-increments).
  int32_t initialSeq() const { return seq0_; }
  const uint8_t *key() const { return key_; }

  // Encrypts with the IV for `seq` and returns SHA256(sig||seq||ct) || ct.
  void seal(int32_t seq, const uint8_t *plain, size_t len, std::vector<uint8_t> &out) const;
  // Checks the signature, then decrypts. False on bad length, signature or padding.
  bool open(int32_t seq, const uint8_t *body, size_t len, std::string &out, bool checkSig = true) const;

 private:
  void ivFor(int32_t seq, uint8_t iv[16]) const;
  void signature(int32_t seq, const uint8_t *ct, size_t len, uint8_t out[32]) const;

  uint8_t key_[16] = {};
  uint8_t iv_[12] = {};
  uint8_t sig_[28] = {};
  int32_t seq0_ = 0;
};

}  // namespace klap
