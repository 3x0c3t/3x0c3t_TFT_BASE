#include <Arduino.h>
#include <TFT_eSPI.h>
#include <time.h>

#include <ESP8266WiFi.h>

#include "config.h"
#include "display.h"
#include "weather.h"

// ============================================================
// WIFI
// ============================================================

static bool wifiEnabled = false;

// ============================================================
// INITIALISATION WIFI
// ============================================================

void wifiInit()
{
    Serial.println();
    Serial.println(
        "[WIFI] Initialisation"
    );

    // --------------------------------------------------------
    // Aucun SSID configuré
    // --------------------------------------------------------

    if (
        strlen(WIFI_SSID) == 0
    )
    {
        Serial.println(
            "[WIFI] Aucun SSID configure"
        );

        wifiEnabled =
            false;

        addStatus(
            "W",
            COLOR_ERROR
        );

        return;
    }

    wifiEnabled =
        true;

    addStatus(
        "W",
        COLOR_WARNING
    );

    WiFi.mode(
        WIFI_STA
    );

    WiFi.begin(
        WIFI_SSID,
        WIFI_PASSWORD
    );

    Serial.print(
        "[WIFI] Connexion"
    );

    unsigned long start =
        millis();

    while (
        WiFi.status() != WL_CONNECTED &&
        millis() - start < 15000
    )
    {
        delay(250);

        Serial.print(
            "."
        );
    }

    Serial.println();

    // --------------------------------------------------------
    // Connexion réussie
    // --------------------------------------------------------

    if (
        WiFi.status() == WL_CONNECTED
    )
    {
        Serial.println(
            "[WIFI] CONNECTE"
        );

        Serial.print(
            "[WIFI] IP : "
        );

        Serial.println(
            WiFi.localIP()
        );

        setStatus(
            "W",
            COLOR_OK
        );
    }
    else
    {
        Serial.println(
            "[WIFI] NON CONNECTE"
        );

        setStatus(
            "W",
            COLOR_ERROR
        );
    }
}

// ============================================================
// MISE A JOUR WIFI
// ============================================================

void wifiUpdate()
{
    if (!wifiEnabled)
    {
        return;
    }

    if (
        WiFi.status() == WL_CONNECTED
    )
    {
        setStatus(
            "W",
            COLOR_OK
        );
    }
    else
    {
        setStatus(
            "W",
            COLOR_ERROR
        );
    }
}

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
    // TFT
    // --------------------------------------------------------

    displayInit();

    // --------------------------------------------------------
    // WiFi
    // --------------------------------------------------------

    wifiInit();

    // --------------------------------------------------------
    // Meteo
    // --------------------------------------------------------

    weatherInit();

    // --------------------------------------------------------
    // Progression de démarrage
    // --------------------------------------------------------

    setProgress(
        0
    );

    delay(
        250
    );

    setProgress(
        25
    );

    delay(
        250
    );

    setProgress(
        50
    );

    delay(
        250
    );

    setProgress(
        75
    );

    delay(
        250
    );

    setProgress(
        100
    );

    delay(
        500
    );

    // --------------------------------------------------------
    // Interface
    // --------------------------------------------------------

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
    static unsigned long lastWifiUpdate = 0;

    unsigned long now =
        millis();

    // --------------------------------------------------------
    // Heure
    // --------------------------------------------------------

    if (
        now - lastDisplayUpdate >= 1000
    )
    {
        lastDisplayUpdate =
            now;

        drawHeaderTime();
    }

    // --------------------------------------------------------
    // WiFi
    // --------------------------------------------------------

    if (
        now - lastWifiUpdate >= 2000
    )
    {
        lastWifiUpdate =
            now;

        wifiUpdate();
    }

    // --------------------------------------------------------
    // Meteo
    // --------------------------------------------------------

    if (
        now - lastWeatherUpdate >= 10000
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
}