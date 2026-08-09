#ifndef PAGES_H
#define PAGES_H

// ============================================================
// IDENTIFIANTS DES PAGES
// ============================================================

enum PageID
{
    PAGE_MAIN = 0,
    PAGE_METEO,
    PAGE_SETTINGS,
    PAGE_SYSTEM,
    PAGE_WIFI,

    PAGE_COUNT
};

// ============================================================
// PAGE COURANTE
// ============================================================

extern PageID currentPage;

// ============================================================
// INITIALISATION
// ============================================================

void pagesInit();

// ============================================================
// AFFICHAGE
// ============================================================

void pagesShow(PageID page);
void pagesUpdate();

// ============================================================
// NAVIGATION
// ============================================================

void pagesButtonUp();
void pagesButtonDown();
void pagesButtonLeft();
void pagesButtonRight();
void pagesButtonOk();
void pagesButtonCancel();

// ============================================================
// ACCES PAGE COURANTE
// ============================================================

PageID pagesGetCurrent();
void pagesSet(PageID page);

#endif