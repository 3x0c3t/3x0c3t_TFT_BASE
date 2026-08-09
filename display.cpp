#include "display.h"

#include <time.h>

// ============================================================
// TFT
// ============================================================

TFT_eSPI tft = TFT_eSPI();

// ============================================================
// STRUCTURE INDICATEUR
// ============================================================

struct StatusItem
{
    bool used;
    bool enabled;
    String label;
    uint16_t color;
};

// ============================================================
// TABLEAU DES INDICATEURS
// ============================================================

static StatusItem statusItems[STATUS_MAX];

// ============================================================
// PROGRESSION
// ============================================================

static uint8_t progressValue = 0;

// ============================================================
// DECLARATION INTERNE
// ============================================================

static void drawArrow(
    int centerX,
    int centerY,
    int directionX,
    int directionY,
    uint16_t color
);

// ============================================================
// INITIALISATION
// ============================================================

void displayInit()
{
    tft.init();

    tft.setRotation(
        TFT_ROTATION
    );

    tft.fillScreen(
        COLOR_BACKGROUND
    );

    tft.setTextWrap(
        false
    );

    clearStatus();

    drawInterface(
        "SYSTEME"
    );
}

// ============================================================
// INTERFACE
// ============================================================

void drawInterface(
    const String& title
)
{
    tft.fillScreen(
        COLOR_BACKGROUND
    );

    drawHeader();

    drawTitle(
        title
    );

    clearContent();

    drawFooter();
}

// ============================================================
// HEADER
// ============================================================

void drawHeader()
{
    drawHeaderTime();

    drawStatusSquares();

    drawProgressBar();

    // Ligne supérieure

    tft.drawFastHLine(
        0,
        HEADER_LINE_1_Y,
        SCREEN_WIDTH,
        COLOR_LINE
    );

    // Ligne inférieure

    tft.drawFastHLine(
        0,
        HEADER_LINE_2_Y,
        SCREEN_WIDTH,
        COLOR_LINE
    );
}

// ============================================================
// HEURE / DATE
// ============================================================

void drawHeaderTime()
{
    time_t now =
        time(nullptr);

    struct tm* timeinfo =
        localtime(&now);

    char buffer[32];

    if (timeinfo != nullptr)
    {
        snprintf(
            buffer,
            sizeof(buffer),
            "%02d:%02d:%02d - %04d/%02d/%02d",
            timeinfo->tm_hour,
            timeinfo->tm_min,
            timeinfo->tm_sec,
            timeinfo->tm_year + 1900,
            timeinfo->tm_mon + 1,
            timeinfo->tm_mday
        );
    }
    else
    {
        snprintf(
            buffer,
            sizeof(buffer),
            "--:--:-- - ----/--/--"
        );
    }

    tft.setTextFont(
        1
    );

    tft.setTextSize(
        1
    );

    tft.setTextDatum(
        TL_DATUM
    );

    tft.setTextColor(
        COLOR_TEXT,
        COLOR_BACKGROUND
    );

    tft.drawString(
        String(buffer),
        2,
        0
    );
}

// ============================================================
// INDICATEURS
// ============================================================

void drawStatusSquares()
{
    const int squareSize = 7;
    const int spacing = 2;

    // --------------------------------------------------------
    // Compter les indicateurs actifs
    // --------------------------------------------------------

    int count = 0;

    for (int i = 0; i < STATUS_MAX; i++)
    {
        if (
            statusItems[i].used &&
            statusItems[i].enabled
        )
        {
            count++;
        }
    }

    // --------------------------------------------------------
    // Largeur totale
    // --------------------------------------------------------

    int totalWidth = 0;

    if (count > 0)
    {
        totalWidth =
            (count * squareSize) +
            ((count - 1) * spacing);
    }

    int startX =
        SCREEN_WIDTH -
        totalWidth -
        2;

    // --------------------------------------------------------
    // Nettoyer la zone
    // --------------------------------------------------------

    tft.fillRect(
        SCREEN_WIDTH - 80,
        0,
        80,
        8,
        COLOR_BACKGROUND
    );

    // --------------------------------------------------------
    // Dessiner les indicateurs
    // --------------------------------------------------------

    int x = startX;

    for (int i = 0; i < STATUS_MAX; i++)
    {
        if (
            !statusItems[i].used ||
            !statusItems[i].enabled
        )
        {
            continue;
        }

        // Carré

        tft.fillRect(
            x,
            0,
            squareSize,
            squareSize,
            statusItems[i].color
        );

        // Lettre

        tft.setTextFont(
            1
        );

        tft.setTextSize(
            1
        );

        tft.setTextDatum(
            MC_DATUM
        );

        tft.setTextColor(
            COLOR_BACKGROUND,
            statusItems[i].color
        );

        tft.drawString(
            statusItems[i].label,
            x + squareSize / 2,
            3
        );

        x +=
            squareSize +
            spacing;
    }
}

// ============================================================
// AJOUTER UN INDICATEUR
// ============================================================

bool addStatus(
    const String& label,
    uint16_t color
)
{
    if (label.length() == 0)
    {
        return false;
    }

    // --------------------------------------------------------
    // Chercher s'il existe déjà
    // --------------------------------------------------------

    for (int i = 0; i < STATUS_MAX; i++)
    {
        if (
            statusItems[i].used &&
            statusItems[i].label == label
        )
        {
            statusItems[i].color =
                color;

            statusItems[i].enabled =
                true;

            drawStatusSquares();

            return true;
        }
    }

    // --------------------------------------------------------
    // Chercher une place libre
    // --------------------------------------------------------

    for (int i = 0; i < STATUS_MAX; i++)
    {
        if (!statusItems[i].used)
        {
            statusItems[i].used =
                true;

            statusItems[i].enabled =
                true;

            statusItems[i].label =
                label;

            statusItems[i].color =
                color;

            drawStatusSquares();

            return true;
        }
    }

    return false;
}

// ============================================================
// SUPPRIMER UN INDICATEUR
// ============================================================

bool removeStatus(
    const String& label
)
{
    for (int i = 0; i < STATUS_MAX; i++)
    {
        if (
            statusItems[i].used &&
            statusItems[i].label == label
        )
        {
            statusItems[i].used =
                false;

            statusItems[i].enabled =
                false;

            statusItems[i].label =
                "";

            statusItems[i].color =
                COLOR_LINE;

            drawStatusSquares();

            return true;
        }
    }

    return false;
}

// ============================================================
// MODIFIER LA COULEUR
// ============================================================

bool setStatus(
    const String& label,
    uint16_t color
)
{
    for (int i = 0; i < STATUS_MAX; i++)
    {
        if (
            statusItems[i].used &&
            statusItems[i].label == label
        )
        {
            statusItems[i].color =
                color;

            drawStatusSquares();

            return true;
        }
    }

    return false;
}

// ============================================================
// ACTIVER
// ============================================================

bool enableStatus(
    const String& label
)
{
    for (int i = 0; i < STATUS_MAX; i++)
    {
        if (
            statusItems[i].used &&
            statusItems[i].label == label
        )
        {
            statusItems[i].enabled =
                true;

            drawStatusSquares();

            return true;
        }
    }

    return false;
}

// ============================================================
// DESACTIVER
// ============================================================

bool disableStatus(
    const String& label
)
{
    for (int i = 0; i < STATUS_MAX; i++)
    {
        if (
            statusItems[i].used &&
            statusItems[i].label == label
        )
        {
            statusItems[i].enabled =
                false;

            drawStatusSquares();

            return true;
        }
    }

    return false;
}

// ============================================================
// EFFACER TOUS LES INDICATEURS
// ============================================================

void clearStatus()
{
    for (int i = 0; i < STATUS_MAX; i++)
    {
        statusItems[i].used =
            false;

        statusItems[i].enabled =
            false;

        statusItems[i].label =
            "";

        statusItems[i].color =
            COLOR_LINE;
    }

    drawStatusSquares();
}

// ============================================================
// BARRE DE PROGRESSION
// ============================================================

void drawProgressBar()
{
    tft.drawFastHLine(
        0,
        PROGRESS_Y,
        SCREEN_WIDTH,
        COLOR_BACKGROUND
    );

    int width =
        map(
            progressValue,
            0,
            100,
            0,
            SCREEN_WIDTH
        );

    if (width > 0)
    {
        tft.drawFastHLine(
            0,
            PROGRESS_Y,
            width,
            COLOR_PRIMARY
        );
    }
}

// ============================================================
// PROGRESSION
// ============================================================

void setProgress(
    uint8_t percent
)
{
    if (percent > 100)
    {
        percent = 100;
    }

    progressValue =
        percent;

    drawProgressBar();
}

// ============================================================
// TITRE
// ============================================================

void drawTitle(
    const String& title
)
{
    tft.fillRect(
        0,
        TITLE_Y,
        SCREEN_WIDTH,
        TITLE_HEIGHT,
        COLOR_BACKGROUND
    );

    tft.setTextFont(
        2
    );

    tft.setTextSize(
        1
    );

    tft.setTextDatum(
        TC_DATUM
    );

    tft.setTextColor(
        COLOR_PRIMARY,
        COLOR_BACKGROUND
    );

    tft.drawString(
        title,
        SCREEN_WIDTH / 2,
        TITLE_Y + 1
    );

    tft.drawFastHLine(
        0,
        TITLE_LINE_Y,
        SCREEN_WIDTH,
        COLOR_LINE
    );
}

// ============================================================
// CONTENU
// ============================================================

void clearContent()
{
    tft.fillRect(
        0,
        CONTENT_Y,
        SCREEN_WIDTH,
        CONTENT_HEIGHT,
        COLOR_BACKGROUND
    );
}

// ============================================================
// FOOTER
// ============================================================

void drawFooter()
{
    const int y =
        FOOTER_Y;

    const int height =
        FOOTER_HEIGHT;

    tft.fillRect(
        0,
        y,
        SCREEN_WIDTH,
        height,
        COLOR_BACKGROUND
    );

    tft.drawFastHLine(
        0,
        y,
        SCREEN_WIDTH,
        COLOR_LINE
    );

    const int buttonCount = 6;

    const int baseWidth =
        SCREEN_WIDTH /
        buttonCount;

    const int remainder =
        SCREEN_WIDTH %
        buttonCount;

    int x = 0;

    for (int i = 0; i < buttonCount; i++)
    {
        int w =
            baseWidth +
            (i < remainder ? 1 : 0);

        uint16_t color =
            COLOR_BUTTON;

        if (i == 4)
        {
            color =
                COLOR_ERROR;
        }

        if (i == 5)
        {
            color =
                COLOR_OK;
        }

        tft.drawRect(
            x,
            y + 1,
            w,
            height - 1,
            COLOR_LINE
        );

        tft.fillRect(
            x + 1,
            y + 2,
            w - 2,
            height - 3,
            color
        );

        int centerX =
            x + w / 2;

        int centerY =
            y + height / 2;

        if (i == 0)
        {
            drawArrow(
                centerX,
                centerY,
                0,
                -1,
                COLOR_BUTTON_TEXT
            );
        }
        else if (i == 1)
        {
            drawArrow(
                centerX,
                centerY,
                0,
                1,
                COLOR_BUTTON_TEXT
            );
        }
        else if (i == 2)
        {
            drawArrow(
                centerX,
                centerY,
                -1,
                0,
                COLOR_BUTTON_TEXT
            );
        }
        else if (i == 3)
        {
            drawArrow(
                centerX,
                centerY,
                1,
                0,
                COLOR_BUTTON_TEXT
            );
        }
        else if (i == 4)
        {
            const int s = 5;

            tft.drawLine(
                centerX - s,
                centerY - s,
                centerX + s,
                centerY + s,
                TFT_WHITE
            );

            tft.drawLine(
                centerX + s,
                centerY - s,
                centerX - s,
                centerY + s,
                TFT_WHITE
            );
        }
        else if (i == 5)
        {
            tft.drawLine(
                centerX - 6,
                centerY,
                centerX - 2,
                centerY + 4,
                TFT_BLACK
            );

            tft.drawLine(
                centerX - 2,
                centerY + 4,
                centerX + 7,
                centerY - 6,
                TFT_BLACK
            );
        }

        x += w;
    }
}

// ============================================================
// FLECHE
// ============================================================

static void drawArrow(
    int centerX,
    int centerY,
    int directionX,
    int directionY,
    uint16_t color
)
{
    const int length = 8;
    const int head = 5;

    if (directionX == 0)
    {
        tft.drawLine(
            centerX,
            centerY - directionY * length,
            centerX,
            centerY + directionY * length,
            color
        );

        tft.drawLine(
            centerX,
            centerY + directionY * length,
            centerX - head,
            centerY + directionY * length
                - directionY * head,
            color
        );

        tft.drawLine(
            centerX,
            centerY + directionY * length,
            centerX + head,
            centerY + directionY * length
                - directionY * head,
            color
        );
    }
    else
    {
        tft.drawLine(
            centerX - directionX * length,
            centerY,
            centerX + directionX * length,
            centerY,
            color
        );

        tft.drawLine(
            centerX + directionX * length,
            centerY,
            centerX + directionX * length
                - directionX * head,
            centerY - head,
            color
        );

        tft.drawLine(
            centerX + directionX * length,
            centerY,
            centerX + directionX * length
                - directionX * head,
            centerY + head,
            color
        );
    }
}

// ============================================================
// BOUTON CLASSIQUE
// ============================================================

void drawButton(
    int x,
    int y,
    int w,
    int h,
    const String& label,
    uint16_t color
)
{
    if (w < 3 || h < 3)
    {
        return;
    }

    tft.drawRect(
        x,
        y,
        w,
        h,
        COLOR_LINE
    );

    tft.fillRect(
        x + 1,
        y + 1,
        w - 2,
        h - 2,
        color
    );

    tft.setTextFont(
        1
    );

    tft.setTextSize(
        1
    );

    tft.setTextDatum(
        MC_DATUM
    );

    uint16_t textColor =
        COLOR_BUTTON_TEXT;

    if (color == COLOR_OK)
    {
        textColor =
            TFT_BLACK;
    }

    tft.setTextColor(
        textColor,
        color
    );

    tft.drawString(
        label,
        x + w / 2,
        y + h / 2
    );
}

// ============================================================
// TEXTE CENTRE
// ============================================================

void centerText(
    const String& text,
    int y,
    uint8_t size,
    uint16_t color
)
{
    tft.setTextFont(
        1
    );

    tft.setTextSize(
        size
    );

    tft.setTextDatum(
        TC_DATUM
    );

    tft.setTextColor(
        color,
        COLOR_BACKGROUND
    );

    tft.drawString(
        text,
        SCREEN_WIDTH / 2,
        y
    );
}