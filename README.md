# 3x0c3t_TFT_BASE

Base logicielle pour écran TFT SPI 240×320 piloté par ESP8266 NodeMCU.

Le projet sert de **socle de développement pour l'interface graphique du 3x0c3t_BO4RD**.

L'objectif est de disposer d'une architecture simple, modulaire et facilement extensible pour ajouter progressivement des écrans, des fonctions, des capteurs et des services réseau.

---

## Matériel

### Contrôleur

* ESP8266
* NodeMCU 1.0 (ESP-12E Module)

### Écran

* TFT SPI
* 2.8"
* Résolution : 240 × 320 pixels
* Contrôleur : ILI9341
* Interface : SPI
* Tactile prévu : XPT2046

### Bibliothèque graphique

Le projet utilise :

* TFT_eSPI

---

## Architecture

Le projet est organisé en modules indépendants.

```text
3x0c3t_TFT_BASE/
│
├── 3x0c3t_TFT_BASE.ino
│
├── config.h
│
├── display.h
├── display.cpp
│
├── wifi.h
├── wifi.cpp
│
├── weather.h
├── weather.cpp
│
├── splash.h
├── splash.cpp
│
└── README.md
```

### `3x0c3t_TFT_BASE.ino`

Programme principal.

Il assure notamment :

* l'initialisation du système
* l'initialisation de l'affichage
* l'initialisation du WiFi
* l'initialisation de la météo
* l'exécution de la boucle principale
* les mises à jour périodiques

---

### `config.h`

Centralise les paramètres du projet.

On y retrouve notamment :

* résolution de l'écran
* rotation TFT
* couleurs
* dimensions du header
* position de la barre de progression
* dimensions du titre
* zone de contenu
* footer
* paramètres WiFi
* paramètres météo
* paramètres du splash screen

L'objectif est d'éviter de modifier directement les fichiers de fonctionnement pour modifier l'apparence ou les temporisations.

---

### `display.cpp / display.h`

Gestion de l'interface graphique.

Fonctions principales :

```cpp
displayInit()
drawInterface()
drawHeader()
drawHeaderTime()
drawStatusSquares()
drawProgressBar()
setProgress()
drawTitle()
clearContent()
drawFooter()
drawButton()
centerText()
setStatus()
```

---

### `wifi.cpp / wifi.h`

Gestion de la connexion WiFi.

Le système utilise deux réseaux configurables :

```text
WIFI1
WIFI2
```

Le comportement prévu est :

```text
Démarrage
   │
   ▼
Recherche WIFI1
   │
   ├── disponible → connexion WIFI1
   │
   └── indisponible
          │
          ▼
      Recherche WIFI2
          │
          ├── disponible → connexion WIFI2
          │
          └── indisponible
                 │
                 ▼
          Aucun réseau disponible
```

Cela permet notamment d'utiliser automatiquement un réseau principal et un réseau de secours.

---

### `weather.cpp / weather.h`

Gestion de la météo via OpenWeatherMap.

Les données récupérées comprennent notamment :

* température
* température ressentie
* température minimale
* température maximale
* humidité
* pression atmosphérique
* description météo

La ville et le pays sont configurables dans `config.h`.

---

### `splash.cpp / splash.h`

Gestion de l'écran de démarrage.

Le splash screen est affiché au démarrage avant l'interface principale.

Il comprend :

* fond
* titre
* sous-titre
* version
* barre de progression
* progression pendant le chargement

La durée d'affichage est configurable dans `config.h`.

Le principe est :

```text
BOOT
 │
 ▼
Splash screen
 │
 ├── progression 0 %
 ├── progression 25 %
 ├── progression 50 %
 ├── progression 75 %
 └── progression 100 %
 │
 ▼
Interface principale
```

---

# Interface graphique

L'interface est conçue pour exploiter au maximum les 320 pixels de hauteur.

## Structure

```text
┌────────────────────────────────────────┐
│ Heure / date                 ■ ■ ■ ■  │
├────────────────────────────────────────┤
│████████████████████████████████████████│  ← 1 px
├────────────────────────────────────────┤
│              TITRE                     │
├────────────────────────────────────────┤
│                                        │
│                                        │
│              CONTENU                   │
│                                        │
│                                        │
├────────────────────────────────────────┤
│  ↑   ↓   ←   →   M   X   ✓            │
└────────────────────────────────────────┘
```

---

## Header compact

Le header utilise une hauteur minimale afin de conserver un maximum d'espace pour le contenu.

Configuration actuelle :

```cpp
#define HEADER_HEIGHT       11

#define HEADER_LINE_1_Y    8

#define PROGRESS_Y         9
#define PROGRESS_HEIGHT    1

#define HEADER_LINE_2_Y   10
```

La barre de progression possède volontairement une hauteur de :

```cpp
#define PROGRESS_HEIGHT 1
```

soit **exactement un pixel**.

---

## Barre de progression

La progression peut être modifiée avec :

```cpp
setProgress(percent);
```

Exemple :

```cpp
setProgress(25);
setProgress(50);
setProgress(75);
setProgress(100);
```

La barre utilise toute la largeur de l'écran.

---

# Titre

La zone de titre est séparée du header.

Configuration :

```cpp
#define TITLE_Y          12
#define TITLE_HEIGHT     20
#define TITLE_LINE_Y     32
```

Le titre est centré horizontalement.

Exemple :

```cpp
drawTitle("SYSTEME");
```

---

# Zone de contenu

La zone centrale est réservée aux écrans et fonctionnalités.

Configuration :

```cpp
#define CONTENT_Y        34
#define CONTENT_HEIGHT   250
```

Cette zone est volontairement importante afin de permettre l'ajout de futures interfaces.

---

# Footer

Le footer contient les commandes principales.

Il utilise une navigation compacte :

```text
↑  ↓  ←  →  M  X  ✓
```

Les boutons sont séparés afin de pouvoir attribuer une couleur différente à chaque fonction.

### Fonctions

| Symbole | Fonction          |
| ------- | ----------------- |
| ↑       | Navigation haut   |
| ↓       | Navigation bas    |
| ←       | Navigation gauche |
| →       | Navigation droite |
| M       | Menu              |
| X       | Annuler           |
| ✓       | Valider           |

Le bouton précédemment représenté par `¤` est maintenant identifié par :

```text
M
```

pour **Menu**.

---

# Couleurs

Les couleurs sont centralisées dans `config.h`.

Exemple :

```cpp
#define COLOR_BACKGROUND   TFT_BLACK
#define COLOR_TEXT         TFT_WHITE
#define COLOR_PRIMARY      TFT_CYAN
#define COLOR_LINE         TFT_WHITE

#define COLOR_BUTTON       TFT_DARKGREY
#define COLOR_BUTTON_TEXT  TFT_WHITE

#define COLOR_OK           TFT_GREEN
#define COLOR_ERROR        TFT_RED
#define COLOR_WARNING      TFT_YELLOW
#define COLOR_INFO         TFT_BLUE
```

L'objectif est de pouvoir modifier rapidement le thème graphique sans modifier le code d'affichage.

---

# Indicateurs d'état

Le header dispose de quatre indicateurs.

Ils peuvent être modifiés avec :

```cpp
setStatus(index, color);
```

Exemple :

```cpp
setStatus(0, COLOR_OK);
setStatus(1, COLOR_OK);
setStatus(2, COLOR_WARNING);
setStatus(3, COLOR_ERROR);
```

Les quatre indicateurs peuvent représenter différents états du système.

Par exemple :

```text
■ WiFi
■ Météo
■ SD
■ Système
```

La signification exacte pourra être définie selon les futures fonctionnalités du 3x0c3t_BO4RD.

---

# Splash screen

Le splash screen est exécuté au démarrage.

Il permet d'afficher une progression visuelle pendant l'initialisation du système.

La durée et les paramètres graphiques sont définis dans `config.h`.

Exemple de séquence :

```text
┌────────────────────────────────────────┐
│                                        │
│                                        │
│              3x0c3t                    │
│                                        │
│            TFT BASE                    │
│                                        │
│              V1.0                      │
│                                        │
│ ████████████████████                   │
│                                        │
└────────────────────────────────────────┘
```

La progression est mise à jour pendant l'affichage du splash avant le passage vers l'interface principale.

---

# WiFi

Deux réseaux peuvent être configurés.

```cpp
WIFI1_SSID
WIFI1_PASSWORD

WIFI2_SSID
WIFI2_PASSWORD
```

Le système essaie d'abord le réseau `WIFI1`.

Si celui-ci n'est pas disponible, il tente `WIFI2`.

Le statut de connexion est ensuite disponible pour les autres modules, notamment la météo.

---

# Météo

La météo nécessite une clé API OpenWeatherMap.

Configuration :

```cpp
#define WEATHER_API_KEY ""

#define WEATHER_CITY     "Lille"
#define WEATHER_COUNTRY  "FR"

#define WEATHER_REFRESH_TIME 600000UL
```

La fréquence de mise à jour est actuellement de :

```text
600000 ms
```

soit :

```text
10 minutes
```

La météo ne tente pas de récupérer les données si le WiFi n'est pas connecté.

---

# Installation

## 1. Cloner le dépôt

```bash
git clone https://github.com/3x0c3t/3x0c3t_TFT_BASE.git
```

Puis :

```bash
cd 3x0c3t_TFT_BASE
```

---

## 2. Sélectionner la carte

Dans Arduino IDE :

```text
NodeMCU 1.0 (ESP-12E Module)
```

---

## 3. Installer TFT_eSPI

Installer la bibliothèque :

```text
TFT_eSPI
```

La configuration du driver ILI9341 doit correspondre au matériel utilisé.

---

## 4. Configurer `config.h`

Modifier notamment :

```cpp
WIFI1_SSID
WIFI1_PASSWORD

WIFI2_SSID
WIFI2_PASSWORD

WEATHER_API_KEY
```

Les paramètres graphiques peuvent également être modifiés directement dans ce fichier.

---

# Compilation

Compiler le fichier :

```text
3x0c3t_TFT_BASE.ino
```

avec :

```text
ESP8266
NodeMCU 1.0 (ESP-12E Module)
```

---

# Organisation du développement

Ce dépôt constitue une **base expérimentale**.

Les nouvelles fonctionnalités doivent idéalement être développées sous forme de modules indépendants.

Exemple :

```text
nouvelle_fonction/
├── fonction.cpp
└── fonction.h
```

Puis intégrées progressivement dans :

```text
3x0c3t_TFT_BASE
```

Cette organisation permet de tester les fonctionnalités séparément avant de les intégrer au projet principal.

---

# État actuel

## Fonctionnel

* [x] Initialisation ESP8266
* [x] Initialisation TFT
* [x] Rotation écran
* [x] Interface 240×320
* [x] Header compact
* [x] Heure et date
* [x] Indicateurs d'état
* [x] Barre de progression
* [x] Barre de progression 1 pixel
* [x] Titre
* [x] Zone de contenu
* [x] Footer compact
* [x] Navigation ↑ ↓ ← →
* [x] Bouton Menu `M`
* [x] Bouton Annuler `X`
* [x] Bouton Valider `✓`
* [x] Gestion des couleurs
* [x] Gestion météo
* [x] Gestion WiFi
* [x] WiFi principal WIFI1
* [x] WiFi secondaire WIFI2
* [x] Splash screen
* [x] Progression du splash screen
* [x] Configuration centralisée

---

# À venir

* [ ] Gestion tactile XPT2046
* [ ] Système de pages
* [ ] Navigation tactile
* [ ] Menus
* [ ] Gestion SD
* [ ] Widgets graphiques
* [ ] Icônes
* [ ] Système d'événements
* [ ] Configuration dynamique
* [ ] Intégration des capteurs
* [ ] Interface web de configuration
* [ ] Gestion OTA
* [ ] Système de thèmes

---

# Philosophie du projet

Le projet privilégie :

* simplicité
* modularité
* faible consommation de ressources
* affichage compact
* configuration centralisée
* fonctions indépendantes
* code facilement réutilisable
* expérimentation rapide

Le but n'est pas de construire une usine à gaz dès le premier démarrage. L'ESP8266 a déjà suffisamment de caractère comme ça.

---

# Version

Version actuelle :

```text
v1.0
```

Branche :

```text
v1.0
```

Dépôt :

[3x0c3t_TFT_BASE sur GitHub](https://github.com/3x0c3t/3x0c3t_TFT_BASE/tree/v1.0?utm_source=chatgpt.com)

---

# Licence

Projet personnel 3x0c3t.

Licence à définir.
