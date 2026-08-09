#include "pMeteo.h"
#include "display.h"
#include "config.h"

// ============================================================
// PAGE METEO
// ============================================================

void pMeteoInit()
{
}

void pMeteoShow()
{
    clearContent();

    drawTitle("METEO");

    tft.setTextFont(2);
    tft.setTextSize(1);
    tft.setTextDatum(MC_DATUM);

    tft.setTextColor(
        COLOR_TEXT,
        COLOR_BACKGROUND
    );

    tft.drawString(
        "METEO",
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

void pMeteoUpdate()
{
}

void pMeteoButtonUp()
{
}

void pMeteoButtonDown()
{
}

void pMeteoButtonLeft()
{
}

void pMeteoButtonRight()
{
}

void pMeteoButtonOk()
{
}

void pMeteoButtonCancel()
{
}

void pMeteoButtonMenu()
{
}