#ifndef PAGES_H
#define PAGES_H

#include <Arduino.h>

enum PageID
{
    PAGE_HOME = 0,
    PAGE_METEO,
    PAGE_WIFI,
    PAGE_SYSTEME,
    PAGE_COUNT
};

void pagesInit();
void pagesShow(PageID page);
void pagesNext();
void pagesPrevious();

PageID pagesCurrent();

#endifages