#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

// ============================================================
// ECRAN
// ============================================================

#define SCREEN_WIDTH  240
#define SCREEN_HEIGHT 320

#define TFT_ROTATION 1

// ============================================================
// COULEURS
// ============================================================

#define COLOR_BACKGROUND   TFT_BLACK
#define COLOR_TEXT         TFT_WHITE
#define COLOR_PRIMARY      TFT_CYAN
#define COLOR_LINE         TFT_DARKGREY

#define COLOR_BUTTON       TFT_DARKGREY
#define COLOR_BUTTON_TEXT  TFT_WHITE

#define COLOR_OK            TFT_GREEN
#define COLOR_ERROR         TFT_RED
#define COLOR_WARNING       TFT_YELLOW

// ============================================================
// HEADER
// ============================================================

#define HEADER_LINE_1_Y  18
#define HEADER_LINE_2_Y  20

#define PROGRESS_Y       19

// ============================================================
// TITRE
// ============================================================

#define TITLE_Y          22
#define TITLE_HEIGHT     24
#define TITLE_LINE_Y     46

// ============================================================
// CONTENU
// ============================================================

#define CONTENT_Y        47
#define CONTENT_HEIGHT   218

// ============================================================
// FOOTER
// ============================================================

#define FOOTER_HEIGHT    30
#define FOOTER_Y         (SCREEN_HEIGHT - FOOTER_HEIGHT)

// ============================================================
// WIFI
// ============================================================

#define WIFI_CONNECT_TIMEOUT 15000
#define WIFI_RETRY_INTERVAL  10000

// ============================================================
// METEO
// ============================================================

#define WEATHER_CITY       "Lille"
#define WEATHER_COUNTRY    "FR"

#define WEATHER_REFRESH_TIME 600000UL

#endif