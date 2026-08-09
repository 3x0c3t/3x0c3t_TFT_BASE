#include "display.h"
#include <time.h>

// ============================================================
// TFT
// ============================================================

TFT_eSPI tft = TFT_eSPI();

// ============================================================
// STATUTS
// ============================================================

#define MAX_STATUS 4

struct StatusItem
{
    bool active;
    String label;
    uint16_t color;
};

static StatusItem statusItems[MAX_STATUS];

// ============================================================
// PROGRESSION
// ============================================================

static uint8_t progressValue = 0;

// ============================================================
// PROTOTYPE INTERNE
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

    tft.drawFastHLine(
        0,
        HEADER_LINE_1_Y,
        SCREEN_WIDTH,
        COLOR_LINE
    );

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
// STATUTS
// ============================================================

void drawStatusSquares()
{
    const int squareSize = 7;
    const int spacing = 2;
    const int labelWidth = 7;

    int activeCount = 0;

    for (int i = 0; i < MAX_STATUS; i++)
    {
        if (statusItems[i].active)
        {
            activeCount++;
        }
    }

    if (activeCount == 0)
    {
        return;
    }

    int totalWidth = 0;

    for (int i = 0; i < MAX_STATUS; i++)
    {
        if (!statusItems[i].active)
        {
            continue;
        }

        totalWidth += labelWidth;
        totalWidth += squareSize;
        totalWidth += spacing;
    }

    totalWidth -= spacing;

    int startX =
        SCREEN_WIDTH -
        totalWidth -
        2;

    int x =
        startX;

    for (int i = 0; i < MAX_STATUS; i++)
    {
        if (!statusItems[i].active)
        {
            continue;
        }

        tft.setTextFont(
            1
        );

        tft.setTextSize(
            1
        );

        tft.setTextDatum(
            TR_DATUM
        );

        tft.setTextColor(
            COLOR_TEXT,
            COLOR_BACKGROUND
        );

        tft.drawString(
            statusItems[i].label,
            x + labelWidth,
            0
        );

        x += labelWidth;

        tft.fillRect(
            x,
            0,
            squareSize,
            squareSize,
            statusItems[i].color
        );

        x += squareSize;

        if (i < MAX_STATUS - 1)
        {
            x += spacing;
        }
    }
}

// ============================================================
// AJOUT STATUT
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

    // Si le statut existe déjà,
    // on met simplement sa couleur à jour.

    for (int i = 0; i < MAX_STATUS; i++)
    {
        if (
            statusItems[i].active &&
            statusItems[i].label == label
        )
        {
            statusItems[i].color =
                color;

            drawStatusSquares();

            return true;
        }
    }

    // Recherche d'un emplacement libre.

    for (int i = 0; i < MAX_STATUS; i++)
    {
        if (!statusItems[i].active)
        {
            statusItems[i].active =
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
// MODIFICATION STATUT
// ============================================================

bool setStatus(
    const String& label,
    uint16_t color
)
{
    for (int i = 0; i < MAX_STATUS; i++)
    {
        if (
            statusItems[i].active &&
            statusItems[i].label == label
        )
        {
            statusItems[i].color =
                color;

            drawStatusSquares();

            return true;
        }
    }

    return addStatus(
        label,
        color
    );
}

// ============================================================
// COMPATIBILITE ANCIEN SYSTEME
// ============================================================

void setStatus(
    int index,
    uint16_t color
)
{
    if (
        index < 0 ||
        index >= MAX_STATUS
    )
    {
        return;
    }

    if (!statusItems[index].active)
    {
        return;
    }

    statusItems[index].color =
        color;

    drawStatusSquares();
}

// ============================================================
// SUPPRESSION DES STATUTS
// ============================================================

void clearStatus()
{
    for (int i = 0; i < MAX_STATUS; i++)
    {
        statusItems[i].active =
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

    const int buttonCount = 7;

    const int baseWidth =
        SCREEN_WIDTH /
        buttonCount;

    const int remainder =
        SCREEN_WIDTH %
        buttonCount;

    int x = 0;

    int w =
        baseWidth +
        (0 < remainder ? 1 : 0);

    drawArrow(
        x + w / 2,
        y + height / 2,
        w,
        height,
        0,
        COLOR_BUTTON
    );

    x += w;

    w =
        baseWidth +
        (1 < remainder ? 1 : 0);

    drawArrow(
        x + w / 2,
        y + height / 2,
        w,
        height,
        1,
        COLOR_BUTTON
    );

    x += w;

    w =
        baseWidth +
        (2 < remainder ? 1 : 0);

    drawArrow(
        x + w / 2,
        y + height / 2,
        w,
        height,
        2,
        COLOR_BUTTON
    );

    x += w;

    w =
        baseWidth +
        (3 < remainder ? 1 : 0);

    drawArrow(
        x + w / 2,
        y + height / 2,
        w,
        height,
        3,
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
        "¤",
        COLOR_BUTTON
    );

    x += w;

    w =
        baseWidth +
        (5 < remainder ? 1 : 0);

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
// FLECHE
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
    int margin = 3;

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
        COLOR_LINE
    );

    int shaft = 4;
    int head = 6;

    if (direction == 0)
    {
        tft.fillRect(
            centerX - shaft / 2,
            centerY - head,
            shaft,
            head + 7,
            color
        );

        tft.fillTriangle(
            centerX,
            top + margin + 2,
            centerX - head,
            top + margin + 8,
            centerX + head,
            top + margin + 8,
            color
        );
    }
    else if (direction == 1)
    {
        tft.fillRect(
            centerX - shaft / 2,
            centerY - 7,
            shaft,
            head + 7,
            color
        );

        tft.fillTriangle(
            centerX,
            bottom - margin - 2,
            centerX - head,
            bottom - margin - 8,
            centerX + head,
            bottom - margin - 8,
            color
        );
    }
    else if (direction == 2)
    {
        tft.fillRect(
            centerX - head,
            centerY - shaft / 2,
            head + 7,
            shaft,
            color
        );

        tft.fillTriangle(
            left + margin + 2,
            centerY,
            left + margin + 8,
            centerY - head,
            left + margin + 8,
            centerY + head,
            color
        );
    }
    else
    {
        tft.fillRect(
            centerX - 7,
            centerY - shaft / 2,
            head + 7,
            shaft,
            color
        );

        tft.fillTriangle(
            right - margin - 2,
            centerY,
            right - margin - 8,
            centerY - head,
            right - margin - 8,
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
    if (
        w < 3 ||
        h < 3
    )
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