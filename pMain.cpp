#include "pMain.h"
#include "config.h"
#include "display.h"

// ============================================================
// INITIALISATION
// ============================================================

void pMainInit()
{
    Serial.println("[PMAIN] ================================");
    Serial.println("[PMAIN] pMainInit() START");

    Serial.println("[PMAIN] Initialisation page MAIN");

    Serial.println("[PMAIN] pMainInit() END");
    Serial.println("[PMAIN] ================================");
}

// ============================================================
// AFFICHAGE PAGE MAIN
// ============================================================

void pMainShow()
{
    Serial.println("[PMAIN] ================================");
    Serial.println("[PMAIN] pMainShow() START");

    Serial.println("[PMAIN] TEST 1 -> fond");

    tft.fillScreen(COLOR_BACKGROUND);

    Serial.println("[PMAIN] TEST 1 OK");

    Serial.println("[PMAIN] TEST 2 -> titre");

    tft.setTextColor(COLOR_TITLE_TEXT, COLOR_BACKGROUND);
    tft.setTextSize(2);
    tft.setCursor(20, 55);
    tft.print(HOME_TITLE);

    Serial.println("[PMAIN] TEST 2 OK");

    Serial.println("[PMAIN] TEST 3 -> bouton METEO");

    tft.fillRect(
        HOME_BUTTON_X,
        HOME_BUTTON_METEO_Y,
        HOME_BUTTON_WIDTH,
        HOME_BUTTON_HEIGHT,
        HOME_BUTTON_BG
    );

    tft.drawRect(
        HOME_BUTTON_X,
        HOME_BUTTON_METEO_Y,
        HOME_BUTTON_WIDTH,
        HOME_BUTTON_HEIGHT,
        HOME_BUTTON_BORDER
    );

    tft.setTextColor(
        HOME_BUTTON_TEXT,
        HOME_BUTTON_BG
    );

    tft.setTextSize(2);
    tft.setCursor(
        HOME_BUTTON_X + 55,
        HOME_BUTTON_METEO_Y + 18
    );

    tft.print("METEO");

    Serial.println("[PMAIN] TEST 3 OK");

    Serial.println("[PMAIN] TEST 4 -> bouton WIFI");

    tft.fillRect(
        HOME_BUTTON_X,
        HOME_BUTTON_WIFI_Y,
        HOME_BUTTON_WIDTH,
        HOME_BUTTON_HEIGHT,
        HOME_BUTTON_BG
    );

    tft.drawRect(
        HOME_BUTTON_X,
        HOME_BUTTON_WIFI_Y,
        HOME_BUTTON_WIDTH,
        HOME_BUTTON_HEIGHT,
        HOME_BUTTON_BORDER
    );

    tft.setTextColor(
        HOME_BUTTON_TEXT,
        HOME_BUTTON_BG
    );

    tft.setTextSize(2);
    tft.setCursor(
        HOME_BUTTON_X + 65,
        HOME_BUTTON_WIFI_Y + 18
    );

    tft.print("WIFI");

    Serial.println("[PMAIN] TEST 4 OK");

    Serial.println("[PMAIN] TEST 5 -> texte");

    tft.setTextColor(
        COLOR_TEXT,
        COLOR_BACKGROUND
    );

    tft.setTextSize(1);
    tft.setCursor(20, 220);
    tft.print("3x0c3t TFT BASE");

    Serial.println("[PMAIN] TEST 5 OK");

    Serial.println("[PMAIN] ================================");
    Serial.println("[PMAIN] pMainShow() END");
    Serial.println("[PMAIN] ================================");
}

// ============================================================
// UPDATE
// ============================================================

void pMainUpdate()
{
    Serial.println("[PMAIN] pMainUpdate()");
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

void pMainButtonOk()
{
    Serial.println("[PMAIN] BUTTON OK");

    Serial.println("[PMAIN] -> bouton OK MAIN");
}

void pMainButtonCancel()
{
    Serial.println("[PMAIN] BUTTON CANCEL");
}

void pMainButtonMenu()
{
    Serial.println("[PMAIN] BUTTON MENU");
}