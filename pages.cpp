#include "pages.h"
#include "display.h"
#include "settings.h"
#include "config.h"

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
// NOM DE PAGE
// ============================================================

static const char* pageName(PageID page)
{
    switch (page)
    {
        case PAGE_MAIN:
            return "MAIN";

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
        page = PAGE_MAIN;
    }

    currentPage = page;

    // ========================================================
    // INTERFACE FIXE
    // ========================================================

    drawHeader();

    clearContent();

    drawTitle(
        pageName(currentPage)
    );

    drawFooter();

    // ========================================================
    // MAIN
    // ========================================================

    if (page == PAGE_MAIN)
    {
        drawTitle(
            "-3x0c3t- B04RD"
        );

        // ----------------------------------------------------
        // METEO
        // ----------------------------------------------------

        drawButton(
            20,
            75,
            200,
            50,
            "METEO",
            COLOR_BUTTON_BG
        );

        // ----------------------------------------------------
        // WIFI
        // ----------------------------------------------------

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

    // ========================================================
    // METEO
    // ========================================================

    if (page == PAGE_METEO)
    {
        drawTitle(
            "METEO"
        );

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

    // ========================================================
    // SETTINGS
    // ========================================================

    if (page == PAGE_SETTINGS)
    {
        settingsShow();
        return;
    }

    // ========================================================
    // SYSTEME
    // ========================================================

    if (page == PAGE_SYSTEM)
    {
        drawTitle(
            "SYSTEME"
        );

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
        next = PAGE_MAIN;
    }

    pagesShow(
        (PageID)next
    );
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

    pagesShow(
        (PageID)previous
    );
}

// ============================================================
// PAGE COURANTE
// ============================================================

PageID pagesCurrent()
{
    return currentPage;
}

// ============================================================
// RETOUR MAIN
// ============================================================

void pagesHome()
{
    pagesShow(
        PAGE_MAIN
    );
}

// ============================================================
// OUVRIR SETTINGS
// ============================================================

void pagesSettings()
{
    pagesShow(
        PAGE_SETTINGS
    );
}

// ============================================================
// BOUTON MENU
// ============================================================

void pagesMenu()
{
    pagesShow(
        PAGE_SETTINGS
    );
}

// ============================================================
// BOUTON METEO
// ============================================================

void pagesButtonMeteo()
{
    pagesShow(
        PAGE_METEO
    );
}

// ============================================================
// BOUTON WIFI
// ============================================================

void pagesButtonWifi()
{
    pagesShow(
        PAGE_MAIN
    );
}