#include <Arduino.h>

#include "touch.h"
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
    Serial.println("================================");
    Serial.println("3x0c3t TFT BASE");
    Serial.println("================================");

    // --------------------------------------------------------
    // AFFICHAGE
    // --------------------------------------------------------

    Serial.println("[BOOT] displayInit() START");

    displayInit();

    Serial.println("[BOOT] displayInit() END");

    // --------------------------------------------------------
    // TACTILE
    // --------------------------------------------------------

    Serial.println("[BOOT] touchInit() START");

    touchInit();

    Serial.println("[BOOT] touchInit() END");

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

    // --------------------------------------------------------
    // INITIALISATION DES PAGES
    // --------------------------------------------------------

    Serial.println("[BOOT] pMainInit()");
    pMainInit();

    Serial.println("[BOOT] pMeteoInit()");
    pMeteoInit();

    Serial.println("[BOOT] pSettingsInit()");
    pSettingsInit();

    Serial.println("[BOOT] pSystemInit()");
    pSystemInit();

    Serial.println("[BOOT] pWifiInit()");
    pWifiInit();

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
    // TACTILE
    // --------------------------------------------------------

    touchUpdate();

    // --------------------------------------------------------
    // PAGE
    // --------------------------------------------------------

    pagesUpdate();

    // --------------------------------------------------------
    // HORLOGE
    // --------------------------------------------------------

    drawHeaderTime();

    // --------------------------------------------------------
    // PETITE PAUSE
    // --------------------------------------------------------

    delay(50);
}