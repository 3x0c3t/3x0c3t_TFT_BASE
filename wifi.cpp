#include "wifi.h"

#include <Arduino.h>
#include <ESP8266WiFi.h>

#include "config.h"
#include "secrets.h"
#include "display.h"

// ============================================================
// ETAT WIFI
// ============================================================

bool wifiConnected = false;

static unsigned long lastWifiAttempt = 0;

// ============================================================
// ETAT TEXTE WIFI
// ============================================================

static const char* wifiStatusText()
{
    wl_status_t status = WiFi.status();

    switch (status)
    {
        case WL_CONNECTED:
            return "CONNECTE";

        case WL_NO_SSID_AVAIL:
            return "SSID ABSENT";

        case WL_CONNECT_FAILED:
            return "ECHEC";

        case WL_CONNECTION_LOST:
            return "PERDU";

        case WL_DISCONNECTED:
            return "DECONNECTE";

        case WL_IDLE_STATUS:
            return "IDLE";

        default:
            return "INCONNU";
    }
}

// ============================================================
// CONNEXION A UN RESEAU
// ============================================================

static bool wifiConnect(const char* ssid, const char* password)
{
    Serial.println();
    Serial.println("[WIFI] ================================");
    Serial.println("[WIFI] wifiConnect() START");

    if (ssid == nullptr || password == nullptr)
    {
        Serial.println("[WIFI] ERREUR : SSID ou password NULL");
        Serial.println("[WIFI] wifiConnect() END -> false");
        return false;
    }

    if (strlen(ssid) == 0)
    {
        Serial.println("[WIFI] ERREUR : SSID vide");
        Serial.println("[WIFI] wifiConnect() END -> false");
        return false;
    }

    Serial.print("[WIFI] SSID = ");
    Serial.println(ssid);

    Serial.println("[WIFI] WiFi.mode(WIFI_STA)");

    WiFi.mode(WIFI_STA);

    delay(100);

    Serial.println("[WIFI] WiFi.disconnect()");

    WiFi.disconnect();

    delay(200);

    Serial.println("[WIFI] WiFi.begin()");

    WiFi.begin(ssid, password);

    unsigned long start = millis();

    Serial.println("[WIFI] Attente connexion...");

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(250);

        unsigned long elapsed = millis() - start;

        if (elapsed >= WIFI_CONNECT_TIMEOUT)
        {
            Serial.println();
            Serial.println("[WIFI] TIMEOUT");

            Serial.print("[WIFI] status = ");
            Serial.println(wifiStatusText());

            Serial.print("[WIFI] code status = ");
            Serial.println((int)WiFi.status());

            WiFi.disconnect();

            delay(100);

            Serial.println("[WIFI] wifiConnect() END -> false");
            Serial.println("[WIFI] ================================");

            return false;
        }

        if ((elapsed % 1000) < 300)
        {
            Serial.print(".");
        }

        yield();
    }

    Serial.println();
    Serial.println("[WIFI] CONNEXION OK");

    Serial.print("[WIFI] SSID : ");
    Serial.println(WiFi.SSID());

    Serial.print("[WIFI] IP : ");
    Serial.println(WiFi.localIP());

    Serial.print("[WIFI] RSSI : ");
    Serial.print(WiFi.RSSI());
    Serial.println(" dBm");

    Serial.println("[WIFI] wifiConnect() END -> true");
    Serial.println("[WIFI] ================================");

    wifiConnected = true;

    return true;
}

// ============================================================
// INITIALISATION WIFI
// ============================================================

void wifiInit()
{
    Serial.println();
    Serial.println("================================");
    Serial.println("[BOOT] wifiInit() START");
    Serial.println("================================");

    wifiConnected = false;

    // --------------------------------------------------------
    // MODE STATION
    // --------------------------------------------------------

    Serial.println("[WIFI] ETAPE 1 -> WIFI_STA");

    WiFi.mode(WIFI_STA);

    delay(100);

    Serial.println("[WIFI] ETAPE 1 OK");

    // --------------------------------------------------------
    // DECONNEXION
    // --------------------------------------------------------

    Serial.println("[WIFI] ETAPE 2 -> disconnect");

    WiFi.disconnect();

    delay(500);

    Serial.println("[WIFI] ETAPE 2 OK");

    // --------------------------------------------------------
    // SCAN
    // --------------------------------------------------------

    Serial.println();
    Serial.println("================================");
    Serial.println("[WIFI] SCAN DES RESEAUX");
    Serial.println("================================");

    Serial.println("[WIFI] ETAPE 3 -> scanNetworks()");

    int count = WiFi.scanNetworks();

    Serial.print("[WIFI] ETAPE 3 -> resultat = ");
    Serial.println(count);

    if (count < 0)
    {
        Serial.println("[WIFI] ERREUR SCAN");
    }
    else if (count == 0)
    {
        Serial.println("[WIFI] Aucun reseau detecte");
    }
    else
    {
        Serial.print("[WIFI] Reseaux trouves : ");
        Serial.println(count);

        for (int i = 0; i < count; i++)
        {
            Serial.print("[WIFI] ");
            Serial.print(i);
            Serial.print(" : ");
            Serial.print(WiFi.SSID(i));
            Serial.print(" | RSSI : ");
            Serial.print(WiFi.RSSI(i));
            Serial.print(" dBm | CH : ");
            Serial.println(WiFi.channel(i));

            yield();
        }
    }

    Serial.println("[WIFI] ETAPE 3 OK");

    // --------------------------------------------------------
    // CONFIGURATION
    // --------------------------------------------------------

    Serial.println();
    Serial.println("[WIFI] ================================");
    Serial.println("[WIFI] CONFIGURATION");
    Serial.println("[WIFI] ================================");

    Serial.println("[WIFI] ETAPE 4 -> lecture configuration");

    Serial.print("[WIFI1] SSID = ");
    Serial.println(WIFI1_SSID);

    Serial.print("[WIFI2] SSID = ");
    Serial.println(WIFI2_SSID);

    Serial.println("[WIFI] ETAPE 4 OK");

    // --------------------------------------------------------
    // RECHERCHE WIFI1
    // --------------------------------------------------------

    bool wifi1Found = false;
    bool wifi2Found = false;

    if (count > 0)
    {
        for (int i = 0; i < count; i++)
        {
            String scannedSSID = WiFi.SSID(i);

            if (scannedSSID == String(WIFI1_SSID))
            {
                wifi1Found = true;
            }

            if (scannedSSID == String(WIFI2_SSID))
            {
                wifi2Found = true;
            }

            yield();
        }
    }

    Serial.println();
    Serial.println("[WIFI] ================================");
    Serial.println("[WIFI] RESEAUX CONFIGURES");
    Serial.println("[WIFI] ================================");

    Serial.print("[WIFI] WIFI1 detecte : ");
    Serial.println(wifi1Found ? "OUI" : "NON");

    Serial.print("[WIFI] WIFI2 detecte : ");
    Serial.println(wifi2Found ? "OUI" : "NON");

    // --------------------------------------------------------
    // WIFI1
    // --------------------------------------------------------

    if (wifi1Found)
    {
        Serial.println();
        Serial.println("[WIFI] ================================");
        Serial.println("[WIFI] TENTATIVE WIFI1");
        Serial.println("[WIFI] ================================");

        if (wifiConnect(WIFI1_SSID, WIFI1_PASSWORD))
        {
            Serial.println("[WIFI] WIFI1 CONNECTE");

            wifiConnected = true;

            Serial.println("[BOOT] wifiInit() END -> WIFI1");

            return;
        }

        Serial.println("[WIFI] WIFI1 ECHEC");
    }
    else
    {
        Serial.println("[WIFI] WIFI1 non detecte");
    }

    // --------------------------------------------------------
    // WIFI2
    // --------------------------------------------------------

    if (wifi2Found)
    {
        Serial.println();
        Serial.println("[WIFI] ================================");
        Serial.println("[WIFI] TENTATIVE WIFI2");
        Serial.println("[WIFI] ================================");

        if (wifiConnect(WIFI2_SSID, WIFI2_PASSWORD))
        {
            Serial.println("[WIFI] WIFI2 CONNECTE");

            wifiConnected = true;

            Serial.println("[BOOT] wifiInit() END -> WIFI2");

            return;
        }

        Serial.println("[WIFI] WIFI2 ECHEC");
    }
    else
    {
        Serial.println("[WIFI] WIFI2 non detecte");
    }

    // --------------------------------------------------------
    // AUCUN WIFI
    // --------------------------------------------------------

    wifiConnected = false;

    Serial.println();
    Serial.println("[WIFI] ================================");
    Serial.println("[WIFI] AUCUNE CONNEXION WIFI");
    Serial.println("[WIFI] ================================");

    Serial.println("[WIFI] Le programme continue sans WiFi");

    Serial.println("[BOOT] wifiInit() END -> OFFLINE");
}

// ============================================================
// MISE A JOUR
// ============================================================

void wifiUpdate()
{
    static unsigned long lastLog = 0;

    unsigned long now = millis();

    if (now - lastLog < 5000)
    {
        return;
    }

    lastLog = now;

    wl_status_t status = WiFi.status();

    bool connected = (status == WL_CONNECTED);

    if (connected != wifiConnected)
    {
        wifiConnected = connected;

        Serial.println();
        Serial.println("[WIFI] CHANGEMENT ETAT");

        Serial.print("[WIFI] status = ");
        Serial.println(wifiStatusText());

        if (wifiConnected)
        {
            Serial.print("[WIFI] IP = ");
            Serial.println(WiFi.localIP());
        }
    }
}

// ============================================================
// ETAT WIFI
// ============================================================

bool wifiIsConnected()
{
    return WiFi.status() == WL_CONNECTED;
}