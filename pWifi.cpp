#include "pWifi.h"
#include "pages.h"
#include "config.h"
#include "display.h"

#include <Arduino.h>
#include <TFT_eSPI.h>
#include <ESP8266WiFi.h>

// ============================================================
// ETAT
// ============================================================

static bool wifiPageInitialized = false;

// ============================================================
// INITIALISATION
// ============================================================

void pWifiInit()
{
    wifiPageInitialized = true;
}

// ============================================================
// AFFICHAGE
// ============================================================

void pWifiShow()
{
    // Nettoyage uniquement de la zone contenu.
    // Le header reste intact.

    tft.fillRect(
        0,
        CONTENT_Y,
        SCREEN_WIDTH,
        CONTENT_HEIGHT,
        COLOR_BACKGROUND
    );

    drawTitle("WIFI");

    tft.setTextColor(COLOR_TEXT);
    tft.setTextSize(1);

    int y = CONTENT_Y + 10;

    // --------------------------------------------------------
    // TITRE
    // --------------------------------------------------------

    tft.setCursor(10, y);
    tft.print("WIFI");

    y += 18;

    // --------------------------------------------------------
    // SSID
    // --------------------------------------------------------

    tft.setCursor(10, y);
    tft.print("SSID : ");

    if (WiFi.status() == WL_CONNECTED)
    {
        tft.print(WiFi.SSID());
    }
    else
    {
        tft.print("Non connecte");
    }

    y += 18;

    // --------------------------------------------------------
    // ETAT
    // --------------------------------------------------------

    tft.setCursor(10, y);
    tft.print("Etat : ");

    if (WiFi.status() == WL_CONNECTED)
    {
        tft.print("CONNECTE");
    }
    else
    {
        tft.print("DECONNECTE");
    }

    // --------------------------------------------------------
    // INFORMATIONS WIFI
    // --------------------------------------------------------

    if (WiFi.status() == WL_CONNECTED)
    {
        y += 18;

        tft.setCursor(10, y);
        tft.print("IP : ");
        tft.print(WiFi.localIP());

        y += 18;

        tft.setCursor(10, y);
        tft.print("RSSI : ");
        tft.print(WiFi.RSSI());
        tft.print(" dBm");
    }
}

// ============================================================
// MISE A JOUR
// ============================================================

void pWifiUpdate()
{
    // Rien pour le moment.
}

// ============================================================
// BOUTON UP
// ============================================================

void pWifiButtonUp()
{
    // Rien pour le moment.
}

// ============================================================
// BOUTON DOWN
// ============================================================

void pWifiButtonDown()
{
    // Rien pour le moment.
}

// ============================================================
// BOUTON LEFT
// ============================================================

void pWifiButtonLeft()
{
    // Rien pour le moment.
}

// ============================================================
// BOUTON RIGHT
// ============================================================

void pWifiButtonRight()
{
    // Rien pour le moment.
}

// ============================================================
// BOUTON OK
// ============================================================

void pWifiButtonOk()
{
    // Rien pour le moment.
}

// ============================================================
// BOUTON CANCEL
// ============================================================

void pWifiButtonCancel()
{
    // Retour vers la page principale.
    pagesShow(PAGE_MAIN);
}