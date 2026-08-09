#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

// ============================================================
// ECRAN
// ============================================================

#define SCREEN_WIDTH   240
#define SCREEN_HEIGHT  320

#define TFT_ROTATION   2


// ============================================================
// COULEURS GENERALES
// ============================================================

#define COLOR_BACKGROUND     TFT_BLACK
#define COLOR_TEXT           TFT_WHITE
#define COLOR_PRIMARY        TFT_CYAN
#define COLOR_LINE           TFT_DARKGREY


// ============================================================
// COULEURS HEADER
// ============================================================

#define COLOR_HEADER_TIME    TFT_WHITE
#define COLOR_HEADER_LINE    TFT_DARKGREY
#define COLOR_HEADER_STATUS  TFT_DARKGREY
#define COLOR_PROGRESS       TFT_CYAN


// ============================================================
// COULEURS TITRE
// ============================================================

#define COLOR_TITLE_TEXT     TFT_CYAN
#define COLOR_TITLE_LINE     TFT_DARKGREY


// ============================================================
// COULEURS CONTENU
// ============================================================

#define COLOR_CONTENT_TEXT   TFT_WHITE
#define COLOR_CONTENT_VALUE  TFT_CYAN
#define COLOR_CONTENT_LINE   TFT_DARKGREY


// ============================================================
// COULEURS FOOTER
// ============================================================

#define COLOR_FOOTER_BG      TFT_BLACK
#define COLOR_FOOTER_LINE    TFT_DARKGREY

#define COLOR_BUTTON         TFT_DARKGREY
#define COLOR_BUTTON_TEXT    TFT_WHITE

#define COLOR_BUTTON_UP      TFT_DARKGREY
#define COLOR_BUTTON_DOWN    TFT_DARKGREY
#define COLOR_BUTTON_LEFT    TFT_DARKGREY
#define COLOR_BUTTON_RIGHT   TFT_DARKGREY

#define COLOR_BUTTON_MENU    TFT_DARKGREY
#define COLOR_BUTTON_CANCEL  TFT_RED
#define COLOR_BUTTON_OK      TFT_GREEN


// ============================================================
// COULEURS STATUT
// ============================================================

#define COLOR_OK             TFT_GREEN
#define COLOR_ERROR          TFT_RED
#define COLOR_WARNING        TFT_YELLOW


// ============================================================
// HEADER
// ============================================================

// Heure
#define HEADER_TIME_X        2
#define HEADER_TIME_Y        0

// Première ligne
#define HEADER_LINE_1_Y      10

// Barre de progression
// IMPORTANT : hauteur exactement 1 pixel
#define PROGRESS_Y           11
#define PROGRESS_HEIGHT      1

// Deuxième ligne
#define HEADER_LINE_2_Y      12


// ============================================================
// TITRE
// ============================================================

// On gagne quelques pixels en remontant le titre
#define TITLE_Y              13
#define TITLE_HEIGHT         17
#define TITLE_LINE_Y         29


// ============================================================
// CONTENU
// ============================================================

#define CONTENT_Y            31
#define CONTENT_HEIGHT       228


// ============================================================
// FOOTER
// ============================================================

#define FOOTER_HEIGHT        30
#define FOOTER_Y             (SCREEN_HEIGHT - FOOTER_HEIGHT)


// ============================================================
// WIFI
// ============================================================

#define WIFI_CONNECT_TIMEOUT 15000UL
#define WIFI_RETRY_INTERVAL  10000UL


// ============================================================
// METEO
// ============================================================

#define WEATHER_CITY          "Lille"
#define WEATHER_COUNTRY       "FR"

#define WEATHER_REFRESH_TIME  600000UL

#endif