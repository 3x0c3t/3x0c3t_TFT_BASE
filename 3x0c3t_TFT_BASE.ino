#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <time.h>

#include "config.h"
#include "secrets.h"
#include "display.h"

// ============================================================
// WIFI
// ============================================================

bool wifiConnected = false;

unsigned long lastWifiAttempt = 0;

// ============================================================
// WIFI INITIALISATION
// ============================================================

void wifiInit()
{
    Serial.println();
    Serial.println("================================");
    Serial.println("[WIFI] INITIALISATION");
    Serial.println("================================");

    addStatus(
        "W",
        COLOR_ERROR
    );

    if (strlen(WIFI_SSID) == 0)
    {
        Serial.println(
            "[WIFI] SSID non configure"
        );

        setStatus(
            "W",
            COLOR_ERROR
        );

        return;
    }

    Serial.print(
        "[WIFI] Connexion a : "
    );

    Serial.println(
        WIFI_SSID
    );

    WiFi.mode(
        WIFI_STA
    );

    WiFi.begin(
        WIFI_SSID,
        WIFI_PASSWORD
    );

    unsigned long start =
        millis();

    while (
        WiFi.status() != WL_CONNECTED &&
        millis() - start < WIFI_CONNECT_TIMEOUT
    )
    {
        delay(250);

        Serial.print(".");
    }

    Serial.println();

    if (WiFi.status() == WL_CONNECTED)
    {
        wifiConnected = true;

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

        configTime(
            3600,
            3600,
            "pool.ntp.org",
            "time.nist.gov"
        );
    }
    else
    {
        wifiConnected = false;

        Serial.println(
            "[WIFI] ECHEC CONNEXION"
        );

        setStatus(
            "W",
            COLOR_ERROR
        );
    }
}

// ============================================================
// WIFI UPDATE
// ============================================================

void wifiUpdate()
{
    wl_status_t status =
        WiFi.status();

    if (status == WL_CONNECTED)
    {
        if (!wifiConnected)
        {
            wifiConnected = true;

            Serial.println(
                "[WIFI] CONNEXION RETABLIE"
            );
        }

        setStatus(
            "W",
            COLOR_OK
        );

        return;
    }

    if (wifiConnected)
    {
        wifiConnected = false;

        Serial.println(
            "[WIFI] CONNEXION PERDUE"
        );

        setStatus(
            "W",
            COLOR_ERROR
        );
    }

    if (
        millis() - lastWifiAttempt >
        WIFI_RETRY_INTERVAL
    )
    {
        lastWifiAttempt =
            millis();

        Serial.println(
            "[WIFI] Nouvelle tentative..."
        );

        WiFi.disconnect();

        WiFi.begin(
            WIFI_SSID,
            WIFI_PASSWORD
        );
    }
}

// ============================================================
// SETUP
// ============================================================

void setup()
{
    Serial.begin(115200);

    delay(500);

    Serial.println();
    Serial.println(
        "[BOOT] Demarrage"
    );

    displayInit();

    wifiInit();

    Serial.println();
    Serial.println(
        "[BOOT] Initialisation terminee"
    );
}

// ============================================================
// LOOP
// ============================================================

void loop()
{
    wifiUpdate();

    drawHeaderTime();

    delay(1000);
}