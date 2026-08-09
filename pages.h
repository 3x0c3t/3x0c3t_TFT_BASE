#ifndef PAGES_H
#define PAGES_H

#include <Arduino.h>

// ============================================================
// IDENTIFIANTS DES PAGES
// ============================================================

enum PageID
{
PAGE_MAIN = 0,
PAGE_SETTINGS,
PAGE_WIFI,
PAGE_DISPLAY,
PAGE_WEATHER,
PAGE_SYSTEM
};

// ============================================================
// INITIALISATION
// ============================================================

void pagesInit();

// ============================================================
// PAGE ACTUELLE
// ============================================================

PageID pagesGetCurrent();

// ============================================================
// CHANGEMENT DE PAGE
// ============================================================

void pagesShow(PageID page);

// ============================================================
// MISE A JOUR
// ============================================================

void pagesUpdate();

// ============================================================
// BOUTONS
// ============================================================

void pagesButtonUp();
void pagesButtonDown();
void pagesButtonLeft();
void pagesButtonRight();

void pagesButtonMenu();
void pagesButtonCancel();
void pagesButtonOk();

#endif
