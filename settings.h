#ifndef SETTINGS_H
#define SETTINGS_H

#include <Arduino.h>

// ============================================================
// PAGE REGLAGES
// ============================================================

void settingsInit();

void settingsShow();

void settingsUpdate();

// ============================================================
// NAVIGATION
// ============================================================

void settingsButtonUp();

void settingsButtonDown();

void settingsButtonLeft();

void settingsButtonRight();

void settingsButtonMenu();

void settingsButtonCancel();

void settingsButtonOk();

// ============================================================
// ETAT
// ============================================================

int settingsGetIndex();

#endif