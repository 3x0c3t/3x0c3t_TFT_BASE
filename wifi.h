#ifndef WIFI_H
#define WIFI_H

#include <Arduino.h>

void wifiInit();
void wifiUpdate();

bool wifiIsConnected();

#endif