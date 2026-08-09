#include "touch.h"
#include "config.h"

#include <SPI.h>
#include <XPT2046_Touchscreen.h>

#define TOUCH_CS   0
#define TOUCH_IRQ  5

XPT2046_Touchscreen touch(TOUCH_CS, TOUCH_IRQ);

static bool touchIsPressed = false;
static uint16_t touchX = 0;
static uint16_t touchY = 0;

void touchInit()
{
    Serial.println();
    Serial.println("[TOUCH] ================================");
    Serial.println("[TOUCH] touchInit() START");

    Serial.print("[TOUCH] CS = GPIO ");
    Serial.println(TOUCH_CS);

    Serial.print("[TOUCH] IRQ = GPIO ");
    Serial.println(TOUCH_IRQ);

    Serial.println("[TOUCH] SPI materiel deja utilise par le TFT");

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

    touchIsPressed = false;
    touchX = 0;
    touchY = 0;

    Serial.println("[TOUCH] touchInit() END");
    Serial.println("[TOUCH] ================================");
}

void touchUpdate()
{
    if (!touch.touched())
    {
        if (touchIsPressed)
        {
            Serial.println("[TOUCH] RELACHE");
        }

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
    Serial.println(point.x);

    Serial.print("[TOUCH] RAW Y = ");
    Serial.println(point.y);

    Serial.print("[TOUCH] RAW Z = ");
    Serial.println(point.z);

    Serial.println("[TOUCH] -------------------------------");
}

bool touchPressed()
{
    return touchIsPressed;
}

uint16_t touchGetX()
{
    return touchX;
}

uint16_t touchGetY()
{
    return touchY;
}
