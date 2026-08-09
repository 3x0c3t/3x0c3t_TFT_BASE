#include "pMain.h"
#include "display.h"
#include "config.h"

// ============================================================
// PAGE MAIN
// ============================================================

void pMainInit()
{
    Serial.println("[PMAIN] pMainInit() START");
    Serial.println("[PMAIN] Initialisation MAIN");
    Serial.println("[PMAIN] pMainInit() END");
}

// ============================================================
// AFFICHAGE
// ============================================================

void pMainShow()
{
    Serial.println("[PMAIN] ================================");
    Serial.println("[PMAIN] pMainShow() START");

    // --------------------------------------------------------
    // CONTENU
    // --------------------------------------------------------

    Serial.println("[PMAIN] clearContent()");

    clearContent();

    Serial.println("[PMAIN] clearContent() OK");

    // --------------------------------------------------------
    // TITRE
    // --------------------------------------------------------

    Serial.println("[PMAIN] drawTitle()");

    drawTitle(HOME_TITLE);

    Serial.println("[PMAIN] drawTitle() OK");

    // --------------------------------------------------------
    // BOUTON METEO
    // --------------------------------------------------------

    Serial.println("[PMAIN] drawButton METEO");

    drawButton(
        HOME_BUTTON_X,
        HOME_BUTTON_METEO_Y,
        HOME_BUTTON_WIDTH,
        HOME_BUTTON_HEIGHT,
        "METEO",
        HOME_BUTTON_BG
    );

    Serial.println("[PMAIN] bouton METEO OK");

    // --------------------------------------------------------
    // BOUTON WIFI
    // --------------------------------------------------------

    Serial.println("[PMAIN] drawButton WIFI");

    drawButton(
        HOME_BUTTON_X,
        HOME_BUTTON_WIFI_Y,
        HOME_BUTTON_WIDTH,
        HOME_BUTTON_HEIGHT,
        "WIFI",
        HOME_BUTTON_BG
    );

    Serial.println("[PMAIN] bouton WIFI OK");

    Serial.println("[PMAIN] ================================");
    Serial.println("[PMAIN] pMainShow() END");
    Serial.println("[PMAIN] ================================");
}

// ============================================================
// UPDATE
// ============================================================

void pMainUpdate()
{
    // Pas de mise à jour dynamique pour le moment.
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
}

void pMainButtonCancel()
{
    Serial.println("[PMAIN] BUTTON CANCEL");
}

void pMainButtonMenu()
{
    Serial.println("[PMAIN] BUTTON MENU");
}