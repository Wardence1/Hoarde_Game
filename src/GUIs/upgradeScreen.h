#pragma once
#include <SFML/Graphics.hpp>
#include "../textures.h"
#include "../globals.h"
#include "../player.h"
#include "upgradePanel.h"
#include <vector>

class UpgradeScreen {

public:
    UpgradeScreen();
    void update(Player&);
    void draw(sf::RenderWindow&);
    void init(); // Used to reset the vector of panels
    bool alreadyReset = false;
private:
    int selected = -10;
    sf::RectangleShape body;
    sf::Text upgrades; // The title
    sf::RectangleShape greyness; // The Background
    std::vector<UpgradePanel> panels;

    enum buttons {
        None,
        Top, // Weapon upgrade
        Middle, // powerup
        Bottom, // building
        Back
    };
};