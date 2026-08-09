#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

// ============================================================
// ECRAN
// ============================================================

#define SCREEN_WIDTH  240
#define SCREEN_HEIGHT 320

#define TFT_ROTATION 2

// ============================================================
// COULEURS GENERALES
// ============================================================

#define COLOR_BACKGROUND   TFT_BLACK
#define COLOR_TEXT         TFT_WHITE
#define COLOR_PRIMARY      TFT_CYAN
#define COLOR_LINE         TFT_DARKGREY

// ============================================================
// HEADER
// ============================================================

// Ligne supérieure
#define HEADER_LINE_1_Y    10

// Barre de progression
// EXACTEMENT 1 PIXEL DE HAUTEUR
#define PROGRESS_Y         19
#define PROGRESS_HEIGHT    1

// Ligne inférieure
#define HEADER_LINE_2_Y    12

// Position heure
#define HEADER_TIME_X      2
#define HEADER_TIME_Y      0

// ============================================================
// COULEURS HEADER
// ============================================================

#define COLOR_HEADER_TIME      COLOR_TEXT
#define COLOR_HEADER_STATUS    COLOR_PRIMARY
#define COLOR_HEADER_LINE      COLOR_LINE
#define COLOR_PROGRESS         COLOR_PRIMARY

// ============================================================
// TITRE
// ============================================================

#define TITLE_Y          13
#define TITLE_HEIGHT     20
#define TITLE_LINE_Y     30

#define COLOR_TITLE_TEXT      COLOR_PRIMARY
#define COLOR_TITLE_LINE      COLOR_LINE

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
// COULEURS FOOTER
// ============================================================

#define COLOR_FOOTER_BG       COLOR_BACKGROUND
#define COLOR_FOOTER_LINE     COLOR_LINE

// ============================================================
// BOUTONS
// ============================================================

// Couleur générale
#define COLOR_BUTTON          TFT_DARKGREY
#define COLOR_BUTTON_TEXT     TFT_WHITE

// Flèches
#define COLOR_BUTTON_UP       TFT_DARKGREY
#define COLOR_BUTTON_DOWN     TFT_DARKGREY
#define COLOR_BUTTON_LEFT     TFT_DARKGREY
#define COLOR_BUTTON_RIGHT    TFT_DARKGREY

// Menu
#define COLOR_BUTTON_MENU     TFT_BLUE

// Annuler
#define COLOR_BUTTON_CANCEL   TFT_RED

// Valider
#define COLOR_BUTTON_OK       TFT_GREEN

// ============================================================
// ETATS
// ============================================================

#define COLOR_OK              TFT_GREEN
#define COLOR_ERROR           TFT_RED
#define COLOR_WARNING         TFT_YELLOW

// ============================================================
// WIFI
// ============================================================

#define WIFI_CONNECT_TIMEOUT  15000
#define WIFI_RETRY_INTERVAL   10000

// ============================================================
// METEO
// ============================================================

#define WEATHER_CITY            "Lille"
#define WEATHER_COUNTRY         "FR"

#define WEATHER_REFRESH_TIME    600000UL

// ============================================================
// SPLASH SCREEN
// ============================================================

// Fond
#define SPLASH_BACKGROUND          COLOR_BACKGROUND

// Texte principal
#define SPLASH_TITLE               "3x0c3t"
#define SPLASH_TITLE_COLOR         COLOR_PRIMARY
#define SPLASH_TITLE_Y             105

// Sous-titre
#define SPLASH_SUBTITLE            "TFT BASE"
#define SPLASH_SUBTITLE_COLOR      COLOR_TEXT
#define SPLASH_SUBTITLE_Y          145

// Version
#define SPLASH_VERSION             "V1.0"
#define SPLASH_VERSION_COLOR       COLOR_TEXT
#define SPLASH_VERSION_Y           175

// ============================================================
// SPLASH SCREEN
// ============================================================

// Durée totale d'affichage du splash en millisecondes
#define SPLASH_DURATION          3000UL

// Fréquence de mise à jour de la barre
#define SPLASH_UPDATE_INTERVAL   20UL

// Fond
#define SPLASH_BACKGROUND        TFT_BLACK

// Texte principal
#define SPLASH_TITLE             "3x0c3t"
#define SPLASH_TITLE_COLOR       TFT_CYAN
#define SPLASH_TITLE_Y           125

// Sous-titre
#define SPLASH_SUBTITLE          "TFT BASE"
#define SPLASH_SUBTITLE_COLOR    TFT_WHITE
#define SPLASH_SUBTITLE_Y        155

// Version
#define SPLASH_VERSION           "V1.0"
#define SPLASH_VERSION_COLOR     TFT_DARKGREY
#define SPLASH_VERSION_Y         180

// Barre de progression
#define SPLASH_PROGRESS_X        20
#define SPLASH_PROGRESS_Y        220
#define SPLASH_PROGRESS_WIDTH    200
#define SPLASH_PROGRESS_HEIGHT   1

#define SPLASH_PROGRESS_BORDER   TFT_DARKGREY
#define SPLASH_PROGRESS_COLOR    TFT_CYAN

#endif