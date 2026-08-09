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
// INITIALISATION
// ============================================================

void pagesInit()
{
    currentPage = PAGE_MAIN;
}

// ============================================================
// AFFICHAGE D'UNE PAGE
// ============================================================

void pagesShow(PageID page)
{
    if (page >= PAGE_COUNT)
    {
        page = PAGE_MAIN;
    }

    currentPage = page;

    // ========================================================
    // RECONSTRUCTION COMPLETE DE L'INTERFACE
    //
    // drawInterface() restaure :
    // - fond
    // - première ligne du header
    // - barre de progression
    // - deuxième ligne du header
    // - titre
    // ========================================================

    switch (page)
    {
        case PAGE_MAIN:
            drawInterface("MAIN");
            pMainShow();
            break;

        case PAGE_METEO:
            drawInterface("METEO");
            pMeteoShow();
            break;

        case PAGE_SETTINGS:
            drawInterface("SETTINGS");
            pSettingsShow();
            break;

        case PAGE_SYSTEM:
            drawInterface("SYSTEM");
            pSystemShow();
            break;

        case PAGE_WIFI:
            drawInterface("WIFI");
            pWifiShow();
            break;

        default:
            currentPage = PAGE_MAIN;
            drawInterface("MAIN");
            pMainShow();
            break;
    }
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
            break;
    }
}

// ============================================================
// BOUTON UP
// ============================================================

void pagesButtonUp()
{
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
            break;
    }
}

// ============================================================
// BOUTON DOWN
// ============================================================

void pagesButtonDown()
{
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
            break;
    }
}

// ============================================================
// BOUTON LEFT
// ============================================================

void pagesButtonLeft()
{
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
            break;
    }
}

// ============================================================
// BOUTON RIGHT
// ============================================================

void pagesButtonRight()
{
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
            break;
    }
}

// ============================================================
// BOUTON OK
// ============================================================

void pagesButtonOk()
{
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
            break;
    }
}

// ============================================================
// BOUTON CANCEL
// ============================================================

void pagesButtonCancel()
{
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
    pagesShow(page);
}