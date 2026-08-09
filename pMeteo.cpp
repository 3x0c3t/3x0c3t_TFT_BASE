#include "pMeteo.h"
#include "display.h"
#include "config.h"

// ============================================================
// PAGE METEO
// ============================================================

void pMeteoInit()
{
    Serial.println("[PMETEO] ================================");
    Serial.println("[PMETEO] pMeteoInit() START");

    Serial.println("[PMETEO] Initialisation page METEO");

    Serial.println("[PMETEO] pMeteoInit() END");
    Serial.println("[PMETEO] ================================");
}

// ============================================================
// AFFICHAGE
// ============================================================

void pMeteoShow()
{
    Serial.println("[PMETEO] ================================");
    Serial.println("[PMETEO] pMeteoShow() START");

    // --------------------------------------------------------
    // NETTOYAGE DU CONTENU
    // --------------------------------------------------------

    Serial.println("[PMETEO] TEST 1 -> clearContent()");

    clearContent();

    Serial.println("[PMETEO] TEST 1 OK");

    // --------------------------------------------------------
    // TITRE
    // --------------------------------------------------------

    Serial.println("[PMETEO] TEST 2 -> titre");

    drawTitle("METEO");

    Serial.println("[PMETEO] TEST 2 OK");

    // --------------------------------------------------------
    // TEMPERATURE
    // --------------------------------------------------------

    Serial.println("[PMETEO] TEST 3 -> temperature");

    tft.setTextDatum(MC_DATUM);
    tft.setTextFont(2);
    tft.setTextSize(1);

    tft.setTextColor(
        COLOR_TEXT,
        COLOR_BACKGROUND
    );

    tft.drawString(
        "TEMPERATURE",
        SCREEN_WIDTH / 2,
        CONTENT_Y + 55
    );

    tft.setTextFont(4);

    tft.drawString(
        "--.- C",
        SCREEN_WIDTH / 2,
        CONTENT_Y + 85
    );

    Serial.println("[PMETEO] TEST 3 OK");

    // --------------------------------------------------------
    // HUMIDITE
    // --------------------------------------------------------

    Serial.println("[PMETEO] TEST 4 -> humidite");

    tft.setTextFont(2);

    tft.drawString(
        "HUMIDITE",
        SCREEN_WIDTH / 2,
        CONTENT_Y + 130
    );

    tft.setTextFont(4);

    tft.drawString(
        "-- %",
        SCREEN_WIDTH / 2,
        CONTENT_Y + 160
    );

    Serial.println("[PMETEO] TEST 4 OK");

    // --------------------------------------------------------
    // CONDITIONS
    // --------------------------------------------------------

    Serial.println("[PMETEO] TEST 5 -> conditions");

    tft.setTextFont(2);

    tft.drawString(
        "CONDITIONS",
        SCREEN_WIDTH / 2,
        CONTENT_Y + 195
    );

    tft.setTextFont(2);

    tft.drawString(
        "---",
        SCREEN_WIDTH / 2,
        CONTENT_Y + 215
    );

    Serial.println("[PMETEO] TEST 5 OK");

    // --------------------------------------------------------
    // FIN
    // --------------------------------------------------------

    tft.setTextDatum(TL_DATUM);
    tft.setTextFont(1);
    tft.setTextSize(1);

    Serial.println("[PMETEO] ================================");
    Serial.println("[PMETEO] pMeteoShow() END");
    Serial.println("[PMETEO] ================================");
}

// ============================================================
// UPDATE
// ============================================================

void pMeteoUpdate()
{
    // Rien de dynamique pour le moment.
}

// ============================================================
// BOUTONS
// ============================================================

void pMeteoButtonUp()
{
    Serial.println("[PMETEO] BUTTON UP");
}

void pMeteoButtonDown()
{
    Serial.println("[PMETEO] BUTTON DOWN");
}

void pMeteoButtonLeft()
{
    Serial.println("[PMETEO] BUTTON LEFT");
}

void pMeteoButtonRight()
{
    Serial.println("[PMETEO] BUTTON RIGHT");
}

void pMeteoButtonOk()
{
    Serial.println("[PMETEO] BUTTON OK");
}

void pMeteoButtonCancel()
{
    Serial.println("[PMETEO] BUTTON CANCEL");
}

void pMeteoButtonMenu()
{
    Serial.println("[PMETEO] BUTTON MENU");
}