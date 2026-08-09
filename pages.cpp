#include "pages.h"

#include "display.h"
#include "config.h"

#include "pMain.h"
#include "pMeteo.h"
#include "pSettings.h"
#include "pSystem.h"
#include "pWifi.h"


// ============================================================
// PAGE COURANTE
// ============================================================

static PageID currentPage = PAGE_MAIN;


// ============================================================
// INITIALISATION
// ============================================================

void pagesInit()
{
    currentPage = PAGE_MAIN;
}


// ============================================================
// PAGE COURANTE
// ============================================================

PageID pagesCurrent()
{
    return currentPage;
}


// ============================================================
// NOM PAGE
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
// AFFICHAGE PAGE
// ============================================================

void pagesShow(PageID page)
{
    if (page >= PAGE_COUNT)
    {
        page = PAGE_MAIN;
    }

    currentPage = page;

    switch (currentPage)
    {
        case PAGE_MAIN:
            pMainShow();
            break;

        case PAGE_METEO:
            pMeteoShow();
            break;

        case PAGE_SETTINGS:
            pSettingsShow();
            break;

        case PAGE_SYSTEM:
            pSystemShow();
            break;

        case PAGE_WIFI:
            pWifiShow();
            break;

        default:
            pMainShow();
            currentPage = PAGE_MAIN;
            break;
    }
}


// ============================================================
// UPDATE
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
// PAGE SUIVANTE
// ============================================================

void pagesNext()
{
    int next = (int)currentPage + 1;

    if (next >= PAGE_COUNT)
    {
        next = PAGE_MAIN;
    }

    pagesShow((PageID)next);
}


// ============================================================
// PAGE PRECEDENTE
// ============================================================

void pagesPrevious()
{
    int previous = (int)currentPage - 1;

    if (previous < 0)
    {
        previous = PAGE_COUNT - 1;
    }

    pagesShow((PageID)previous);
}


// ============================================================
// MAIN
// ============================================================

void pagesMain()
{
    pagesShow(PAGE_MAIN);
}


// ============================================================
// METEO
// ============================================================

void pagesMeteo()
{
    pagesShow(PAGE_METEO);
}


// ============================================================
// SETTINGS
// ============================================================

void pagesSettings()
{
    pagesShow(PAGE_SETTINGS);
}


// ============================================================
// SYSTEM
// ============================================================

void pagesSystem()
{
    pagesShow(PAGE_SYSTEM);
}


// ============================================================
// WIFI
// ============================================================

void pagesWifi()
{
    pagesShow(PAGE_WIFI);
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
            pagesMain();
            break;
    }
}