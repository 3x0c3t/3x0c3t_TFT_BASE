#include "pSettings.h"
#include "display.h"
#include "config.h"

// ============================================================
// ETAT
// ============================================================

static int settingsIndex = 0;

// ============================================================
// ELEMENTS
// ============================================================

static const char* settingsItems[] =
{
    "WIFI",
    "AFFICHAGE",
    "METEO",
    "SYSTEME"
};

static const int SETTINGS_COUNT =
    sizeof(settingsItems) / sizeof(settingsItems[0]);

// ============================================================
// INITIALISATION
// ============================================================

void pSettingsInit()
{
    settingsIndex = 0;
}

// ============================================================
// AFFICHAGE
// ============================================================

void pSettingsShow()
{
    clearContent();

    drawTitle("REGLAGES");

    for (int i = 0; i < SETTINGS_COUNT; i++)
    {
        int y =
            SETTINGS_ITEM_START_Y +
            (i * SETTINGS_ITEM_HEIGHT);

        bool selected =
            (i == settingsIndex);

        uint16_t background =
            selected
                ? SETTINGS_SELECTED_COLOR
                : COLOR_BACKGROUND;

        uint16_t textColor =
            selected
                ? SETTINGS_SELECTED_TEXT_COLOR
                : SETTINGS_TEXT_COLOR;

        tft.fillRect(
            SETTINGS_ITEM_X - 4,
            y - 2,
            SCREEN_WIDTH -
                SETTINGS_ITEM_X * 2 + 8,
            SETTINGS_ITEM_HEIGHT - 2,
            background
        );

        tft.drawFastHLine(
            SETTINGS_ITEM_X,
            y + SETTINGS_ITEM_HEIGHT - 4,
            SCREEN_WIDTH -
                SETTINGS_ITEM_X * 2,
            SETTINGS_LINE_COLOR
        );

        tft.setTextFont(1);
        tft.setTextSize(1);
        tft.setTextDatum(ML_DATUM);

        tft.setTextColor(
            textColor,
            background
        );

        if (selected)
        {
            tft.drawString(
                ">",
                SETTINGS_ITEM_X,
                y + SETTINGS_ITEM_HEIGHT / 2 - 2
            );

            tft.drawString(
                settingsItems[i],
                SETTINGS_ITEM_X + 12,
                y + SETTINGS_ITEM_HEIGHT / 2 - 2
            );
        }
        else
        {
            tft.drawString(
                settingsItems[i],
                SETTINGS_ITEM_X + 12,
                y + SETTINGS_ITEM_HEIGHT / 2 - 2
            );
        }
    }
}

// ============================================================
// UPDATE
// ============================================================

void pSettingsUpdate()
{
}

// ============================================================
// NAVIGATION
// ============================================================

void pSettingsButtonUp()
{
    settingsIndex--;

    if (settingsIndex < 0)
    {
        settingsIndex = SETTINGS_COUNT - 1;
    }

    pSettingsShow();
}

void pSettingsButtonDown()
{
    settingsIndex++;

    if (settingsIndex >= SETTINGS_COUNT)
    {
        settingsIndex = 0;
    }

    pSettingsShow();
}

void pSettingsButtonLeft()
{
}

void pSettingsButtonRight()
{
}

void pSettingsButtonOk()
{
}

void pSettingsButtonCancel()
{
}

void pSettingsButtonMenu()
{
}