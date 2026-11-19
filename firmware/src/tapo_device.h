// Tapo SMART-protocol request handling (the JSON inside the KLAP envelope), emulating an
// L530 colour bulb closely enough for the tapo_light_display knob and python-kasa.
#pragma once

#include <stddef.h>

#include <string>

namespace tapo_device {

// `request` is the decrypted JSON ({"method":..,"params":{..},...}); returns the reply JSON.
std::string handle(const char *request, size_t len);

}  // namespace tapo_device
