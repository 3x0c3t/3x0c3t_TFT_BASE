#include "wifi.h"

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <time.h>

#include "config.h"
#include "secrets.h"
#include "display.h"

// ============================================================
// ETAT WIFI
// ============================================================

bool wifiConnected = false;

static unsigned long lastWifiAttempt = 0;

// ============================================================
// INITIALISATION WIFI
// ============================================================

void wifiInit()
{
    Serial.println();
    Serial.println("================================");
    Serial.println("[WIFI] INITIALISATION");
    Serial.println("================================");

    // --------------------------------------------------------
    // Statut WiFi
    // Carré 0 = WiFi
    // --------------------------------------------------------

    setStatus(
        0,
        COLOR_ERROR
    );

    // --------------------------------------------------------
    // Vérification configuration
    // --------------------------------------------------------

    if (
        strlen(WIFI1_SSID) == 0 ||
        strlen(WIFI1_PASSWORD) == 0
    )
    {
        Serial.println(
            "[WIFI] SSID ou mot de passe non configure"
        );

        wifiConnected = false;

        setStatus(
            0,
            COLOR_ERROR
        );

        return;
    }

    // --------------------------------------------------------
    // Configuration ESP8266
    // --------------------------------------------------------

    WiFi.mode(
        WIFI_STA
    );

    WiFi.setAutoReconnect(
        true
    );

    WiFi.persistent(
        false
    );

    // --------------------------------------------------------
    // Connexion
    // --------------------------------------------------------

    Serial.print(
        "[WIFI] Connexion a : "
    );

    Serial.println(
        WIFI1_SSID
    );

    WiFi.begin(
        WIFI1_SSID,
        WIFI1_PASSWORD
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

    // --------------------------------------------------------
    // Connexion réussie
    // --------------------------------------------------------

    if (
        WiFi.status() == WL_CONNECTED
    )
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

        Serial.print(
            "[WIFI] RSSI : "
        );

        Serial.print(
            WiFi.RSSI()
        );

        Serial.println(
            " dBm"
        );

        setStatus(
            0,
            COLOR_OK
        );

        // ----------------------------------------------------
        // Synchronisation NTP
        // ----------------------------------------------------

        configTime(
            3600,
            3600,
            "pool.ntp.org",
            "time.nist.gov"
        );

        Serial.println(
            "[TIME] Synchronisation NTP demandee"
        );
    }

    // --------------------------------------------------------
    // Échec
    // --------------------------------------------------------

    else
    {
        wifiConnected = false;

        Serial.println(
            "[WIFI] ECHEC CONNEXION"
        );

        Serial.print(
            "[WIFI] Etat : "
        );

        Serial.println(
            WiFi.status()
        );

        setStatus(
            0,
            COLOR_ERROR
        );
    }
}

// ============================================================
// MISE A JOUR WIFI
// ============================================================

void wifiUpdate()
{
    wl_status_t status =
        WiFi.status();

    // ========================================================
    // CONNECTE
    // ========================================================

    if (
        status == WL_CONNECTED
    )
    {
        if (!wifiConnected)
        {
            wifiConnected = true;

            Serial.println(
                "[WIFI] CONNEXION RETABLIE"
            );

            Serial.print(
                "[WIFI] IP : "
            );

            Serial.println(
                WiFi.localIP()
            );

            // ------------------------------------------------
            // Relance synchronisation NTP
            // ------------------------------------------------

            configTime(
                3600,
                3600,
                "pool.ntp.org",
                "time.nist.gov"
            );

            Serial.println(
                "[TIME] Synchronisation NTP relancee"
            );
        }

        setStatus(
            0,
            COLOR_OK
        );

        return;
    }

    // ========================================================
    // CONNEXION PERDUE
    // ========================================================

    if (wifiConnected)
    {
        wifiConnected = false;

        Serial.println(
            "[WIFI] CONNEXION PERDUE"
        );

        setStatus(
            0,
            COLOR_ERROR
        );
    }

    // ========================================================
    // VERIFICATION INTERVALLE
    // ========================================================

    if (
        millis() - lastWifiAttempt <
        WIFI_RETRY_INTERVAL
    )
    {
        return;
    }

    lastWifiAttempt =
        millis();

    // ========================================================
    // VERIFICATION CONFIGURATION
    // ========================================================

    if (
        strlen(WIFI1_SSID) == 0 ||
        strlen(WIFI1_PASSWORD) == 0
    )
    {
        Serial.println(
            "[WIFI] Configuration absente"
        );

        setStatus(
            0,
            COLOR_ERROR
        );

        return;
    }

    // ========================================================
    // NOUVELLE TENTATIVE
    // ========================================================

    Serial.println(
        "[WIFI] Nouvelle tentative..."
    );

    setStatus(
        0,
        COLOR_WARNING
    );

    WiFi.disconnect();

    delay(100);

    WiFi.begin(
        WIFI1_SSID,
        WIFI1_PASSWORD
    );
}

// ============================================================
// ETAT WIFI
// ============================================================

bool wifiIsConnected()
{
    return (
        WiFi.status() == WL_CONNECTED
    );
}