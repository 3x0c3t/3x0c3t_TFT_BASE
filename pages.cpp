#include "pages.h"
#include "display.h"
#include "settings.h"
#include "config.h"

// ============================================================
// PAGE COURANTE
// ============================================================

static PageID currentPage = PAGE_HOME;

// ============================================================
// INITIALISATION
// ============================================================

void pagesInit()
{
currentPage = PAGE_HOME;
}

// ============================================================
// NOM DE PAGE
// ============================================================

static const char* pageName(PageID page)
{
switch (page)
{
case PAGE_HOME:
return "ACCUEIL";

    case PAGE_METEO:
        return "METEO";

    case PAGE_SETTINGS:
        return "REGLAGES";

    case PAGE_SYSTEM:
        return "SYSTEME";

    default:
        return "";
}

}

// ============================================================
// AFFICHAGE PAGE
// ============================================================

void pagesShow(PageID page)
{
if (page >= PAGE_COUNT)
{
page = PAGE_HOME;
}

currentPage = page;

// --------------------------------------------------------
// Nettoyage du contenu
// --------------------------------------------------------

tft.fillRect(
    0,
    CONTENT_Y,
    SCREEN_WIDTH,
    CONTENT_HEIGHT,
    COLOR_BACKGROUND
);

// --------------------------------------------------------
// ACCUEIL
// --------------------------------------------------------

if (page == PAGE_HOME)
{
    drawTitle(HOME_TITLE);

    // ----------------------------------------------------
    // Bouton METEO
    // ----------------------------------------------------

    drawButton(
        HOME_BUTTON_X,
        HOME_BUTTON_METEO_Y,
        HOME_BUTTON_WIDTH,
        HOME_BUTTON_HEIGHT,
        "METEO",
        HOME_BUTTON_BG
    );

    // ----------------------------------------------------
    // Bouton WIFI
    // ----------------------------------------------------

    drawButton(
        HOME_BUTTON_X,
        HOME_BUTTON_WIFI_Y,
        HOME_BUTTON_WIDTH,
        HOME_BUTTON_HEIGHT,
        "WiFi",
        HOME_BUTTON_BG
    );

    return;
}

// --------------------------------------------------------
// METEO
// --------------------------------------------------------

if (page == PAGE_METEO)
{
    drawTitle("METEO");

    tft.setTextFont(2);
    tft.setTextSize(1);
    tft.setTextDatum(MC_DATUM);
    tft.setTextColor(
        COLOR_TEXT,
        COLOR_BACKGROUND
    );

    tft.drawString(
        "METEO",
        SCREEN_WIDTH / 2,
        CONTENT_Y + 50
    );

    return;
}

// --------------------------------------------------------
// SETTINGS
// --------------------------------------------------------

if (page == PAGE_SETTINGS)
{
    settingsShow();
    return;
}

// --------------------------------------------------------
// SYSTEME
// --------------------------------------------------------

if (page == PAGE_SYSTEM)
{
    drawTitle("SYSTEME");

    tft.setTextFont(2);
    tft.setTextSize(1);
    tft.setTextDatum(MC_DATUM);
    tft.setTextColor(
        COLOR_TEXT,
        COLOR_BACKGROUND
    );

    tft.drawString(
        "SYSTEME",
        SCREEN_WIDTH / 2,
        CONTENT_Y + 50
    );

    return;
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
    next = PAGE_HOME;
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
// PAGE COURANTE
// ============================================================

PageID pagesCurrent()
{
return currentPage;
}

// ============================================================
// RETOUR ACCUEIL
// ============================================================

void pagesHome()
{
pagesShow(PAGE_HOME);
}

// ============================================================
// OUVRIR SETTINGS
// ============================================================

void pagesSettings()
{
pagesShow(PAGE_SETTINGS);
}

// ============================================================
// BOUTON MENU
// ============================================================

void pagesMenu()
{
pagesShow(PAGE_SETTINGS);
}

// ============================================================
// GESTION BOUTONS ACCUEIL
// ============================================================

void pagesButtonMeteo()
{
pagesShow(PAGE_METEO);
}

// ============================================================
// GESTION BOUTON WIFI
// ============================================================

void pagesButtonWifi()
{
// Pour l'instant, on reste sur l'accueil.
// La page WIFI sera ajoutée ensuite.
pagesShow(PAGE_HOME);
}
