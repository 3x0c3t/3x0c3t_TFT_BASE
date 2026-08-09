#include "splash.h"

#include <Arduino.h>
#include <TFT_eSPI.h>

#include "config.h"

// ============================================================
// TFT EXTERNE
// ============================================================

extern TFT_eSPI tft;


// ============================================================
// SPLASH
// ============================================================

void splashInit()
{
    // Rien à initialiser pour le moment.
}


// ============================================================
// AFFICHAGE SPLASH
// ============================================================

void splashShow()
{
    unsigned long startTime =
        millis();

    // ========================================================
    // ECRAN NOIR
    // ========================================================

    tft.fillScreen(
        SPLASH_BACKGROUND
    );


    // ========================================================
    // TITRE PRINCIPAL
    // ========================================================

    tft.setTextFont(2);

    tft.setTextSize(1);

    tft.setTextDatum(
        MC_DATUM
    );

    tft.setTextColor(
        SPLASH_TITLE_COLOR,
        SPLASH_BACKGROUND
    );

    tft.drawString(
        SPLASH_TITLE,
        SCREEN_WIDTH / 2,
        SPLASH_TITLE_Y
    );


    // ========================================================
    // SOUS-TITRE
    // ========================================================

    tft.setTextFont(1);

    tft.setTextSize(1);

    tft.setTextColor(
        SPLASH_SUBTITLE_COLOR,
        SPLASH_BACKGROUND
    );

    tft.drawString(
        SPLASH_SUBTITLE,
        SCREEN_WIDTH / 2,
        SPLASH_SUBTITLE_Y
    );


    // ========================================================
    // VERSION
    // ========================================================

    tft.setTextColor(
        SPLASH_VERSION_COLOR,
        SPLASH_BACKGROUND
    );

    tft.drawString(
        SPLASH_VERSION,
        SCREEN_WIDTH / 2,
        SPLASH_VERSION_Y
    );


    // ========================================================
    // BARRE DE PROGRESSION
    // ========================================================

    const int barX =
        SPLASH_PROGRESS_X;

    const int barY =
        SPLASH_PROGRESS_Y;

    const int barWidth =
        SPLASH_PROGRESS_WIDTH;

    const int barHeight =
        SPLASH_PROGRESS_HEIGHT;


    tft.drawRect(
        barX,
        barY,
        barWidth,
        barHeight,
        SPLASH_PROGRESS_BORDER
    );


    // ========================================================
    // PROGRESSION
    // ========================================================

    const unsigned long duration =
        SPLASH_DURATION;

    while (
        millis() - startTime <
        duration
    )
    {
        unsigned long elapsed =
            millis() - startTime;

        int percent =
            map(
                elapsed,
                0,
                duration,
                0,
                100
            );

        if (percent > 100)
        {
            percent = 100;
        }

        int fillWidth =
            map(
                percent,
                0,
                100,
                0,
                barWidth - 2
            );

        if (fillWidth > 0)
        {
            tft.fillRect(
                barX + 1,
                barY + 1,
                fillWidth,
                barHeight - 2,
                SPLASH_PROGRESS_COLOR
            );
        }

        delay(
            SPLASH_UPDATE_INTERVAL
        );
    }


    // ========================================================
    // FIN
    // ========================================================

    splashHide();
}


// ============================================================
// MASQUAGE SPLASH
// ============================================================

void splashHide()
{
    tft.fillScreen(
        COLOR_BACKGROUND
    );
}