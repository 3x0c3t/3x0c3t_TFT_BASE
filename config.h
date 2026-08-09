#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>
#include <TFT_eSPI.h>

// ============================================================
// ECRAN
// ============================================================

#define SCREEN_WIDTH  240
#define SCREEN_HEIGHT 320

#define TFT_ROTATION  2

// ============================================================
// COULEURS
// ============================================================

#define COLOR_BACKGROUND  TFT_BLACK
#define COLOR_TEXT        TFT_WHITE
#define COLOR_PRIMARY     TFT_CYAN
#define COLOR_LINE        TFT_WHITE

#define COLOR_BUTTON      TFT_DARKGREY
#define COLOR_BUTTON_TEXT TFT_WHITE
#define COLOR_OK          TFT_GREEN
#define COLOR_ERROR       TFT_RED
#define COLOR_WARNING     TFT_YELLOW
#define COLOR_INFO        TFT_BLUE

// ============================================================
// HEADER
//
// Y = 0 à 7    : heure / indicateurs
// Y = 8        : ligne
// Y = 9        : progression
// Y = 10       : ligne
// ============================================================

#define HEADER_HEIGHT      11
#define HEADER_LINE_1_Y    8
#define PROGRESS_Y         9
#define PROGRESS_HEIGHT    1
#define HEADER_LINE_2_Y    10

// ============================================================
// TITRE
// ============================================================

#define TITLE_Y             12
#define TITLE_HEIGHT        20
#define TITLE_LINE_Y        32

// ============================================================
// CONTENU
// ============================================================

#define CONTENT_Y           34
#define CONTENT_HEIGHT      250

// ============================================================
// FOOTER
// ============================================================

#define FOOTER_Y            284
#define FOOTER_HEIGHT       36

// ============================================================
// METEO
// ============================================================

#define WEATHER_API_KEY       ""
#define WEATHER_CITY          "Lille"
#define WEATHER_COUNTRY       "FR"
#define WEATHER_REFRESH_TIME  600000UL

// ============================================================
// WIFI
// ============================================================
//
// Laisser vide pour désactiver la tentative de connexion.
//
// Exemple :
//
// #define WIFI_SSID      "MonWifi"
// #define WIFI_PASSWORD  "MotDePasse"
//
// ============================================================

#define WIFI_SSID      ""
#define WIFI_PASSWORD  ""

// ============================================================
// INDICATEURS HEADER
// ============================================================
//
// Nombre maximum d'indicateurs disponibles.
//
// On pourra ensuite en ajouter facilement :
//
// W = WiFi
// S = SD
// T = Touch
// B = Bluetooth
// etc.
//
// ============================================================

#define STATUS_MAX 8

// ============================================================
// TFT
// ============================================================

extern TFT_eSPI tft;

#endif