#pragma once
#include <SFML/Graphics.hpp>
#include "globals.h"
#include <iostream>
#include "textures.h"
#include "player.h"
#include "enemyManager.h"
#include "projManager.h"

class Game {

public:
    void start();
    bool running;
};