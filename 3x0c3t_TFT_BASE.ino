#include <Arduino.h>
#include <TFT_eSPI.h>
#include <time.h>

#include "config.h"
#include "display.h"
#include "weather.h"
#include "wifi.h"

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

    // --------------------------------------------------------
    // ECRAN
    // --------------------------------------------------------

    displayInit();

    // --------------------------------------------------------
    // STATUTS
    // --------------------------------------------------------

    clearStatus();

    // --------------------------------------------------------
    // PROGRESSION
    // --------------------------------------------------------

    setProgress(
        10
    );

    // --------------------------------------------------------
    // WIFI
    // --------------------------------------------------------

    wifiInit();

    setProgress(
        50
    );

    // --------------------------------------------------------
    // METEO
    // --------------------------------------------------------

    weatherInit();

    setProgress(
        100
    );

    delay(
        300
    );

    drawInterface(
        "SYSTEME"
    );

    Serial.println(
        "[BOOT] Initialisation terminee"
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

    // --------------------------------------------------------
    // WIFI
    // --------------------------------------------------------

    wifiUpdate();

    // --------------------------------------------------------
    // HEADER
    // --------------------------------------------------------

    if (
        now - lastDisplayUpdate >=
        1000
    )
    {
        lastDisplayUpdate =
            now;

        drawHeaderTime();

        drawStatusSquares();
    }

    // --------------------------------------------------------
    // METEO
    // --------------------------------------------------------

    if (
        now - lastWeatherUpdate >=
        10000
    )
    {
        lastWeatherUpdate =
            now;

        if (
            weatherUpdate()
        )
        {
            drawWeather(
                10,
                CONTENT_Y + 10
            );
        }
    }

    delay(
        10
    );
}