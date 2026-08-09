#include "wifi.h"

#include <ESP8266WiFi.h>

#include "config.h"
#include "display.h"

// ============================================================
// ETAT INTERNE
// ============================================================

static unsigned long lastReconnectAttempt = 0;

static bool wifiWasConnected = false;

// ============================================================
// INITIALISATION
// ============================================================

void wifiInit()
{
    Serial.println();
    Serial.println(
        "================================"
    );

    Serial.println(
        "[WIFI] INITIALISATION"
    );

    Serial.println(
        "================================"
    );

    // Ajout du statut WiFi dans le header.

    addStatus(
        "W",
        COLOR_ERROR
    );

    if (
        strlen(WIFI_SSID) == 0
    )
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

    WiFi.mode(
        WIFI_STA
    );

    WiFi.persistent(
        false
    );

    WiFi.setAutoReconnect(
        true
    );

    WiFi.begin(
        WIFI_SSID,
        WIFI_PASSWORD
    );

    Serial.print(
        "[WIFI] Connexion a : "
    );

    Serial.println(
        WIFI_SSID
    );

    unsigned long start =
        millis();

    while (
        WiFi.status() != WL_CONNECTED &&
        millis() - start <
        WIFI_CONNECT_TIMEOUT
    )
    {
        delay(250);

        Serial.print(
            "."
        );
    }

    Serial.println();

    if (
        WiFi.status() ==
        WL_CONNECTED
    )
    {
        wifiWasConnected =
            true;

        setStatus(
            "W",
            COLOR_OK
        );

        Serial.println(
            "[WIFI] CONNECTE"
        );

        Serial.print(
            "[WIFI] SSID : "
        );

        Serial.println(
            WiFi.SSID()
        );

        Serial.print(
            "[WIFI] IP   : "
        );

        Serial.println(
            WiFi.localIP()
        );

        Serial.print(
            "[WIFI] RSSI : "
        );

        Serial.print(
            WiFi.RSSI()
        );

        Serial.println(
            " dBm"
        );
    }
    else
    {
        wifiWasConnected =
            false;

        setStatus(
            "W",
            COLOR_ERROR
        );

        Serial.println(
            "[WIFI] ECHEC CONNEXION"
        );
    }

    lastReconnectAttempt =
        millis();
}

// ============================================================
// MISE A JOUR
// ============================================================

void wifiUpdate()
{
    wl_status_t status =
        WiFi.status();

    // --------------------------------------------------------
    // CONNECTE
    // --------------------------------------------------------

    if (
        status ==
        WL_CONNECTED
    )
    {
        if (!wifiWasConnected)
        {
            wifiWasConnected =
                true;

            setStatus(
                "W",
                COLOR_OK
            );

            Serial.println();
            Serial.println(
                "[WIFI] RECONNECTE"
            );

            Serial.print(
                "[WIFI] IP : "
            );

            Serial.println(
                WiFi.localIP()
            );
        }
        else
        {
            setStatus(
                "W",
                COLOR_OK
            );
        }

        return;
    }

    // --------------------------------------------------------
    // DECONNECTE
    // --------------------------------------------------------

    if (wifiWasConnected)
    {
        wifiWasConnected =
            false;

        setStatus(
            "W",
            COLOR_ERROR
        );

        Serial.println();
        Serial.println(
            "[WIFI] DECONNECTE"
        );
    }

    // --------------------------------------------------------
    // RECONNEXION
    // --------------------------------------------------------

    unsigned long now =
        millis();

    if (
        now - lastReconnectAttempt <
        WIFI_RECONNECT_INTERVAL
    )
    {
        return;
    }

    lastReconnectAttempt =
        now;

    if (
        strlen(WIFI_SSID) == 0
    )
    {
        return;
    }

    Serial.println(
        "[WIFI] Nouvelle tentative..."
    );

    WiFi.disconnect();

    delay(100);

    WiFi.begin(
        WIFI_SSID,
        WIFI_PASSWORD
    );
}

// ============================================================
// ETAT
// ============================================================

bool wifiConnected()
{
    return (
        WiFi.status() ==
        WL_CONNECTED
    );
}

// ============================================================
// SSID
// ============================================================

String wifiSSID()
{
    if (
        WiFi.status() !=
        WL_CONNECTED
    )
    {
        return "";
    }

    return WiFi.SSID();
}

// ============================================================
// IP
// ============================================================

String wifiIP()
{
    if (
        WiFi.status() !=
        WL_CONNECTED
    )
    {
        return "";
    }

    return WiFi.localIP().toString();
}

// ============================================================
// RSSI
// ============================================================

int wifiRSSI()
{
    if (
        WiFi.status() !=
        WL_CONNECTED
    )
    {
        return 0;
    }

    return WiFi.RSSI();
}