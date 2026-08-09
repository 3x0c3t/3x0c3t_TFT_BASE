#ifndef PSYSTEM_H
#define PSYSTEM_H

#include <Arduino.h>

void pSystemInit();
void pSystemShow();
void pSystemUpdate();

void pSystemButtonUp();
void pSystemButtonDown();
void pSystemButtonLeft();
void pSystemButtonRight();
void pSystemButtonOk();
void pSystemButtonCancel();
void pSystemButtonMenu();

#endif