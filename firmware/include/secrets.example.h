// Copy to include/secrets.h (git-ignored) and fill in. Never commit secrets.h.
#pragma once

// 2.4 GHz Wi-Fi (the XIAO C6/S3 have no 5 GHz radio).
#define WIFI_SSID "your-ssid"
#define WIFI_PASSWORD "your-wifi-password"

// The Tapo account the controller (tapo_light_display knob) uses. The light derives the same
// KLAP auth hash from it, so the knob's handshake succeeds. Nothing is sent to TP-Link.
#define TAPO_EMAIL "you@example.com"
#define TAPO_PASSWORD "your-tapo-password"

// Optional fixed address. The knob reaches lights by IP (TAPO_BULB_IPS in its secrets.h), so
// either reserve the light's address on the router or set one here.
// #define LIGHT_IP "192.168.1.60"
// #define LIGHT_GATEWAY "192.168.1.1"
// #define LIGHT_SUBNET "255.255.255.0"
// #define LIGHT_DNS "192.168.1.1"
