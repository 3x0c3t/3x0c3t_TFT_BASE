#include "pages.h"
#include "display.h"
#include "config.h"
#include "settings.h"

// ============================================================
// ETAT
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

PageID pagesGetCurrent()
{
    return currentPage;
}

// ============================================================
// AFFICHAGE
// ============================================================

void pagesShow(PageID page)
{
    if (page >= PAGE_COUNT)
    {
        page = PAGE_MAIN;
    }

    currentPage = page;

    // --------------------------------------------------------
    // Nettoyage contenu
    // --------------------------------------------------------

    tft.fillRect(
        0,
        CONTENT_Y,
        SCREEN_WIDTH,
        CONTENT_HEIGHT,
        COLOR_BACKGROUND
    );

    // --------------------------------------------------------
    // PAGE MAIN
    // --------------------------------------------------------

    if (currentPage == PAGE_MAIN)
    {
        drawTitle("-3x0c3t- B04RD");

        drawButton(
            20,
            75,
            200,
            50,
            "METEO",
            COLOR_BUTTON_BG
        );

        drawButton(
            20,
            140,
            200,
            50,
            "WiFi",
            COLOR_BUTTON_BG
        );

        return;
    }

    // --------------------------------------------------------
    // PAGE METEO
    // --------------------------------------------------------

    if (currentPage == PAGE_METEO)
    {
        drawTitle("METEO");

        tft.setTextFont(1);
        tft.setTextSize(1);
        tft.setTextDatum(MC_DATUM);

        tft.setTextColor(
            COLOR_TEXT,
            COLOR_BACKGROUND
        );

        tft.drawString(
            "METEO",
            SCREEN_WIDTH / 2,
            CONTENT_Y + 60
        );

        return;
    }

    // --------------------------------------------------------
    // PAGE SETTINGS
    // --------------------------------------------------------

    if (currentPage == PAGE_SETTINGS)
    {
        settingsShow();
        return;
    }

    // --------------------------------------------------------
    // PAGE SYSTEM
    // --------------------------------------------------------

    if (currentPage == PAGE_SYSTEM)
    {
        drawTitle("SYSTEME");

        tft.setTextFont(1);
        tft.setTextSize(1);
        tft.setTextDatum(MC_DATUM);

        tft.setTextColor(
            COLOR_TEXT,
            COLOR_BACKGROUND
        );

        tft.drawString(
            "SYSTEME",
            SCREEN_WIDTH / 2,
            CONTENT_Y + 60
        );

        return;
    }
}

// ============================================================
// NAVIGATION
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

void pagesGoMain()
{
    pagesShow(PAGE_MAIN);
}

// ============================================================

void pagesGoMeteo()
{
    pagesShow(PAGE_METEO);
}

// ============================================================

void pagesGoSettings()
{
    pagesShow(PAGE_SETTINGS);
}

// ============================================================

void pagesGoSystem()
{
    pagesShow(PAGE_SYSTEM);
}

// ============================================================
// BOUTON HAUT
// ============================================================

void pagesButtonUp()
{
    if (currentPage == PAGE_SETTINGS)
    {
        settingsButtonUp();
        return;
    }

    pagesPrevious();
}

// ============================================================
// BOUTON BAS
// ============================================================

void pagesButtonDown()
{
    if (currentPage == PAGE_SETTINGS)
    {
        settingsButtonDown();
        return;
    }

    pagesNext();
}

// ============================================================
// BOUTON GAUCHE
// ============================================================

void pagesButtonLeft()
{
    if (currentPage == PAGE_SETTINGS)
    {
        settingsButtonLeft();
    }
}

// ============================================================
// BOUTON DROITE
// ============================================================

void pagesButtonRight()
{
    if (currentPage == PAGE_SETTINGS)
    {
        settingsButtonRight();
    }
}

// ============================================================
// BOUTON MENU
// ============================================================

void pagesButtonMenu()
{
    if (currentPage == PAGE_MAIN)
    {
        pagesGoSettings();
        return;
    }

    pagesGoMain();
}

// ============================================================
// BOUTON OK
// ============================================================

void pagesButtonOk()
{
    if (currentPage == PAGE_SETTINGS)
    {
        settingsButtonOk();
        return;
    }
}

// ============================================================
// BOUTON CANCEL
// ============================================================

void pagesButtonCancel()
{
    if (currentPage == PAGE_SETTINGS)
    {
        settingsButtonCancel();
        pagesGoMain();
        return;
    }

    pagesGoMain();
}