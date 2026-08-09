#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>
#include <TFT_eSPI.h>

// ============================================================
// ECRAN
// ============================================================

#define SCREEN_WIDTH        240
#define SCREEN_HEIGHT       320

#define TFT_ROTATION        2

// ============================================================
// COULEURS GENERALES
// ============================================================

#define COLOR_BACKGROUND    TFT_BLACK
#define COLOR_TEXT          TFT_WHITE
#define COLOR_PRIMARY       TFT_CYAN
#define COLOR_LINE          TFT_DARKGREY

#define COLOR_OK            TFT_GREEN
#define COLOR_ERROR         TFT_RED
#define COLOR_WARNING       TFT_YELLOW

// ============================================================
// BOUTONS
// ============================================================

#define COLOR_BUTTON        TFT_DARKGREY
#define COLOR_BUTTON_TEXT   TFT_WHITE

#define COLOR_BUTTON_UP     TFT_DARKGREY
#define COLOR_BUTTON_DOWN   TFT_DARKGREY
#define COLOR_BUTTON_LEFT   TFT_DARKGREY
#define COLOR_BUTTON_RIGHT  TFT_DARKGREY
#define COLOR_BUTTON_MENU   TFT_DARKGREY

#define COLOR_BUTTON_CANCEL COLOR_ERROR
#define COLOR_BUTTON_OK     COLOR_OK

// ============================================================
// HEADER
// ============================================================

#define HEADER_LINE_1_Y     10

#define PROGRESS_Y          19
#define PROGRESS_HEIGHT     1

#define HEADER_LINE_2_Y     12

#define HEADER_TIME_X       2
#define HEADER_TIME_Y       0

#define COLOR_HEADER_TIME   COLOR_TEXT
#define COLOR_HEADER_STATUS COLOR_LINE
#define COLOR_HEADER_LINE   COLOR_LINE

// Couleur barre de progression
#define COLOR_PROGRESS      COLOR_PRIMARY

// ============================================================
// TITRE
// ============================================================

#define TITLE_Y             13
#define TITLE_HEIGHT        20
#define TITLE_LINE_Y        30

#define COLOR_TITLE_TEXT    COLOR_PRIMARY
#define COLOR_TITLE_LINE    COLOR_LINE

// ============================================================
// CONTENU
// ============================================================

#define CONTENT_Y           47
#define CONTENT_HEIGHT      218

// ============================================================
// FOOTER
// ============================================================

#define FOOTER_HEIGHT       30
#define FOOTER_Y            (SCREEN_HEIGHT - FOOTER_HEIGHT)

// ------------------------------------------------------------
// Bouton MENU
// ------------------------------------------------------------

#define FOOTER_MENU_WIDTH   30
#define FOOTER_MENU_LABEL   "M"

// ------------------------------------------------------------
// Couleurs footer
// ------------------------------------------------------------

#define COLOR_FOOTER_BG       COLOR_BACKGROUND
#define COLOR_FOOTER_LINE     COLOR_LINE

#define COLOR_FOOTER_MENU     COLOR_BUTTON
#define COLOR_FOOTER_MENU_TEXT COLOR_BUTTON_TEXT

// ------------------------------------------------------------
// Zone informations
// ------------------------------------------------------------

#define COLOR_FOOTER_INFO     COLOR_TEXT

// ============================================================
// SPLASH SCREEN
// ============================================================

#define SPLASH_BACKGROUND        COLOR_BACKGROUND

#define SPLASH_TITLE             "3x0c3t TFT BASE"
#define SPLASH_TITLE_COLOR       COLOR_PRIMARY
#define SPLASH_TITLE_Y           105

#define SPLASH_SUBTITLE          "Initialisation..."
#define SPLASH_SUBTITLE_COLOR    COLOR_TEXT
#define SPLASH_SUBTITLE_Y        145

#define SPLASH_VERSION           "v1.0"
#define SPLASH_VERSION_COLOR     COLOR_TEXT
#define SPLASH_VERSION_Y         175

// ------------------------------------------------------------
// Barre de progression Splash
// ------------------------------------------------------------

#define SPLASH_PROGRESS_X        20
#define SPLASH_PROGRESS_Y        205
#define SPLASH_PROGRESS_WIDTH    200
#define SPLASH_PROGRESS_HEIGHT   1

#define SPLASH_PROGRESS_BORDER   COLOR_LINE
#define SPLASH_PROGRESS_COLOR    COLOR_PRIMARY

// ------------------------------------------------------------
// Temps Splash
// ------------------------------------------------------------

#define SPLASH_DURATION          3000
#define SPLASH_UPDATE_INTERVAL   30

// ============================================================
// REGLAGES
// ============================================================

#define SETTINGS_TITLE               "REGLAGES"

// ------------------------------------------------------------
// Couleurs
// ------------------------------------------------------------

#define SETTINGS_TEXT_COLOR          COLOR_TEXT
#define SETTINGS_SELECTED_COLOR      COLOR_PRIMARY
#define SETTINGS_SELECTED_TEXT_COLOR TFT_BLACK
#define SETTINGS_LINE_COLOR          COLOR_LINE

// ------------------------------------------------------------
// Position
// ------------------------------------------------------------

#define SETTINGS_ITEM_X              10
#define SETTINGS_ITEM_START_Y        55
#define SETTINGS_ITEM_HEIGHT         30

#define SETTINGS_VISIBLE_ITEMS       6

// ------------------------------------------------------------
// Elements du menu
// ------------------------------------------------------------

#define SETTINGS_ITEM_WIFI           "WIFI"
#define SETTINGS_ITEM_DISPLAY        "AFFICHAGE"
#define SETTINGS_ITEM_WEATHER        "METEO"
#define SETTINGS_ITEM_SYSTEM         "SYSTEME"

// ============================================================
// WIFI
// ============================================================

#define WIFI_CONNECT_TIMEOUT         15000
#define WIFI_RETRY_INTERVAL          10000

// ============================================================
// METEO
// ============================================================

#define WEATHER_CITY                 "Lille"
#define WEATHER_COUNTRY              "FR"

#define WEATHER_REFRESH_TIME         600000UL

// ============================================================

#endif