// Wi-Fi station: connect, auto-reconnect, optional fixed IP (secrets.h).
#pragma once

namespace net {

// False if secrets.h still has the placeholder values (network stays off).
bool begin();
bool online();

}  // namespace net
