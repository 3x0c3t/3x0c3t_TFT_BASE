#include "display.h"

#include <time.h>

#include "config.h"

// ============================================================
// TFT
// ============================================================

TFT_eSPI tft = TFT_eSPI();

// ============================================================
// ETAT
// ============================================================

static uint16_t statusColors[4] =
{
    COLOR_HEADER_STATUS,
    COLOR_HEADER_STATUS,
    COLOR_HEADER_STATUS,
    COLOR_HEADER_STATUS
};

static uint8_t progressValue = 0;

// ============================================================
// FONCTION INTERNE
// ============================================================

static void drawArrow(
    int centerX,
    int centerY,
    int w,
    int h,
    uint8_t direction,
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

    drawInterface(
        "SYSTEME"
    );
}

// ============================================================
// INTERFACE COMPLETE
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

    tft.drawFastHLine(
        0,
        HEADER_LINE_1_Y,
        SCREEN_WIDTH,
        COLOR_HEADER_LINE
    );

    tft.drawFastHLine(
        0,
        HEADER_LINE_2_Y,
        SCREEN_WIDTH,
        COLOR_HEADER_LINE
    );
}

// ============================================================
// HEURE
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
        COLOR_HEADER_TIME,
        COLOR_BACKGROUND
    );

    tft.drawString(
        String(buffer),
        HEADER_TIME_X,
        HEADER_TIME_Y
    );
}

// ============================================================
// CARRES DE STATUT
// ============================================================

void drawStatusSquares()
{
    const int squareSize = 7;
    const int spacing = 2;

    const int totalWidth =
        (squareSize * 4) +
        (spacing * 3);

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
    tft.fillRect(
        0,
        PROGRESS_Y,
        SCREEN_WIDTH,
        PROGRESS_HEIGHT,
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
        tft.fillRect(
            0,
            PROGRESS_Y,
            width,
            PROGRESS_HEIGHT,
            COLOR_PROGRESS
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
        COLOR_TITLE_TEXT,
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
        COLOR_TITLE_LINE
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

    // --------------------------------------------------------
    // FOND
    // --------------------------------------------------------

    tft.fillRect(
        0,
        y,
        SCREEN_WIDTH,
        height,
        COLOR_FOOTER_BG
    );

    // --------------------------------------------------------
    // LIGNE SUPERIEURE
    // --------------------------------------------------------

    tft.drawFastHLine(
        0,
        y,
        SCREEN_WIDTH,
        COLOR_FOOTER_LINE
    );

// --------------------------------------------------------
// BOUTON MENU
// --------------------------------------------------------

const int buttonY =
    y + 1;

const int buttonHeight =
    height - 1;

const int iconSize =
    FOOTER_MENU_ICON_SIZE;

const int iconX =
    (FOOTER_MENU_WIDTH - iconSize) / 2;

const int iconY =
    buttonY +
    (buttonHeight - iconSize) / 2;

tft.drawRoundRect(
    iconX,
    iconY,
    iconSize,
    iconSize,
    FOOTER_MENU_ICON_RADIUS,
    COLOR_FOOTER_MENU
);

    // --------------------------------------------------------
    // SEPARATION MENU / INFORMATIONS
    // --------------------------------------------------------

    tft.drawFastVLine(
        FOOTER_MENU_WIDTH,
        y + 1,
        height - 1,
        COLOR_FOOTER_LINE
    );

    // --------------------------------------------------------
    // ZONE INFORMATIONS
    // --------------------------------------------------------

    drawFooterInfo(
        ""
    );
}

// ============================================================
// INFORMATIONS FOOTER
// ============================================================

void drawFooterInfo(
    const String& text
)
{
    const int x =
        FOOTER_MENU_WIDTH + 2;

    const int y =
        FOOTER_Y + 1;

    const int width =
        SCREEN_WIDTH -
        FOOTER_MENU_WIDTH -
        2;

    const int height =
        FOOTER_HEIGHT - 2;

    // --------------------------------------------------------
    // NETTOYAGE
    // --------------------------------------------------------

    tft.fillRect(
        x,
        y,
        width,
        height,
        COLOR_FOOTER_BG
    );

    // --------------------------------------------------------
    // PAS DE TEXTE
    // --------------------------------------------------------

    if (text.length() == 0)
    {
        return;
    }

    // --------------------------------------------------------
    // TEXTE
    // --------------------------------------------------------

    tft.setTextFont(
        1
    );

    tft.setTextSize(
        1
    );

    tft.setTextDatum(
        ML_DATUM
    );

    tft.setTextColor(
        COLOR_FOOTER_INFO,
        COLOR_FOOTER_BG
    );

    tft.drawString(
        text,
        x + 3,
        y + height / 2
    );
}

// ============================================================
// FLECHES
// ============================================================

static void drawArrow(
    int centerX,
    int centerY,
    int w,
    int h,
    uint8_t direction,
    uint16_t color
)
{
    int left =
        centerX -
        w / 2;

    int top =
        centerY -
        h / 2;

    int right =
        centerX +
        w / 2;

    int bottom =
        centerY +
        h / 2;

    tft.drawRect(
        left,
        top,
        w,
        h,
        COLOR_FOOTER_LINE
    );

    const int shaft = 3;
    const int head = 5;

    // --------------------------------------------------------
    // HAUT
    // --------------------------------------------------------

    if (direction == 0)
    {
        tft.fillRect(
            centerX - shaft / 2,
            centerY - 1,
            shaft,
            7,
            color
        );

        tft.fillTriangle(
            centerX,
            top + 3,
            centerX - head,
            top + 9,
            centerX + head,
            top + 9,
            color
        );
    }

    // --------------------------------------------------------
    // BAS
    // --------------------------------------------------------

    else if (direction == 1)
    {
        tft.fillRect(
            centerX - shaft / 2,
            centerY - 6,
            shaft,
            7,
            color
        );

        tft.fillTriangle(
            centerX,
            bottom - 3,
            centerX - head,
            bottom - 9,
            centerX + head,
            bottom - 9,
            color
        );
    }

    // --------------------------------------------------------
    // GAUCHE
    // --------------------------------------------------------

    else if (direction == 2)
    {
        tft.fillRect(
            centerX - 1,
            centerY - shaft / 2,
            7,
            shaft,
            color
        );

        tft.fillTriangle(
            left + 3,
            centerY,
            left + 9,
            centerY - head,
            left + 9,
            centerY + head,
            color
        );
    }

    // --------------------------------------------------------
    // DROITE
    // --------------------------------------------------------

    else
    {
        tft.fillRect(
            centerX - 6,
            centerY - shaft / 2,
            7,
            shaft,
            color
        );

        tft.fillTriangle(
            right - 3,
            centerY,
            right - 9,
            centerY - head,
            right - 9,
            centerY + head,
            color
        );
    }
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

    // --------------------------------------------------------
    // BORDURE
    // --------------------------------------------------------

    tft.drawRect(
        x,
        y,
        w,
        h,
        COLOR_FOOTER_LINE
    );

    // --------------------------------------------------------
    // FOND
    // --------------------------------------------------------

    tft.fillRect(
        x + 1,
        y + 1,
        w - 2,
        h - 2,
        color
    );

    // --------------------------------------------------------
    // TEXTE
    // --------------------------------------------------------

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

    if (color == COLOR_BUTTON_OK ||
        color == COLOR_FOOTER_MENU)
    {
        textColor =
            TFT_BLACK;
    }

    if (color == COLOR_BUTTON_CANCEL)
    {
        textColor =
            TFT_WHITE;
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
// STATUT
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