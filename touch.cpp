#include "touch.h"
#include "config.h"

#include <SPI.h>
#include <XPT2046_Touchscreen.h>

// ============================================================
// BROCHAGE XPT2046
// ============================================================

#define TOUCH_CS   0
#define TOUCH_IRQ  5

// ============================================================
// OBJET TACTILE
// ============================================================

XPT2046_Touchscreen touch(TOUCH_CS, TOUCH_IRQ);

// ============================================================
// ETAT
// ============================================================

static bool touchIsPressed = false;
static uint16_t touchX = 0;
static uint16_t touchY = 0;

// ============================================================
// INITIALISATION
// ============================================================

void touchInit()
{
    Serial.println();
    Serial.println("[TOUCH] ================================");
    Serial.println("[TOUCH] touchInit() START");

    Serial.print("[TOUCH] CS  = GPIO ");
    Serial.println(TOUCH_CS);

    Serial.print("[TOUCH] IRQ = GPIO ");
    Serial.println(TOUCH_IRQ);

    if (touch.begin())
    {
        Serial.println("[TOUCH] XPT2046 detecte");
    }
    else
    {
        Serial.println("[TOUCH] ERREUR XPT2046");
    }

    touch.setRotation(TFT_ROTATION);

    Serial.print("[TOUCH] rotation = ");
    Serial.println(TFT_ROTATION);

    Serial.println("[TOUCH] touchInit() END");
    Serial.println("[TOUCH] ================================");
}

// ============================================================
// LECTURE
// ============================================================

void touchUpdate()
{
    if (!touch.touched())
    {
        touchIsPressed = false;
        return;
    }

    TS_Point point = touch.getPoint();

    touchX = point.x;
    touchY = point.y;

    touchIsPressed = true;

    Serial.println("[TOUCH] -------------------------------");
    Serial.println("[TOUCH] PRESSION DETECTEE");

    Serial.print("[TOUCH] RAW X = ");
    Serial.println(touchX);

    Serial.print("[TOUCH] RAW Y = ");
    Serial.println(touchY);

    Serial.print("[TOUCH] RAW Z = ");
    Serial.println(point.z);

    Serial.println("[TOUCH] -------------------------------");
}

// ============================================================
// ETAT
// ============================================================

bool touchPressed()
{
    return touchIsPressed;
}

// ============================================================
// X
// ============================================================

uint16_t touchGetX()
{
    return touchX;
}

// ============================================================
// Y
// ============================================================

uint16_t touchGetY()
{
    return touchY;
}