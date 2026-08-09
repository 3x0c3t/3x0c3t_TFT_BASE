#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
#include <TFT_eSPI.h>
#include "config.h"

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

void drawButton(
    int x,
    int y,
    int w,
    int h,
    const String& label,
    uint16_t color
);

// ============================================================
// TEXTE
// ============================================================

void centerText(
    const String& text,
    int y,
    uint8_t size,
    uint16_t color
);

// ============================================================
// GESTION DES STATUTS
// ============================================================

// Ajoute un nouveau statut dans le header.
// Exemple : addStatus("W", COLOR_ERROR);

bool addStatus(
    const String& label,
    uint16_t color
);

// Modifie la couleur d'un statut existant.
// Exemple : setStatus("W", COLOR_OK);

bool setStatus(
    const String& label,
    uint16_t color
);

// Supprime tous les statuts.

void clearStatus();

// Compatibilité avec l'ancienne API.
// Exemple : setStatus(0, COLOR_OK);

void setStatus(
    int index,
    uint16_t color
);

#endif