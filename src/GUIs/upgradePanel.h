// The slot for each upgrade in upgradeScreen
#pragma once
#include "SFML/Graphics.hpp"
#include "../globals.h"
#include "../textures.h"
#include "../player.h"
#include <random>
#include <iostream>

class UpgradePanel {

public:
    UpgradePanel(point pos, std::string type);
    void update(bool selected);
    void pressed(Player&);
    void draw(sf::RenderWindow&);
    sf::RectangleShape bigBox;
    sf::Text description, title;

private:
    int randWep;
    int randSelf;
    int randBuilding;
    std::string type;
};