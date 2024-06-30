#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../enemies/enemy.h"
#include "button.h"
#include "../player.h"
#include "../globals.h"

class DeadScreen {

public:
    DeadScreen();
    void update(Player& p, HitNumManager& nMan);
    void draw(sf::RenderWindow&);

private:
    float width=0, height=0;
    sf::RectangleShape redness; // Gives the screen a red tint
    Button exit_B, respawn_B;
    sf::Text youDied;

    enum {
        Exit,
        Respawn
    } buttons;
};