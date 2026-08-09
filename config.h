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

// Fond général
#define COLOR_BUTTON_BG             TFT_DARKGREY

// Contour général
#define COLOR_BUTTON_BORDER         TFT_WHITE

// Texte
#define COLOR_BUTTON_TEXT           TFT_WHITE

// Boutons directionnels
#define COLOR_BUTTON_UP             COLOR_BUTTON_BG
#define COLOR_BUTTON_DOWN           COLOR_BUTTON_BG
#define COLOR_BUTTON_LEFT           COLOR_BUTTON_BG
#define COLOR_BUTTON_RIGHT          COLOR_BUTTON_BG

// Bouton MENU
#define COLOR_BUTTON_MENU           COLOR_BUTTON_BG

// Bouton OK
#define COLOR_BUTTON_OK_BG          COLOR_OK
#define COLOR_BUTTON_OK_BORDER      COLOR_OK
#define COLOR_BUTTON_OK_TEXT        TFT_BLACK

// Bouton CANCEL
#define COLOR_BUTTON_CANCEL_BG      COLOR_ERROR
#define COLOR_BUTTON_CANCEL_BORDER  COLOR_ERROR
#define COLOR_BUTTON_CANCEL_TEXT    TFT_WHITE

// Compatibilité ancien code
#define COLOR_BUTTON               COLOR_BUTTON_BG
#define COLOR_BUTTON_OK            COLOR_BUTTON_OK_BG
#define COLOR_BUTTON_CANCEL        COLOR_BUTTON_CANCEL_BG

// ============================================================
// HEADER
// ============================================================

// Première ligne horizontale
#define HEADER_LINE_1_Y      10

// Barre de progression
#define PROGRESS_Y           19
#define PROGRESS_HEIGHT      1
#define COLOR_PROGRESS       COLOR_PRIMARY

// Deuxième ligne horizontale
#define HEADER_LINE_2_Y      12

// Heure
#define HEADER_TIME_X        2
#define HEADER_TIME_Y        0

// Couleurs Header
#define COLOR_HEADER_TIME    COLOR_TEXT
#define COLOR_HEADER_STATUS  COLOR_LINE
#define COLOR_HEADER_LINE    COLOR_LINE

// ============================================================
// TITRE
// ============================================================

#define TITLE_Y              13
#define TITLE_HEIGHT         20
#define TITLE_LINE_Y         30

#define COLOR_TITLE_TEXT     COLOR_PRIMARY
#define COLOR_TITLE_LINE     COLOR_LINE

// ============================================================
// CONTENU
// ============================================================

#define CONTENT_Y            47
#define CONTENT_HEIGHT       218

// ============================================================
// PAGE MAIN
// ============================================================

#define HOME_TITLE                  "-3xØc3t- BO4RD"

#define HOME_BUTTON_X               20

#define HOME_BUTTON_WIDTH           200
#define HOME_BUTTON_HEIGHT          50

#define HOME_BUTTON_METEO_Y         80
#define HOME_BUTTON_WIFI_Y          150

#define HOME_BUTTON_BG              COLOR_BUTTON_BG
#define HOME_BUTTON_BORDER          COLOR_BUTTON_BORDER
#define HOME_BUTTON_TEXT            COLOR_BUTTON_TEXT

// ============================================================
// FOOTER
// ============================================================

#define FOOTER_HEIGHT        20
#define FOOTER_Y             (SCREEN_HEIGHT - FOOTER_HEIGHT)

// ------------------------------------------------------------
// Bouton MENU
// ------------------------------------------------------------

#define FOOTER_MENU_WIDTH        30

#define FOOTER_MENU_ICON_SIZE    14
#define FOOTER_MENU_ICON_RADIUS  3
#define FOOTER_MENU_ICON_LINE    2

// ------------------------------------------------------------
// Couleurs footer
// ------------------------------------------------------------

#define COLOR_FOOTER_BG              COLOR_BACKGROUND
#define COLOR_FOOTER_LINE            COLOR_LINE

#define COLOR_FOOTER_MENU_BG         COLOR_BUTTON_BG
#define COLOR_FOOTER_MENU_BORDER     COLOR_BUTTON_BORDER
#define COLOR_FOOTER_MENU_TEXT       COLOR_BUTTON_TEXT

// Compatibilité ancien code
#define COLOR_FOOTER_MENU            COLOR_FOOTER_MENU_BG
#define COLOR_FOOTER_MENU_LINE       COLOR_FOOTER_MENU_BORDER
#define COLOR_FOOTER_INFO            COLOR_TEXT

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

#define SPLASH_PROGRESS_X        0
#define SPLASH_PROGRESS_Y        PROGRESS_Y
#define SPLASH_PROGRESS_WIDTH    SCREEN_WIDTH
#define SPLASH_PROGRESS_HEIGHT   PROGRESS_HEIGHT

#define SPLASH_PROGRESS_BORDER   COLOR_LINE
#define SPLASH_PROGRESS_COLOR    COLOR_PROGRESS

// ------------------------------------------------------------
// Temps Splash
// ------------------------------------------------------------

#define SPLASH_DURATION          3000
#define SPLASH_UPDATE_INTERVAL   30

// ============================================================
// REGLAGES
// ============================================================

#define SETTINGS_TITLE               "REGLAGES"

#define SETTINGS_TEXT_COLOR          COLOR_TEXT
#define SETTINGS_SELECTED_COLOR      COLOR_PRIMARY
#define SETTINGS_SELECTED_TEXT_COLOR TFT_BLACK
#define SETTINGS_LINE_COLOR          COLOR_LINE

#define SETTINGS_ITEM_X              10
#define SETTINGS_ITEM_START_Y        55
#define SETTINGS_ITEM_HEIGHT         30

#define SETTINGS_VISIBLE_ITEMS       6

#define SETTINGS_ITEM_WIFI           "WIFI"
#define SETTINGS_ITEM_DISPLAY       "AFFICHAGE"
#define SETTINGS_ITEM_WEATHER       "METEO"
#define SETTINGS_ITEM_SYSTEM        "SYSTEME"

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

#endif
