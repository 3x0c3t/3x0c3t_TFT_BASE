#ifndef PAGES_H
#define PAGES_H

#include <Arduino.h>

// ============================================================
// PAGES
// ============================================================

enum PageID
{
    PAGE_MAIN = 0,
    PAGE_METEO,
    PAGE_SETTINGS,
    PAGE_SYSTEM,
    PAGE_COUNT
};

// ============================================================
// INITIALISATION
// ============================================================

void pagesInit();

// ============================================================
// AFFICHAGE
// ============================================================

void pagesShow(PageID page);

// ============================================================
// PAGE COURANTE
// ============================================================

PageID pagesGetCurrent();

// ============================================================
// NAVIGATION
// ============================================================

void pagesNext();
void pagesPrevious();

void pagesGoMain();
void pagesGoMeteo();
void pagesGoSettings();
void pagesGoSystem();

// ============================================================
// BOUTONS
// ============================================================

void pagesButtonUp();
void pagesButtonDown();
void pagesButtonLeft();
void pagesButtonRight();
void pagesButtonMenu();
void pagesButtonOk();
void pagesButtonCancel();

#endif