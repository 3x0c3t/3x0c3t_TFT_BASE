#include <Arduino.h>

#include "config.h"
#include "display.h"
#include "splash.h"
#include "pages.h"

#include "pMain.h"
#include "pMeteo.h"
#include "pSettings.h"
#include "pSystem.h"
#include "pWifi.h"

#include "clock.h"
#include "wifi.h"
#include "weather.h"

// ============================================================
// SETUP
// ============================================================

void setup()
{
    Serial.begin(115200);
    delay(100);

    Serial.println();
    Serial.println();
    Serial.println("================================");
    Serial.println("3x0c3t TFT BASE");
    Serial.println("================================");

    Serial.println("[BOOT] setup() START");

    // --------------------------------------------------------
    // AFFICHAGE
    // --------------------------------------------------------

    Serial.println("[BOOT] displayInit() START");
    displayInit();
    Serial.println("[BOOT] displayInit() END");

    // --------------------------------------------------------
    // SPLASH
    // --------------------------------------------------------

    Serial.println("[BOOT] splashShow() START");
    splashShow();
    Serial.println("[BOOT] splashShow() END");

    // --------------------------------------------------------
    // INITIALISATION DES PAGES
    // --------------------------------------------------------

    Serial.println("[BOOT] pagesInit() START");
    pagesInit();
    Serial.println("[BOOT] pagesInit() END");

    Serial.println("[BOOT] pMainInit() START");
    pMainInit();
    Serial.println("[BOOT] pMainInit() END");

    Serial.println("[BOOT] pMeteoInit() START");
    pMeteoInit();
    Serial.println("[BOOT] pMeteoInit() END");

    Serial.println("[BOOT] pSettingsInit() START");
    pSettingsInit();
    Serial.println("[BOOT] pSettingsInit() END");

    Serial.println("[BOOT] pSystemInit() START");
    pSystemInit();
    Serial.println("[BOOT] pSystemInit() END");

    Serial.println("[BOOT] pWifiInit() START");
    pWifiInit();
    Serial.println("[BOOT] pWifiInit() END");

    // --------------------------------------------------------
    // SERVICES
    // --------------------------------------------------------

    Serial.println("[BOOT] wifiInit() START");
    wifiInit();
    Serial.println("[BOOT] wifiInit() END");

    // --------------------------------------------------------
    // AFFICHAGE MAIN
    // --------------------------------------------------------

    Serial.println("[BOOT] pagesShow(PAGE_MAIN) START");
    pagesShow(PAGE_MAIN);
    Serial.println("[BOOT] pagesShow(PAGE_MAIN) END");

    Serial.println("[BOOT] MAIN actif");
    Serial.println("[BOOT] setup() END");
}

// ============================================================
// LOOP
// ============================================================

void loop()
{
    static unsigned long lastLoopLog = 0;

    unsigned long now = millis();

    // --------------------------------------------------------
    // LOG PERIODIQUE
    // --------------------------------------------------------

    if (now - lastLoopLog >= 5000)
    {
        lastLoopLog = now;

        Serial.print("[LOOP] actif - page = ");

        switch (pagesGetCurrent())
        {
            case PAGE_MAIN:
                Serial.println("MAIN");
                break;

            case PAGE_METEO:
                Serial.println("METEO");
                break;

            case PAGE_SETTINGS:
                Serial.println("SETTINGS");
                break;

            case PAGE_SYSTEM:
                Serial.println("SYSTEM");
                break;

            case PAGE_WIFI:
                Serial.println("WIFI");
                break;

            default:
                Serial.println("UNKNOWN");
                break;
        }
    }

    // --------------------------------------------------------
    // HEADER
    // --------------------------------------------------------

    drawHeaderTime();

    // --------------------------------------------------------
    // PAGE
    // --------------------------------------------------------

    pagesUpdate();

    delay(1000);
}