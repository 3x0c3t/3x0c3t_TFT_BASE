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

void drawInterface(const String& title);

void drawHeader();
void drawHeaderTime();
void drawStatusSquares();

void drawProgressBar();
void setProgress(uint8_t percent);

void drawTitle(const String& title);

void clearContent();

void drawFooter();

// ============================================================
// ETATS
// ============================================================

void addStatus(
    const String& label,
    uint16_t color
);

void setStatus(
    const String& label,
    uint16_t color
);

void removeStatus(
    const String& label
);

void clearStatus();

// ============================================================
// OUTILS AFFICHAGE
// ============================================================

void drawButton(
    int x,
    int y,
    int w,
    int h,
    const String& label,
    uint16_t color
);

void centerText(
    const String& text,
    int y,
    uint8_t size,
    uint16_t color
);

#endif