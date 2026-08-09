#ifndef WIFI_H
#define WIFI_H

#include <Arduino.h>

extern bool wifiConnected;

void wifiInit();
void wifiUpdate();

bool wifiIsConnected();

#endif