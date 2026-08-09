#include "pSystem.h"
#include "display.h"
#include "config.h"

// ============================================================
// PAGE SYSTEME
// ============================================================

void pSystemInit()
{
}

void pSystemShow()
{
    clearContent();

    drawTitle("SYSTEME");

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
        CONTENT_Y + 80
    );

    tft.setTextFont(1);

    tft.drawString(
        "Page en construction",
        SCREEN_WIDTH / 2,
        CONTENT_Y + 115
    );
}

void pSystemUpdate()
{
}

void pSystemButtonUp()
{
}

void pSystemButtonDown()
{
}

void pSystemButtonLeft()
{
}

void pSystemButtonRight()
{
}

void pSystemButtonOk()
{
}

void pSystemButtonCancel()
{
}

void pSystemButtonMenu()
{
}