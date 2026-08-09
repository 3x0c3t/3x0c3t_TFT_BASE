#include "wifi.h"

#include <Arduino.h>
#include <ESP8266WiFi.h>

#include "config.h"
#include "secrets.h"
#include "display.h"

bool wifiConnected = false;

static unsigned long lastWifiAttempt = 0;

void wifiInit()
{
    Serial.println();
    Serial.println("================================");
    Serial.println("[WIFI] SCAN DES RESEAUX");
    Serial.println("================================");

    WiFi.mode(WIFI_STA);

    WiFi.disconnect();

    delay(500);

    int count = WiFi.scanNetworks();

    Serial.print("[WIFI] Reseaux trouves : ");
    Serial.println(count);

    if (count <= 0)
    {
        Serial.println("[WIFI] Aucun reseau detecte");
    }
    else
    {
        for (int i = 0; i < count; i++)
        {
            Serial.print("[WIFI] ");
            Serial.print(i);
            Serial.print(" : ");
            Serial.print(WiFi.SSID(i));
            Serial.print(" | RSSI : ");
            Serial.print(WiFi.RSSI(i));
            Serial.print(" dBm | CH : ");
            Serial.println(WiFi.channel(i));
        }
    }

    Serial.println();
    Serial.println("[WIFI] Configuration");

    Serial.print("[WIFI1] ");
    Serial.println(WIFI1_SSID);

    Serial.print("[WIFI2] ");
    Serial.println(WIFI2_SSID);

    Serial.println();
    Serial.println("[WIFI] Fin du scan");
}

void wifiUpdate()
{
}

bool wifiIsConnected()
{
    return WiFi.status() == WL_CONNECTED;
}