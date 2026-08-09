#ifndef TOUCH_H
#define TOUCH_H

#include <Arduino.h>

void touchInit();
void touchUpdate();

bool touchPressed();

uint16_t touchGetX();
uint16_t touchGetY();

#endif