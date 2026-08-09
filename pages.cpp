#include "pages.h"
#include "config.h"
#include "display.h"

#include "pMain.h"
#include "pMeteo.h"
#include "pSettings.h"
#include "pSystem.h"
#include "pWifi.h"

#include <Arduino.h>
#include <TFT_eSPI.h>

// ============================================================
// PAGE COURANTE
// ============================================================

PageID currentPage = PAGE_MAIN;

// ============================================================
// NOM DE PAGE POUR LES LOGS
// ============================================================

const char* pageName(PageID page)
{
    switch (page)
    {
        case PAGE_MAIN:
            return "MAIN";

        case PAGE_METEO:
            return "METEO";

        case PAGE_SETTINGS:
            return "SETTINGS";

        case PAGE_SYSTEM:
            return "SYSTEM";

        case PAGE_WIFI:
            return "WIFI";

        default:
            return "UNKNOWN";
    }
}

// ============================================================
// INITIALISATION
// ============================================================

void pagesInit()
{
    Serial.println("[PAGE] pagesInit() START");

    currentPage = PAGE_MAIN;

    Serial.print("[PAGE] currentPage = ");
    Serial.println(pageName(currentPage));

    Serial.println("[PAGE] pagesInit() END");
}

// ============================================================
// AFFICHAGE D'UNE PAGE
// ============================================================

void pagesShow(PageID page)
{
    Serial.println();
    Serial.println("[PAGE] ================================");
    Serial.println("[PAGE] pagesShow() START");

    Serial.print("[PAGE] requested = ");
    Serial.println(pageName(page));

    // --------------------------------------------------------
    // VERIFICATION
    // --------------------------------------------------------

    if (page >= PAGE_COUNT)
    {
        Serial.println("[PAGE] page invalide");
        Serial.println("[PAGE] retour vers MAIN");

        page = PAGE_MAIN;
    }

    // --------------------------------------------------------
    // PAGE COURANTE
    // --------------------------------------------------------

    currentPage = page;

    Serial.print("[PAGE] currentPage = ");
    Serial.println(pageName(currentPage));

    // ========================================================
    // RECONSTRUCTION COMPLETE DE L'INTERFACE
    // ========================================================

    switch (page)
    {
        // ----------------------------------------------------
        // MAIN
        // ----------------------------------------------------

        case PAGE_MAIN:

            Serial.println("[PAGE] -> MAIN");
            Serial.println("[PAGE] drawInterface(\"MAIN\")");

            drawInterface("MAIN");

            Serial.println("[PAGE] pMainShow()");

            pMainShow();

            Serial.println("[PAGE] MAIN affichee");

            break;

        // ----------------------------------------------------
        // METEO
        // ----------------------------------------------------

        case PAGE_METEO:

            Serial.println("[PAGE] -> METEO");
            Serial.println("[PAGE] drawInterface(\"METEO\")");

            drawInterface("METEO");

            Serial.println("[PAGE] pMeteoShow()");

            pMeteoShow();

            Serial.println("[PAGE] METEO affichee");

            break;

        // ----------------------------------------------------
        // SETTINGS
        // ----------------------------------------------------

        case PAGE_SETTINGS:

            Serial.println("[PAGE] -> SETTINGS");
            Serial.println("[PAGE] drawInterface(\"SETTINGS\")");

            drawInterface("SETTINGS");

            Serial.println("[PAGE] pSettingsShow()");

            pSettingsShow();

            Serial.println("[PAGE] SETTINGS affichee");

            break;

        // ----------------------------------------------------
        // SYSTEM
        // ----------------------------------------------------

        case PAGE_SYSTEM:

            Serial.println("[PAGE] -> SYSTEM");
            Serial.println("[PAGE] drawInterface(\"SYSTEM\")");

            drawInterface("SYSTEM");

            Serial.println("[PAGE] pSystemShow()");

            pSystemShow();

            Serial.println("[PAGE] SYSTEM affichee");

            break;

        // ----------------------------------------------------
        // WIFI
        // ----------------------------------------------------

        case PAGE_WIFI:

            Serial.println("[PAGE] -> WIFI");
            Serial.println("[PAGE] drawInterface(\"WIFI\")");

            drawInterface("WIFI");

            Serial.println("[PAGE] pWifiShow()");

            pWifiShow();

            Serial.println("[PAGE] WIFI affichee");

            break;

        // ----------------------------------------------------
        // DEFAULT
        // ----------------------------------------------------

        default:

            Serial.println("[PAGE] DEFAULT");
            Serial.println("[PAGE] retour MAIN");

            currentPage = PAGE_MAIN;

            drawInterface("MAIN");
            pMainShow();

            break;
    }

    Serial.println("[PAGE] pagesShow() END");
    Serial.println("[PAGE] ================================");
}

// ============================================================
// MISE A JOUR DE LA PAGE COURANTE
// ============================================================

void pagesUpdate()
{
    switch (currentPage)
    {
        case PAGE_MAIN:

            pMainUpdate();

            break;

        case PAGE_METEO:

            pMeteoUpdate();

            break;

        case PAGE_SETTINGS:

            pSettingsUpdate();

            break;

        case PAGE_SYSTEM:

            pSystemUpdate();

            break;

        case PAGE_WIFI:

            pWifiUpdate();

            break;

        default:

            Serial.println("[PAGE] pagesUpdate() : page inconnue");

            break;
    }
}

// ============================================================
// BOUTON UP
// ============================================================

void pagesButtonUp()
{
    Serial.print("[BUTTON] UP -> ");
    Serial.println(pageName(currentPage));

    switch (currentPage)
    {
        case PAGE_MAIN:
            pMainButtonUp();
            break;

        case PAGE_METEO:
            pMeteoButtonUp();
            break;

        case PAGE_SETTINGS:
            pSettingsButtonUp();
            break;

        case PAGE_SYSTEM:
            pSystemButtonUp();
            break;

        case PAGE_WIFI:
            pWifiButtonUp();
            break;

        default:
            Serial.println("[BUTTON] UP : page inconnue");
            break;
    }
}

// ============================================================
// BOUTON DOWN
// ============================================================

void pagesButtonDown()
{
    Serial.print("[BUTTON] DOWN -> ");
    Serial.println(pageName(currentPage));

    switch (currentPage)
    {
        case PAGE_MAIN:
            pMainButtonDown();
            break;

        case PAGE_METEO:
            pMeteoButtonDown();
            break;

        case PAGE_SETTINGS:
            pSettingsButtonDown();
            break;

        case PAGE_SYSTEM:
            pSystemButtonDown();
            break;

        case PAGE_WIFI:
            pWifiButtonDown();
            break;

        default:
            Serial.println("[BUTTON] DOWN : page inconnue");
            break;
    }
}

// ============================================================
// BOUTON LEFT
// ============================================================

void pagesButtonLeft()
{
    Serial.print("[BUTTON] LEFT -> ");
    Serial.println(pageName(currentPage));

    switch (currentPage)
    {
        case PAGE_MAIN:
            pMainButtonLeft();
            break;

        case PAGE_METEO:
            pMeteoButtonLeft();
            break;

        case PAGE_SETTINGS:
            pSettingsButtonLeft();
            break;

        case PAGE_SYSTEM:
            pSystemButtonLeft();
            break;

        case PAGE_WIFI:
            pWifiButtonLeft();
            break;

        default:
            Serial.println("[BUTTON] LEFT : page inconnue");
            break;
    }
}

// ============================================================
// BOUTON RIGHT
// ============================================================

void pagesButtonRight()
{
    Serial.print("[BUTTON] RIGHT -> ");
    Serial.println(pageName(currentPage));

    switch (currentPage)
    {
        case PAGE_MAIN:
            pMainButtonRight();
            break;

        case PAGE_METEO:
            pMeteoButtonRight();
            break;

        case PAGE_SETTINGS:
            pSettingsButtonRight();
            break;

        case PAGE_SYSTEM:
            pSystemButtonRight();
            break;

        case PAGE_WIFI:
            pWifiButtonRight();
            break;

        default:
            Serial.println("[BUTTON] RIGHT : page inconnue");
            break;
    }
}

// ============================================================
// BOUTON OK
// ============================================================

void pagesButtonOk()
{
    Serial.print("[BUTTON] OK -> ");
    Serial.println(pageName(currentPage));

    switch (currentPage)
    {
        case PAGE_MAIN:
            pMainButtonOk();
            break;

        case PAGE_METEO:
            pMeteoButtonOk();
            break;

        case PAGE_SETTINGS:
            pSettingsButtonOk();
            break;

        case PAGE_SYSTEM:
            pSystemButtonOk();
            break;

        case PAGE_WIFI:
            pWifiButtonOk();
            break;

        default:
            Serial.println("[BUTTON] OK : page inconnue");
            break;
    }
}

// ============================================================
// BOUTON CANCEL
// ============================================================

void pagesButtonCancel()
{
    Serial.print("[BUTTON] CANCEL -> ");
    Serial.println(pageName(currentPage));

    switch (currentPage)
    {
        case PAGE_MAIN:
            pMainButtonCancel();
            break;

        case PAGE_METEO:
            pMeteoButtonCancel();
            break;

        case PAGE_SETTINGS:
            pSettingsButtonCancel();
            break;

        case PAGE_SYSTEM:
            pSystemButtonCancel();
            break;

        case PAGE_WIFI:
            pWifiButtonCancel();
            break;

        default:
            Serial.println("[BUTTON] CANCEL : page inconnue");
            break;
    }
}

// ============================================================
// PAGE COURANTE
// ============================================================

PageID pagesGetCurrent()
{
    return currentPage;
}

// ============================================================
// CHANGEMENT DE PAGE
// ============================================================

void pagesSet(PageID page)
{
    Serial.print("[PAGE] pagesSet() -> ");
    Serial.println(pageName(page));

    pagesShow(page);
}