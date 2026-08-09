#include "splash.h"

#include <Arduino.h>

#include "config.h"
#include "display.h"

// ============================================================
// SPLASH SCREEN
// ============================================================

void splashShow()
{
    unsigned long startTime = millis();
    unsigned long lastUpdate = 0;

    int progress = 0;

    // ========================================================
    // FOND
    // ========================================================

    tft.fillScreen(
        SPLASH_BACKGROUND
    );

    // ========================================================
    // TITRE
    // ========================================================

    tft.setTextFont(2);
    tft.setTextSize(1);

    tft.setTextDatum(
        TC_DATUM
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
    // CADRE DE PROGRESSION
    // ========================================================

    tft.drawRect(
        SPLASH_PROGRESS_X - 1,
        SPLASH_PROGRESS_Y - 1,
        SPLASH_PROGRESS_WIDTH + 2,
        SPLASH_PROGRESS_HEIGHT + 2,
        SPLASH_PROGRESS_BORDER
    );

    // ========================================================
    // ANIMATION
    // ========================================================

    while (progress < 100)
    {
        unsigned long now = millis();

        unsigned long elapsed =
            now - startTime;

        if (elapsed >= SPLASH_DURATION)
        {
            progress = 100;
        }
        else
        {
            progress =
                (elapsed * 100UL) /
                SPLASH_DURATION;
        }

        // Mise à jour limitée
        // pour éviter de redessiner inutilement
        if (
            now - lastUpdate >=
            SPLASH_UPDATE_INTERVAL
        )
        {
            lastUpdate = now;

            int progressWidth =
                (
                    SPLASH_PROGRESS_WIDTH *
                    progress
                ) / 100;

            // Effacement de la barre
            tft.fillRect(
                SPLASH_PROGRESS_X,
                SPLASH_PROGRESS_Y,
                SPLASH_PROGRESS_WIDTH,
                SPLASH_PROGRESS_HEIGHT,
                SPLASH_BACKGROUND
            );

            // Progression
            if (progressWidth > 0)
            {
                tft.fillRect(
                    SPLASH_PROGRESS_X,
                    SPLASH_PROGRESS_Y,
                    progressWidth,
                    SPLASH_PROGRESS_HEIGHT,
                    SPLASH_PROGRESS_COLOR
                );
            }
        }

        yield();
    }

    // ========================================================
    // PROGRESSION 100 %
    // ========================================================

    tft.fillRect(
        SPLASH_PROGRESS_X,
        SPLASH_PROGRESS_Y,
        SPLASH_PROGRESS_WIDTH,
        SPLASH_PROGRESS_HEIGHT,
        SPLASH_PROGRESS_COLOR
    );

    delay(50);

    // ========================================================
    // FIN DU SPLASH
    // ========================================================

    tft.fillScreen(
        COLOR_BACKGROUND
    );
}