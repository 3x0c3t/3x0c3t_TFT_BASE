#include "pages.h"

#include "display.h"
#include "weather.h"
#include "wifi.h"
#include "config.h"

static PageID currentPage = PAGE_HOME;

void pagesInit()
{
    currentPage = PAGE_HOME;
    pagesShow(currentPage);
}

PageID pagesCurrent()
{
    return currentPage;
}

void pagesShow(PageID page)
{
    if (page >= PAGE_COUNT)
    {
        page = PAGE_HOME;
    }

    currentPage = page;

    drawInterface(
        page == PAGE_HOME   ? "ACCUEIL" :
        page == PAGE_METEO  ? "METEO" :
        page == PAGE_WIFI   ? "WIFI" :
                              "SYSTEME"
    );

    clearContent();

    switch (currentPage)
    {
        case PAGE_HOME:

            centerText(
                "3x0c3t TFT BASE",
                100,
                2,
                COLOR_PRIMARY
            );

            centerText(
                "ACCUEIL",
                130,
                1,
                COLOR_TEXT
            );

            break;


        case PAGE_METEO:

            drawWeather(
                10,
                CONTENT_Y + 10
            );

            break;


        case PAGE_WIFI:

            centerText(
                "WIFI",
                CONTENT_Y + 30,
                2,
                COLOR_PRIMARY
            );

            break;


        case PAGE_SYSTEME:

            centerText(
                "SYSTEME",
                CONTENT_Y + 30,
                2,
                COLOR_PRIMARY
            );

            centerText(
                "ESP8266",
                CONTENT_Y + 60,
                1,
                COLOR_TEXT
            );

            break;
    }
}

void pagesNext()
{
    int next =
        (int)currentPage + 1;

    if (next >= PAGE_COUNT)
    {
        next = 0;
    }

    pagesShow(
        (PageID)next
    );
}

void pagesPrevious()
{
    int previous =
        (int)currentPage - 1;

    if (previous < 0)
    {
        previous = PAGE_COUNT - 1;
    }

    pagesShow(
        (PageID)previous
    );
}