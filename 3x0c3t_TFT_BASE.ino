#include <Arduino.h>
#include <TFT_eSPI.h>
#include <time.h>

#include "config.h"
#include "display.h"
#include "weather.h"

// ============================================================
// SETUP
// ============================================================

void setup()
{
    Serial.begin(
        115200
    );

    delay(
        500
    );

    Serial.println();
    Serial.println(
        "================================"
    );
    Serial.println(
        "3x0c3t TFT BASE"
    );
    Serial.println(
        "================================"
    );

    displayInit();

    weatherInit();

    clearStatus();

    setProgress(
        0
    );

    setStatus(
        0,
        COLOR_OK
    );

    setProgress(
        25
    );

    delay(
        250
    );

    setStatus(
        1,
        COLOR_OK
    );

    setProgress(
        50
    );

    delay(
        250
    );

    setStatus(
        2,
        COLOR_OK
    );

    setProgress(
        75
    );

    delay(
        250
    );

    setStatus(
        3,
        COLOR_OK
    );

    setProgress(
        100
    );

    delay(
        500
    );

    drawInterface(
        "SYSTEME"
    );

    Serial.println(
        "Interface TFT initialisee."
    );
}

// ============================================================
// LOOP
// ============================================================

void loop()
{
    static unsigned long lastDisplayUpdate = 0;
    static unsigned long lastWeatherUpdate = 0;

    unsigned long now =
        millis();

    if (
        now - lastDisplayUpdate >=
        1000
    )
    {
        lastDisplayUpdate =
            now;

        drawHeaderTime();
    }

    if (
        now - lastWeatherUpdate >=
        10000
    )
    {
        lastWeatherUpdate =
            now;

        if (weatherUpdate())
        {
            drawWeather(
                10,
                CONTENT_Y + 10
            );
        }
    }
}