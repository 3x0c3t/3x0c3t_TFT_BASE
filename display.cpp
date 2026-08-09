#include "display.h"

#include <time.h>

// ============================================================
// TFT
// ============================================================

TFT_eSPI tft = TFT_eSPI();

// ============================================================
// ETATS
// ============================================================

static uint16_t statusColors[4] =
{
    COLOR_LINE,
    COLOR_LINE,
    COLOR_LINE,
    COLOR_LINE
};

// ============================================================
// PROGRESSION
// ============================================================

static uint8_t progressValue = 0;

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

    tft.drawFastHLine(
        0,
        HEADER_LINE_1_Y,
        SCREEN_WIDTH,
        COLOR_LINE
    );

    drawProgressBar();

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
        localtime(
            &now
        );

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

    tft.fillRect(
        0,
        0,
        SCREEN_WIDTH,
        HEADER_LINE_1_Y,
        COLOR_BACKGROUND
    );

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
// CARRES D'ETAT
// ============================================================

void drawStatusSquares()
{
    const int squareSize = 7;
    const int spacing = 2;

    const int totalWidth =
        squareSize * 4 +
        spacing * 3;

    const int startX =
        SCREEN_WIDTH -
        totalWidth -
        2;

    const int y = 0;

    for (int i = 0; i < 4; i++)
    {
        int x =
            startX +
            i * (squareSize + spacing);

        tft.fillRect(
            x,
            y,
            squareSize,
            squareSize,
            statusColors[i]
        );
    }
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
    int w = 0;

    w =
        baseWidth +
        (0 < remainder ? 1 : 0);

    drawButton(
        x,
        y + 1,
        w,
        height - 1,
        "HAUT",
        COLOR_BUTTON
    );

    x += w;

    w =
        baseWidth +
        (1 < remainder ? 1 : 0);

    drawButton(
        x,
        y + 1,
        w,
        height - 1,
        "BAS",
        COLOR_BUTTON
    );

    x += w;

    w =
        baseWidth +
        (2 < remainder ? 1 : 0);

    drawButton(
        x,
        y + 1,
        w,
        height - 1,
        "GAUCHE",
        COLOR_BUTTON
    );

    x += w;

    w =
        baseWidth +
        (3 < remainder ? 1 : 0);

    drawButton(
        x,
        y + 1,
        w,
        height - 1,
        "DROITE",
        COLOR_BUTTON
    );

    x += w;

    w =
        baseWidth +
        (4 < remainder ? 1 : 0);

    drawButton(
        x,
        y + 1,
        w,
        height - 1,
        "X",
        COLOR_ERROR
    );

    x += w;

    w =
        SCREEN_WIDTH -
        x;

    drawButton(
        x,
        y + 1,
        w,
        height - 1,
        "V",
        COLOR_OK
    );
}

// ============================================================
// BOUTON
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

// ============================================================
// ETAT
// ============================================================

void setStatus(
    int index,
    uint16_t color
)
{
    if (index < 0 || index > 3)
    {
        return;
    }

    statusColors[index] =
        color;

    drawStatusSquares();
}

// ============================================================
// RESET ETATS
// ============================================================

void clearStatus()
{
    for (int i = 0; i < 4; i++)
    {
        statusColors[i] =
            COLOR_LINE;
    }

    drawStatusSquares();
}