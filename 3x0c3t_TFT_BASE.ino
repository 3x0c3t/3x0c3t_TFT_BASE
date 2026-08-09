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
    Serial.println("================================");
    Serial.println("3x0c3t TFT BASE");
    Serial.println("================================");

    // --------------------------------------------------------
    // AFFICHAGE
    // --------------------------------------------------------

    displayInit();

    // --------------------------------------------------------
    // SPLASH
    // --------------------------------------------------------

    splashShow();

    // --------------------------------------------------------
    // INITIALISATION DES PAGES
    // --------------------------------------------------------

    pagesInit();

    pMainInit();
    pMeteoInit();
    pSettingsInit();
    pSystemInit();
    pWifiInit();

    // --------------------------------------------------------
    // SERVICES
    // --------------------------------------------------------

    wifiInit();

    // --------------------------------------------------------
    // AFFICHAGE MAIN
    // --------------------------------------------------------

    pagesShow(PAGE_MAIN);

    Serial.println("[BOOT] MAIN actif");
}


// ============================================================
// LOOP
// ============================================================

void loop()
{
    drawHeaderTime();

    pagesUpdate();

    delay(1000);
}