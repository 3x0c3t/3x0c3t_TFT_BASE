# 3x0c3t_TFT_BASE

Projet de base pour ESP8266 avec écran TFT SPI 240x320 utilisant le contrôleur ILI9341.

## Matériel

- ESP8266 NodeMCU
- Écran TFT SPI 2.8"
- Résolution 240x320
- Contrôleur ILI9341
- Interface SPI
- Bibliothèque TFT_eSPI

## Fonctionnalités

- Initialisation de l'écran TFT
- Interface graphique 240x320
- En-tête avec heure et date
- Indicateurs d'état
- Barre de progression
- Titre de page
- Zone de contenu
- Barre de navigation
- Boutons HAUT / BAS / GAUCHE / DROITE
- Bouton ANNULER
- Bouton VALIDER
- Gestion de l'affichage météo

## Structure du projet

    3x0c3t_TFT_BASE/
    ├── 3x0c3t_TFT_BASE.ino
    ├── config.h
    ├── display.cpp
    ├── display.h
    ├── weather.cpp
    ├── weather.h
    ├── .gitignore
    └── README.md

## Architecture

Le projet est séparé en plusieurs modules :

### 3x0c3t_TFT_BASE.ino

Programme principal Arduino.

Gère :

- démarrage du système
- initialisation de l'écran
- boucle principale
- gestion générale de l'interface

### config.h

Configuration générale du projet :

- résolution TFT
- rotation
- couleurs
- positions
- dimensions
- paramètres météo
- paramètres d'affichage

### display.cpp / display.h

Gestion de l'interface graphique :

- écran
- header
- date et heure
- indicateurs d'état
- progression
- titre
- contenu
- footer
- boutons
- texte centré

### weather.cpp / weather.h

Gestion de l'affichage et de la récupération des données météo.

## Interface

L'écran est organisé approximativement comme ceci :

    ┌──────────────────────────────┐
    │ Heure / Date          ■■■■   │
    │──────────────────────────────│
    │████████████                  │
    │──────────────────────────────│
    │                              │
    │            TITRE             │
    │──────────────────────────────│
    │                              │
    │                              │
    │           CONTENU            │
    │                              │
    │                              │
    │──────────────────────────────│
    │ HAUT │ BAS │ G │ D │ X │ V   │
    └──────────────────────────────┘

## Bibliothèques

Bibliothèque principale :

- TFT_eSPI

Selon la configuration utilisée, le projet peut également utiliser :

- ESP8266WiFi
- ESP8266HTTPClient
- ArduinoJson

## Configuration TFT_eSPI

La configuration des broches SPI et du contrôleur ILI9341 doit être adaptée à la carte utilisée.

Le projet est prévu pour un écran :

    Driver : ILI9341
    Bus    : SPI
    Width  : 240
    Height : 320

## Version

Version actuelle :

    v1.0

Branche Git :

    v1.0

## Développement

Ce dépôt sert de base expérimentale pour les futurs projets TFT de 3x0c3t.

Les nouvelles fonctionnalités peuvent être développées et testées dans ce projet avant leur intégration dans le projet principal.

## Auteur

3x0c3t

GitHub :

https://github.com/3x0c3t

## Licence

Projet personnel 3x0c3t.
