#ifndef CONFIG_H
#define CONFIG_H

// ============================================================
// ECRAN
// ============================================================

#define SCREEN_WIDTH  240
#define SCREEN_HEIGHT 320

#define TFT_ROTATION 2

// ============================================================
// COULEURS
// ============================================================

#define COLOR_BACKGROUND  TFT_BLACK
#define COLOR_TEXT        TFT_WHITE
#define COLOR_PRIMARY     TFT_CYAN
#define COLOR_LINE        TFT_DARKGREY
#define COLOR_BUTTON      TFT_DARKGREY
#define COLOR_BUTTON_TEXT TFT_WHITE
#define COLOR_OK          TFT_GREEN
#define COLOR_ERROR       TFT_RED
#define COLOR_WARNING     TFT_YELLOW

// ============================================================
// INTERFACE
// ============================================================

#define HEADER_LINE_1_Y 10
#define HEADER_LINE_2_Y 20

#define PROGRESS_Y 21

#define TITLE_Y       22
#define TITLE_HEIGHT  25
#define TITLE_LINE_Y  47

#define CONTENT_Y       48
#define CONTENT_HEIGHT  242

#define FOOTER_Y       291
#define FOOTER_HEIGHT  20

// ============================================================
// WIFI
// ============================================================

#define WIFI_CONNECT_TIMEOUT 15000UL
#define WIFI_RETRY_INTERVAL  30000UL

// ============================================================
// HORLOGE / NTP
// ============================================================

#define CLOCK_GMT_OFFSET      3600
#define CLOCK_DAYLIGHT_OFFSET 3600

#define CLOCK_NTP_SERVER_1 "pool.ntp.org"
#define CLOCK_NTP_SERVER_2 "time.nist.gov"

// ============================================================
// METEO
// ============================================================

#define WEATHER_CITY    "Lille"
#define WEATHER_COUNTRY "FR"

#define WEATHER_REFRESH_TIME 600000UL

#endif