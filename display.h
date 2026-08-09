#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
#include <TFT_eSPI.h>
#include "config.h"

// ============================================================
// TFT
// ============================================================

extern TFT_eSPI tft;

// ============================================================
// INITIALISATION
// ============================================================

void displayInit();

// ============================================================
// INTERFACE
// ============================================================

void drawInterface(
    const String& title
);

// ============================================================
// HEADER
// ============================================================

void drawHeader();

void drawHeaderTime();

void drawStatusSquares();

void drawProgressBar();

// ============================================================
// INDICATEURS
// ============================================================
//
// Ajouter un indicateur :
//
// addStatus("W", COLOR_OK);
//
// Supprimer un indicateur :
//
// removeStatus("W");
//
// Modifier sa couleur :
//
// setStatus("W", COLOR_ERROR);
//
// Activer / désactiver :
//
// enableStatus("W");
// disableStatus("W");
//
// ============================================================

bool addStatus(
    const String& label,
    uint16_t color
);

bool removeStatus(
    const String& label
);

bool setStatus(
    const String& label,
    uint16_t color
);

bool enableStatus(
    const String& label
);

bool disableStatus(
    const String& label
);

void clearStatus();

// ============================================================
// PROGRESSION
// ============================================================

void setProgress(
    uint8_t percent
);

// ============================================================
// TITRE
// ============================================================

void drawTitle(
    const String& title
);

// ============================================================
// CONTENU
// ============================================================

void clearContent();

// ============================================================
// FOOTER
// ============================================================

void drawFooter();

// ============================================================
// BOUTON
// ============================================================

void drawButton(
    int x,
    int y,
    int w,
    int h,
    const String& label,
    uint16_t color
);

// ============================================================
// TEXTE CENTRE
// ============================================================

void centerText(
    const String& text,
    int y,
    uint8_t size,
    uint16_t color
);

#endif