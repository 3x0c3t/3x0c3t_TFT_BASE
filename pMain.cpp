#include "pMain.h"
#include "config.h"
#include "display.h"

#include <Arduino.h>

// ============================================================
// INITIALISATION
// ============================================================

void pMainInit()
{
    Serial.println("[PMAIN] pMainInit() START");
    Serial.println("[PMAIN] pMainInit() END");
}

// ============================================================
// AFFICHAGE MAIN
// ============================================================

void pMainShow()
{
    Serial.println();
    Serial.println("[PMAIN] ================================");
    Serial.println("[PMAIN] pMainShow() START");
    Serial.println("[PMAIN] TEST TFT DIRECT");
    Serial.println("[PMAIN] ================================");

    // --------------------------------------------------------
    // TEST 1 : ECRAN NOIR
    // --------------------------------------------------------

    Serial.println("[PMAIN] TEST 1 -> fillScreen(BLACK)");

    tft.fillScreen(TFT_BLACK);

    Serial.println("[PMAIN] TEST 1 OK");

    delay(500);

    // --------------------------------------------------------
    // TEST 2 : RECTANGLE ROUGE
    // --------------------------------------------------------

    Serial.println("[PMAIN] TEST 2 -> rectangle ROUGE");

    tft.fillRect(
        0,
        0,
        240,
        80,
        TFT_RED
    );

    Serial.println("[PMAIN] TEST 2 OK");

    delay(500);

    // --------------------------------------------------------
    // TEST 3 : RECTANGLE VERT
    // --------------------------------------------------------

    Serial.println("[PMAIN] TEST 3 -> rectangle VERT");

    tft.fillRect(
        0,
        80,
        240,
        80,
        TFT_GREEN
    );

    Serial.println("[PMAIN] TEST 3 OK");

    delay(500);

    // --------------------------------------------------------
    // TEST 4 : RECTANGLE BLEU
    // --------------------------------------------------------

    Serial.println("[PMAIN] TEST 4 -> rectangle BLEU");

    tft.fillRect(
        0,
        160,
        240,
        80,
        TFT_BLUE
    );

    Serial.println("[PMAIN] TEST 4 OK");

    delay(500);

    // --------------------------------------------------------
    // TEST 5 : TEXTE
    // --------------------------------------------------------

    Serial.println("[PMAIN] TEST 5 -> texte");

    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.setTextDatum(MC_DATUM);

    tft.drawString(
        "3x0c3t TFT TEST",
        120,
        280
    );

    Serial.println("[PMAIN] TEST 5 OK");

    // --------------------------------------------------------
    // FIN
    // --------------------------------------------------------

    Serial.println("[PMAIN] ================================");
    Serial.println("[PMAIN] pMainShow() END");
    Serial.println("[PMAIN] ================================");
}

// ============================================================
// UPDATE
// ============================================================

void pMainUpdate()
{
    // Pas d'action pour le moment.
}