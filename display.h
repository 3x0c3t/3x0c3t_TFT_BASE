#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
#include <TFT_eSPI.h>
#include "config.h"

extern TFT_eSPI tft;

void displayInit();

void drawInterface(
    const String& title
);

void drawHeader();
void drawHeaderTime();
void drawStatusSquares();
void drawProgressBar();

void setProgress(
    uint8_t percent
);

void drawTitle(
    const String& title
);

void clearContent();

void drawFooter();

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

void setStatus(
    int index,
    uint16_t color
);

void clearStatus();

#endif
