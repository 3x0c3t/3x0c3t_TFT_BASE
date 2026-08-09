#include "pMain.h"
#include "display.h"
#include "config.h"
#include "pages.h"

// ============================================================
// PAGE MAIN
// ============================================================

void pMainInit()
{
    Serial.println("[PMAIN] pMainInit()");
}

// ============================================================
// AFFICHAGE
// ============================================================

void pMainShow()
{
    Serial.println("[PMAIN] ================================");
    Serial.println("[PMAIN] pMainShow() START");

    clearContent();

    Serial.println("[PMAIN] drawTitle()");
    drawTitle("-3x0c3t- B04RD");

    Serial.println("[PMAIN] drawButton METEO");

    drawButton(
        20,
        CONTENT_Y + 35,
        200,
        45,
        "METEO",
        COLOR_BUTTON_BG
    );

    Serial.println("[PMAIN] drawButton WIFI");

    drawButton(
        20,
        CONTENT_Y + 100,
        200,
        45,
        "WiFi",
        COLOR_BUTTON_BG
    );

    Serial.println("[PMAIN] pMainShow() END");
    Serial.println("[PMAIN] ================================");
}

// ============================================================
// UPDATE
// ============================================================

void pMainUpdate()
{
}

// ============================================================
// BOUTONS
// ============================================================

void pMainButtonUp()
{
    Serial.println("[PMAIN] BUTTON UP");
}

void pMainButtonDown()
{
    Serial.println("[PMAIN] BUTTON DOWN");
}

void pMainButtonLeft()
{
    Serial.println("[PMAIN] BUTTON LEFT");
}

void pMainButtonRight()
{
    Serial.println("[PMAIN] BUTTON RIGHT");
}

// ============================================================
// OK
// ============================================================

void pMainButtonOk()
{
    Serial.println("[PMAIN] ================================");
    Serial.println("[PMAIN] BUTTON OK");
    Serial.println("[PMAIN] -> ouverture PAGE_METEO");

    pagesSet(PAGE_METEO);

    Serial.println("[PMAIN] PAGE_METEO demandee");
    Serial.println("[PMAIN] ================================");
}

void pMainButtonCancel()
{
    Serial.println("[PMAIN] BUTTON CANCEL");
}

void pMainButtonMenu()
{
    Serial.println("[PMAIN] BUTTON MENU");
}