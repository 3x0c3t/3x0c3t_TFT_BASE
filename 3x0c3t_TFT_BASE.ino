#include <Arduino.h>

#include "config.h"
#include "display.h"
#include "wifi.h"
#include "weather.h"
#include "clock.h"

// ============================================================
// SETUP
// ============================================================

void setup()
{
    Serial.begin(115200);

    delay(500);

    Serial.println();
    Serial.println("================================");
    Serial.println("[BOOT] DEMARRAGE");
    Serial.println("================================");

    displayInit();

    clockInit();

    wifiInit();

    weatherInit();

    Serial.println();
    Serial.println("[BOOT] Initialisation terminee");
}

// ============================================================
// LOOP
// ============================================================

void loop()
{
    wifiUpdate();

    clockUpdate();

    weatherUpdate();

    drawHeaderTime();

    delay(1000);
}