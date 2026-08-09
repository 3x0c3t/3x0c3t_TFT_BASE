#ifndef PAGES_H
#define PAGES_H

#include <Arduino.h>


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
// INITIALISATION
// ============================================================

void pagesInit();


// ============================================================
// AFFICHAGE
// ============================================================

void pagesShow(PageID page);


// ============================================================
// UPDATE
// ============================================================

void pagesUpdate();


// ============================================================
// ETAT
// ============================================================

PageID pagesCurrent();


// ============================================================
// NAVIGATION
// ============================================================

void pagesNext();
void pagesPrevious();

void pagesMain();
void pagesMeteo();
void pagesSettings();
void pagesSystem();
void pagesWifi();


// ============================================================
// BOUTONS
// ============================================================

void pagesButtonUp();
void pagesButtonDown();
void pagesButtonLeft();
void pagesButtonRight();
void pagesButtonOk();
void pagesButtonCancel();


// ============================================================
// NOM DE PAGE
// ============================================================

const char* pageName(PageID page);

#endif