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
    // Nettoyage du contenu
    // --------------------------------------------------------

    clearContent();

    // --------------------------------------------------------
    // Titre
    // --------------------------------------------------------

    drawTitle(
        SETTINGS_TITLE
    );

    // --------------------------------------------------------
    // Liste des réglages
    // --------------------------------------------------------

    for (int i = 0; i < SETTINGS_COUNT; i++)
    {
        const int y =
            SETTINGS_ITEM_START_Y +
            (i * SETTINGS_ITEM_HEIGHT);

        const bool selected =
            (i == settingsIndex);

        const int x =
            SETTINGS_ITEM_X - 4;

        const int width =
            SCREEN_WIDTH -
            (SETTINGS_ITEM_X * 2) +
            8;

        const int height =
            SETTINGS_ITEM_HEIGHT - 2;

        // ----------------------------------------------------
        // Fond
        // ----------------------------------------------------

        if (selected)
        {
            tft.fillRoundRect(
                x,
                y - 2,
                width,
                height,
                4,
                SETTINGS_SELECTED_COLOR
            );
        }
        else
        {
            tft.fillRect(
                x,
                y - 2,
                width,
                height,
                COLOR_BACKGROUND
            );
        }

        // ----------------------------------------------------
        // Ligne de séparation
        // ----------------------------------------------------

        if (!selected)
        {
            tft.drawFastHLine(
                SETTINGS_ITEM_X,
                y + SETTINGS_ITEM_HEIGHT - 4,
                SCREEN_WIDTH -
                SETTINGS_ITEM_X * 2,
                SETTINGS_LINE_COLOR
            );
        }

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

            // Indicateur de sélection
            tft.drawString(
                ">",
                SETTINGS_ITEM_X + 2,
                y + SETTINGS_ITEM_HEIGHT / 2 - 2
            );

            // Libellé
            tft.drawString(
                settingsLabels[i],
                SETTINGS_ITEM_X + 14,
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
                SETTINGS_ITEM_X + 14,
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
    // Réservé aux réglages de valeurs.
}

// ============================================================
// DROITE
// ============================================================

void settingsButtonRight()
{
    // Réservé aux réglages de valeurs.
}

// ============================================================
// MENU
// ============================================================

void settingsButtonMenu()
{
    // La navigation vers PAGE_MENU
    // est gérée par pages.cpp.
}

// ============================================================
// ANNULER
// ============================================================

void settingsButtonCancel()
{
    // Réservé à la navigation des sous-pages.
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

        default:
            break;
    }
}

// ============================================================
// INDEX ACTUEL
// ============================================================

int settingsGetIndex()
{
    return settingsIndex;
}