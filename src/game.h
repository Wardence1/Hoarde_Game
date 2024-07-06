#pragma once
#include <SFML/Graphics.hpp>
#include "globals.h"
#include <iostream>
#include "textures.h"
#include "player.h"
#include "./enemies/enemyManager.h"
#include "projManager.h"
#include "GUIs/deadScreen.h"
#include "hitNumbers.h"
#include "GUIs/runScreen.h"
#include "GUIs/pauseScreen.h"
#include "GUIs/upgradeScreen.h"
#include "objects/objectManager.h"

class Game {

public:
    void start();
};