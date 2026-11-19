// KLAP v2 HTTP server on port 80: the device side of the Tapo local protocol.
//
//   POST /app/handshake1          body local_seed(16)   -> remote_seed || SHA256(local||remote||auth)
//                                                          + Set-Cookie TP_SESSIONID=..;TIMEOUT=86400
//   POST /app/handshake2          body SHA256(remote||local||auth), cookie -> 200 / 403
//   POST /app/request?seq=<n>     body sig||ct, cookie  -> sig||ct of the JSON reply
//
// Unknown or expired sessions, bad signatures and replayed seqs get HTTP 403, which makes
// clients (the knob, python-kasa) re-handshake. Several sessions are kept so more than one
// controller can talk to the light at once.
#pragma once

namespace tapo_server {

// Runs the server in its own task. Requires secrets.h credentials.
void begin();

}  // namespace tapo_server
