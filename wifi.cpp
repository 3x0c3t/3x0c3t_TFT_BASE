#include "wifi.h"

#include <ESP8266WiFi.h>
#include <time.h>

#include "config.h"
#include "secrets.h"
#include "display.h"

// ============================================================
// ETAT WIFI
// ============================================================

static bool wifiConnectedState = false;

static unsigned long lastWifiAttempt = 0;

// ============================================================
// WIFI ACTUEL
// ============================================================

static const char* getWifiSSID()
{
    if (strlen(WIFI1_SSID) > 0)
    {
        return WIFI1_SSID;
    }

    return WIFI2_SSID;
}

static const char* getWifiPassword()
{
    if (strlen(WIFI1_SSID) > 0)
    {
        return WIFI1_PASSWORD;
    }

    return WIFI2_PASSWORD;
}

// ============================================================
// INITIALISATION
// ============================================================

void wifiInit()
{
    Serial.println();
    Serial.println("================================");
    Serial.println("[WIFI] INITIALISATION");
    Serial.println("================================");

    setStatus(
        "W",
        COLOR_ERROR
    );

    const char* ssid =
        getWifiSSID();

    const char* password =
        getWifiPassword();

    if (
        ssid == nullptr ||
        strlen(ssid) == 0
    )
    {
        Serial.println(
            "[WIFI] Aucun SSID configure"
        );

        wifiConnectedState = false;

        return;
    }

    Serial.print(
        "[WIFI] Connexion a : "
    );

    Serial.println(
        ssid
    );

    WiFi.mode(
        WIFI_STA
    );

    WiFi.setAutoReconnect(
        true
    );

    WiFi.persistent(
        false
    );

    WiFi.begin(
        ssid,
        password
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

    if (
        WiFi.status() ==
        WL_CONNECTED
    )
    {
        wifiConnectedState = true;

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

        Serial.println(
            "[CLOCK] Synchronisation NTP..."
        );

        configTime(
            CLOCK_GMT_OFFSET,
            CLOCK_DAYLIGHT_OFFSET,
            CLOCK_NTP_SERVER_1,
            CLOCK_NTP_SERVER_2
        );
    }
    else
    {
        wifiConnectedState = false;

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
// MISE A JOUR
// ============================================================

void wifiUpdate()
{
    wl_status_t status =
        WiFi.status();

    if (
        status == WL_CONNECTED
    )
    {
        if (!wifiConnectedState)
        {
            wifiConnectedState = true;

            Serial.println(
                "[WIFI] CONNEXION RETABLIE"
            );

            Serial.print(
                "[WIFI] IP : "
            );

            Serial.println(
                WiFi.localIP()
            );

            configTime(
                CLOCK_GMT_OFFSET,
                CLOCK_DAYLIGHT_OFFSET,
                CLOCK_NTP_SERVER_1,
                CLOCK_NTP_SERVER_2
            );
        }

        setStatus(
            "W",
            COLOR_OK
        );

        return;
    }

    if (wifiConnectedState)
    {
        wifiConnectedState = false;

        Serial.println(
            "[WIFI] CONNEXION PERDUE"
        );

        setStatus(
            "W",
            COLOR_ERROR
        );
    }

    if (
        millis() - lastWifiAttempt <
        WIFI_RETRY_INTERVAL
    )
    {
        return;
    }

    lastWifiAttempt =
        millis();

    const char* ssid =
        getWifiSSID();

    const char* password =
        getWifiPassword();

    if (
        ssid == nullptr ||
        strlen(ssid) == 0
    )
    {
        Serial.println(
            "[WIFI] Aucun SSID configure"
        );

        return;
    }

    Serial.println(
        "[WIFI] Nouvelle tentative..."
    );

    WiFi.disconnect();

    delay(100);

    WiFi.begin(
        ssid,
        password
    );
}

// ============================================================
// ETAT
// ============================================================

bool wifiIsConnected()
{
    return (
        WiFi.status() ==
        WL_CONNECTED
    );
}