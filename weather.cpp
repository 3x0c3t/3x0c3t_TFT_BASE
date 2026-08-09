#include "weather.h"

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

#include "config.h"
#include "secrets.h"
#include "display.h"
#include "wifi.h"

// ============================================================
// DONNEES METEO
// ============================================================

static float weatherTemperature = 0.0;
static float weatherFeelsLike = 0.0;
static float weatherTempMin = 0.0;
static float weatherTempMax = 0.0;
static float weatherHumidity = 0.0;
static float weatherPressure = 0.0;

static String weatherDescription = "";

static unsigned long lastWeatherUpdate = 0;

// ============================================================
// INITIALISATION
// ============================================================

void weatherInit()
{
    weatherTemperature = 0.0;
    weatherFeelsLike = 0.0;
    weatherTempMin = 0.0;
    weatherTempMax = 0.0;
    weatherHumidity = 0.0;
    weatherPressure = 0.0;

    weatherDescription = "";

    lastWeatherUpdate = 0;
}

// ============================================================
// MISE A JOUR
// ============================================================

bool weatherUpdate()
{
    if (
        strlen(WEATHER_API_KEY) == 0
    )
    {
        Serial.println(
            "METEO : cle API absente"
        );

        return false;
    }

    if (!wifiIsConnected())
    {
        Serial.println(
            "METEO : WiFi non connecte"
        );

        return false;
    }

    unsigned long now =
        millis();

    if (
        lastWeatherUpdate != 0 &&
        now - lastWeatherUpdate <
        WEATHER_REFRESH_TIME
    )
    {
        return true;
    }

    String url =
        "http://api.openweathermap.org/data/2.5/weather";

    url +=
        "?q=" +
        String(WEATHER_CITY) +
        "," +
        String(WEATHER_COUNTRY);

    url +=
        "&appid=" +
        String(WEATHER_API_KEY);

    url +=
        "&units=metric";

    url +=
        "&lang=fr";

    WiFiClient client;

    HTTPClient http;

    Serial.println(
        "[METEO] Requete OpenWeather..."
    );

    if (
        !http.begin(
            client,
            url
        )
    )
    {
        Serial.println(
            "METEO : impossible de demarrer HTTP"
        );

        return false;
    }

    int httpCode =
        http.GET();

    if (
        httpCode !=
        HTTP_CODE_OK
    )
    {
        Serial.print(
            "METEO HTTP : "
        );

        Serial.println(
            httpCode
        );

        http.end();

        return false;
    }

    String payload =
        http.getString();

    http.end();

    DynamicJsonDocument doc(
        4096
    );

    DeserializationError error =
        deserializeJson(
            doc,
            payload
        );

    if (error)
    {
        Serial.print(
            "METEO JSON : "
        );

        Serial.println(
            error.c_str()
        );

        return false;
    }

    weatherTemperature =
        doc["main"]["temp"] |
        0.0;

    weatherFeelsLike =
        doc["main"]["feels_like"] |
        0.0;

    weatherTempMin =
        doc["main"]["temp_min"] |
        0.0;

    weatherTempMax =
        doc["main"]["temp_max"] |
        0.0;

    weatherHumidity =
        doc["main"]["humidity"] |
        0.0;

    weatherPressure =
        doc["main"]["pressure"] |
        0.0;

    weatherDescription =
        doc["weather"][0]["description"] |
        "";

    lastWeatherUpdate =
        now;

    Serial.println(
        "[METEO] Mise a jour OK"
    );

    Serial.print(
        "[METEO] Temperature : "
    );

    Serial.print(
        weatherTemperature,
        1
    );

    Serial.println(
        " C"
    );

    return true;
}

// ============================================================
// AFFICHAGE
// ============================================================

void drawWeather(
    int x,
    int y
)
{
    tft.setTextFont(1);

    tft.setTextSize(1);

    tft.setTextDatum(
        TL_DATUM
    );

    tft.setTextColor(
        COLOR_TEXT,
        COLOR_BACKGROUND
    );

    tft.drawString(
        "METEO",
        x,
        y
    );

    tft.drawString(
        "Temperature : " +
        String(
            weatherTemperature,
            1
        ) +
        " C",
        x,
        y + 16
    );

    tft.drawString(
        "Ressentie   : " +
        String(
            weatherFeelsLike,
            1
        ) +
        " C",
        x,
        y + 30
    );

    tft.drawString(
        "Mini / Maxi : " +
        String(
            weatherTempMin,
            1
        ) +
        " / " +
        String(
            weatherTempMax,
            1
        ) +
        " C",
        x,
        y + 44
    );

    tft.drawString(
        "Humidite    : " +
        String(
            weatherHumidity,
            0
        ) +
        " %",
        x,
        y + 58
    );

    tft.drawString(
        "Pression    : " +
        String(
            weatherPressure,
            0
        ) +
        " hPa",
        x,
        y + 72
    );

    if (
        weatherDescription.length() > 0
    )
    {
        tft.drawString(
            weatherDescription,
            x,
            y + 86
        );
    }
}