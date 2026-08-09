#ifndef WIFI_H
#define WIFI_H

#include <Arduino.h>

enum WifiMode
{
    WIFI_MODE_DISCONNECTED,
    WIFI_MODE_CLIENT,
    WIFI_MODE_AP
};

extern WifiMode wifiMode;
extern bool wifiConnected;

void wifiInit();
void wifiUpdate();

bool wifiIsConnected();
bool wifiIsAP();

String wifiGetIP();
String wifiGetSSID();

#endif

