#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

// ============================================================
// ECRAN TFT
// ============================================================

#define SCREEN_WIDTH   240
#define SCREEN_HEIGHT  320

#define TFT_ROTATION   2

// ============================================================
// COULEURS
// ============================================================

#define COLOR_BACKGROUND   TFT_BLACK
#define COLOR_TEXT         TFT_WHITE

#define COLOR_PRIMARY      TFT_CYAN
#define COLOR_SECONDARY    TFT_BLUE

#define COLOR_LINE         TFT_DARKGREY

#define COLOR_BUTTON       TFT_DARKGREY
#define COLOR_BUTTON_TEXT  TFT_WHITE

#define COLOR_OK            TFT_GREEN
#define COLOR_ERROR         TFT_RED
#define COLOR_WARNING       TFT_YELLOW

// ============================================================
// HEADER
// ============================================================

#define HEADER_LINE_1_Y    10
#define HEADER_LINE_2_Y    11

#define PROGRESS_Y         9

// ============================================================
// TITRE
// ============================================================

#define TITLE_Y            12
#define TITLE_HEIGHT       25
#define TITLE_LINE_Y       37

// ============================================================
// CONTENU
// ============================================================

#define CONTENT_Y          38
#define CONTENT_HEIGHT     237

// ============================================================
// FOOTER
// ============================================================

#define FOOTER_HEIGHT      40
#define FOOTER_Y           (SCREEN_HEIGHT - FOOTER_HEIGHT)

// ============================================================
// WIFI
// ============================================================

// Remplace ces valeurs par ton réseau WiFi.

#define WIFI_SSID          "TON_WIFI"
#define WIFI_PASSWORD      "TON_MOT_DE_PASSE"

// ============================================================
// WIFI
// ============================================================

#define WIFI_TIMEOUT       15000

// ============================================================
// METEO
// ============================================================

#define WEATHER_API_KEY    ""
#define WEATHER_CITY       "Lille"
#define WEATHER_COUNTRY    "FR"

#define WEATHER_REFRESH_TIME  600000UL

// ============================================================
// FIN CONFIG
// ============================================================

#endif