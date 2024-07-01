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
    sf::RectangleShape redness; // Gives the screen a red tint
    Button respawn_B, exit_B;
    sf::Text youDied;

    enum {
        None,
        Respawn,
        Exit
    } buttons;
};