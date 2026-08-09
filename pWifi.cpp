#include "pWifi.h"

#include <ESP8266WiFi.h>

#include "config.h"
#include "display.h"
#include "pages.h"
#include "wifi.h"

// ============================================================
// ETAT
// ============================================================

static int wifiIndex = 0;

// ============================================================
// INITIALISATION
// ============================================================

void pWifiInit()
{
wifiIndex = 0;
}

// ============================================================
// AFFICHAGE
// ============================================================

void pWifiShow()
{
tft.fillRect(
0,
CONTENT_Y,
SCREEN_WIDTH,
CONTENT_HEIGHT,
COLOR_BACKGROUND
);

drawTitle("WIFI");

tft.setTextFont(1);
tft.setTextSize(1);
tft.setTextDatum(TL_DATUM);

// --------------------------------------------------------
// Etat
// --------------------------------------------------------

tft.setTextColor(
    COLOR_TEXT,
    COLOR_BACKGROUND
);

tft.drawString(
    "Etat WiFi",
    10,
    CONTENT_Y + 15
);

// --------------------------------------------------------
// Connexion
// --------------------------------------------------------

if (WiFi.status() == WL_CONNECTED)
{
    tft.setTextColor(
        COLOR_OK,
        COLOR_BACKGROUND
    );

    tft.drawString(
        "CONNECTE",
        10,
        CONTENT_Y + 35
    );

    // ----------------------------------------------------
    // SSID
    // ----------------------------------------------------

    tft.setTextColor(
        COLOR_TEXT,
        COLOR_BACKGROUND
    );

    tft.drawString(
        "SSID : " + WiFi.SSID(),
        10,
        CONTENT_Y + 55
    );

    // ----------------------------------------------------
    // Adresse IP
    // ----------------------------------------------------

    tft.drawString(
        "IP : " + WiFi.localIP().toString(),
        10,
        CONTENT_Y + 75
    );

    // ----------------------------------------------------
    // RSSI
    // ----------------------------------------------------

    tft.drawString(
        "Signal : " + String(WiFi.RSSI()) + " dBm",
        10,
        CONTENT_Y + 95
    );
}
else
{
    tft.setTextColor(
        COLOR_ERROR,
        COLOR_BACKGROUND
    );

    tft.drawString(
        "DECONNECTE",
        10,
        CONTENT_Y + 35
    );
}

// --------------------------------------------------------
// Commandes
// --------------------------------------------------------

tft.setTextColor(
    COLOR_TEXT,
    COLOR_BACKGROUND
);

tft.drawString(
    "OK : actualiser",
    10,
    CONTENT_Y + 125
);

tft.drawString(
    "CANCEL : retour",
    10,
    CONTENT_Y + 140
);

}

// ============================================================
// UPDATE
// ============================================================

void pWifiUpdate()
{
// Pas de rafraichissement automatique
}

// ============================================================
// BOUTON HAUT
// ============================================================

void pWifiButtonUp()
{
wifiIndex--;

if (wifiIndex < 0)
{
    wifiIndex = 0;
}

pWifiShow();

}

// ============================================================
// BOUTON BAS
// ============================================================

void pWifiButtonDown()
{
wifiIndex++;

if (wifiIndex > 0)
{
    wifiIndex = 0;
}

pWifiShow();

}

// ============================================================
// BOUTON GAUCHE
// ============================================================

void pWifiButtonLeft()
{
}

// ============================================================
// BOUTON DROITE
// ============================================================

void pWifiButtonRight()
{
}

// ============================================================
// BOUTON OK
// ============================================================

void pWifiButtonOk()
{
pWifiShow();
}

// ============================================================
// BOUTON CANCEL
// ============================================================

void pWifiButtonCancel()
{
pagesMain();
}
