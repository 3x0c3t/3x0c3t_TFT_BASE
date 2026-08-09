#include "settings.h"
#include "display.h"
#include "config.h"

// ============================================================
// ETAT
// ============================================================

static int settingsIndex = 0;

// ============================================================
// NOMBRE DE PARAMETRES
// ============================================================

static const int SETTINGS_COUNT = 4;

// ============================================================
// LIBELLES
// ============================================================

static const char* settingsLabels[SETTINGS_COUNT] =
{
    SETTINGS_ITEM_WIFI,
    SETTINGS_ITEM_DISPLAY,
    SETTINGS_ITEM_WEATHER,
    SETTINGS_ITEM_SYSTEM
};

// ============================================================
// INITIALISATION
// ============================================================

void settingsInit()
{
    settingsIndex = 0;
}

// ============================================================
// AFFICHAGE
// ============================================================

void settingsShow()
{
    // --------------------------------------------------------
    // Nettoyage contenu
    // --------------------------------------------------------

    tft.fillRect(
        0,
        CONTENT_Y,
        SCREEN_WIDTH,
        CONTENT_HEIGHT,
        COLOR_BACKGROUND
    );

    // --------------------------------------------------------
    // Titre
    // --------------------------------------------------------

    drawTitle(
        SETTINGS_TITLE
    );

    // --------------------------------------------------------
    // Liste
    // --------------------------------------------------------

    for (int i = 0; i < SETTINGS_COUNT; i++)
    {
        int y =
            SETTINGS_ITEM_START_Y +
            (i * SETTINGS_ITEM_HEIGHT);

        bool selected =
            (i == settingsIndex);

        // ----------------------------------------------------
        // Fond
        // ----------------------------------------------------

        if (selected)
        {
            tft.fillRect(
                SETTINGS_ITEM_X - 4,
                y - 2,
                SCREEN_WIDTH - SETTINGS_ITEM_X * 2 + 8,
                SETTINGS_ITEM_HEIGHT - 2,
                SETTINGS_SELECTED_COLOR
            );
        }
        else
        {
            tft.fillRect(
                SETTINGS_ITEM_X - 4,
                y - 2,
                SCREEN_WIDTH - SETTINGS_ITEM_X * 2 + 8,
                SETTINGS_ITEM_HEIGHT - 2,
                COLOR_BACKGROUND
            );
        }

        // ----------------------------------------------------
        // Ligne
        // ----------------------------------------------------

        tft.drawFastHLine(
            SETTINGS_ITEM_X,
            y + SETTINGS_ITEM_HEIGHT - 4,
            SCREEN_WIDTH - SETTINGS_ITEM_X * 2,
            SETTINGS_LINE_COLOR
        );

        // ----------------------------------------------------
        // Texte
        // ----------------------------------------------------

        tft.setTextFont(1);
        tft.setTextSize(1);
        tft.setTextDatum(ML_DATUM);

        if (selected)
        {
            tft.setTextColor(
                SETTINGS_SELECTED_TEXT_COLOR,
                SETTINGS_SELECTED_COLOR
            );

            tft.drawString(
                ">",
                SETTINGS_ITEM_X,
                y + SETTINGS_ITEM_HEIGHT / 2 - 2
            );

            tft.drawString(
                settingsLabels[i],
                SETTINGS_ITEM_X + 12,
                y + SETTINGS_ITEM_HEIGHT / 2 - 2
            );
        }
        else
        {
            tft.setTextColor(
                SETTINGS_TEXT_COLOR,
                COLOR_BACKGROUND
            );

            tft.drawString(
                settingsLabels[i],
                SETTINGS_ITEM_X + 12,
                y + SETTINGS_ITEM_HEIGHT / 2 - 2
            );
        }
    }
}

// ============================================================
// UPDATE
// ============================================================

void settingsUpdate()
{
    settingsShow();
}

// ============================================================
// HAUT
// ============================================================

void settingsButtonUp()
{
    settingsIndex--;

    if (settingsIndex < 0)
    {
        settingsIndex =
            SETTINGS_COUNT - 1;
    }

    settingsShow();
}

// ============================================================
// BAS
// ============================================================

void settingsButtonDown()
{
    settingsIndex++;

    if (settingsIndex >= SETTINGS_COUNT)
    {
        settingsIndex = 0;
    }

    settingsShow();
}

// ============================================================
// GAUCHE
// ============================================================

void settingsButtonLeft()
{
    // Réservé aux réglages de valeurs
}

// ============================================================
// DROITE
// ============================================================

void settingsButtonRight()
{
    // Réservé aux réglages de valeurs
}

// ============================================================
// MENU
// ============================================================

void settingsButtonMenu()
{
    // Retour menu principal
}

// ============================================================
// ANNULER
// ============================================================

void settingsButtonCancel()
{
    // Annulation
}

// ============================================================
// VALIDER
// ============================================================

void settingsButtonOk()
{
    switch (settingsIndex)
    {
        case 0:
            // WIFI
            break;

        case 1:
            // AFFICHAGE
            break;

        case 2:
            // METEO
            break;

        case 3:
            // SYSTEME
            break;
    }
}