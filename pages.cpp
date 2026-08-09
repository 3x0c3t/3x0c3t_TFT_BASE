#include "pages.h"
#include "display.h"
#include "config.h"
#include "settings.h"

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

static const char* pageTitle(PageID page)
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
            return "INCONNU";
    }
}

// ============================================================
// AFFICHAGE D'UNE PAGE
// ============================================================

void pagesShow(PageID page)
{
    if (page >= PAGE_COUNT)
    {
        page = PAGE_HOME;
    }

    currentPage = page;

    // --------------------------------------------------------
    // Interface générale
    // --------------------------------------------------------

    drawInterface(pageTitle(page));

    // --------------------------------------------------------
    // Contenu spécifique
    // --------------------------------------------------------

    switch (page)
    {
        case PAGE_HOME:

            centerText(
                "ACCUEIL",
                CONTENT_Y + 50,
                2,
                COLOR_TEXT
            );

            break;

        case PAGE_METEO:

            centerText(
                "METEO",
                CONTENT_Y + 50,
                2,
                COLOR_TEXT
            );

            break;

        case PAGE_SETTINGS:

            settingsShow();

            break;

        case PAGE_SYSTEM:

            centerText(
                "SYSTEME",
                CONTENT_Y + 50,
                2,
                COLOR_TEXT
            );

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
    PageID next =
        static_cast<PageID>(
            static_cast<uint8_t>(currentPage) + 1
        );

    if (next >= PAGE_COUNT)
    {
        next = PAGE_HOME;
    }

    pagesShow(next);
}

// ============================================================
// PAGE PRECEDENTE
// ============================================================

void pagesPrevious()
{
    PageID previous;

    if (currentPage == PAGE_HOME)
    {
        previous =
            static_cast<PageID>(
                PAGE_COUNT - 1
            );
    }
    else
    {
        previous =
            static_cast<PageID>(
                static_cast<uint8_t>(currentPage) - 1
            );
    }

    pagesShow(previous);
}

// ============================================================
// RETOUR ACCUEIL
// ============================================================

void pagesGoHome()
{
    pagesShow(PAGE_HOME);
}

// ============================================================
// OUVRIR REGLAGES
// ============================================================

void pagesGoSettings()
{
    pagesShow(PAGE_SETTINGS);
}

// ============================================================
// PAGE COURANTE
// ============================================================

PageID pagesGetCurrent()
{
    return currentPage;
}