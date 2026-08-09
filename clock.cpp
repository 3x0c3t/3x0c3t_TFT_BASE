#include "clock.h"

#include <time.h>
#include <sys/time.h>

// ============================================================
// CONFIGURATION NTP
// ============================================================

static const char* NTP_SERVER_1 = "pool.ntp.org";
static const char* NTP_SERVER_2 = "time.nist.gov";
static const char* NTP_SERVER_3 = "time.google.com";

// ============================================================
// ETAT
// ============================================================

static bool clockInitialized = false;
static bool clockValid = false;

// ============================================================
// INITIALISATION
// ============================================================

void clockInit()
{
    Serial.println();
    Serial.println("================================");
    Serial.println("[CLOCK] INITIALISATION");
    Serial.println("================================");

    // ========================================================
    // FUSEAU HORAIRE FRANCE
    //
    // CET  = UTC+1
    // CEST = UTC+2
    //
    // Passage heure ete :
    // dernier dimanche de mars
    //
    // Passage heure hiver :
    // dernier dimanche d'octobre
    // ========================================================

    setenv(
        "TZ",
        "CET-1CEST,M3.5.0,M10.5.0",
        1
    );

    tzset();

    // ========================================================
    // SERVEURS NTP
    // ========================================================

    configTime(
        0,
        0,
        NTP_SERVER_1,
        NTP_SERVER_2,
        NTP_SERVER_3
    );

    clockInitialized = true;

    Serial.println("[CLOCK] NTP configure");

    Serial.print("[CLOCK] Serveur 1 : ");
    Serial.println(NTP_SERVER_1);

    Serial.print("[CLOCK] Serveur 2 : ");
    Serial.println(NTP_SERVER_2);

    Serial.print("[CLOCK] Serveur 3 : ");
    Serial.println(NTP_SERVER_3);
}

// ============================================================
// VERIFICATION
// ============================================================

bool clockIsValid()
{
    time_t now = time(nullptr);

    // Une date inferieure a 2020 indique que
    // la synchronisation NTP n'est pas encore faite.

    if (now < 1577836800)
    {
        return false;
    }

    return true;
}

// ============================================================
// MISE A JOUR
// ============================================================

void clockUpdate()
{
    if (!clockInitialized)
    {
        return;
    }

    bool valid =
        clockIsValid();

    if (valid && !clockValid)
    {
        clockValid = true;

        Serial.println();
        Serial.println("[CLOCK] Synchronisation NTP OK");

        Serial.print("[CLOCK] Heure : ");
        Serial.println(
            clockGetString()
        );
    }

    if (!valid && clockValid)
    {
        clockValid = false;

        Serial.println(
            "[CLOCK] Synchronisation perdue"
        );
    }
}

// ============================================================
// FORMAT HEURE
// ============================================================

String clockGetString()
{
    time_t now =
        time(nullptr);

    if (now < 1577836800)
    {
        return "--:--:-- - ----/--/--";
    }

    struct tm timeinfo;

    localtime_r(
        &now,
        &timeinfo
    );

    char buffer[32];

    snprintf(
        buffer,
        sizeof(buffer),
        "%02d:%02d:%02d - %04d/%02d/%02d",
        timeinfo.tm_hour,
        timeinfo.tm_min,
        timeinfo.tm_sec,
        timeinfo.tm_year + 1900,
        timeinfo.tm_mon + 1,
        timeinfo.tm_mday
    );

    return String(buffer);
}