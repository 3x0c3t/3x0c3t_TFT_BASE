#ifndef CLOCK_H
#define CLOCK_H

#include <Arduino.h>

void clockInit();

bool clockIsValid();

void clockUpdate();

String clockGetString();

#endif