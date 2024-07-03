#include "upgradeScreen.h"

UpgradeScreen::UpgradeScreen() {

    greyness.setSize({SCREEN_WIDTH, SCREEN_HEIGHT});
    greyness.setPosition(0, 0);
    greyness.setFillColor(sf::Color({95, 95, 95, 125}));

    upgrades.setString("Upgrade Time!");
    upgrades.setFont(PIXEL_F);
    upgrades.setCharacterSize(60);
    upgrades.setOrigin(upgrades.getLocalBounds().width/2, upgrades.getLocalBounds().height/2);
    upgrades.setPosition(SCREEN_WIDTH/2, SCREEN_HEIGHT/6);
}

void UpgradeScreen::init() {

    panels.clear();

    panels.push_back(UpgradePanel({SCREEN_WIDTH/2, (SCREEN_HEIGHT/4)+(130)}, "weapon"));
    panels.push_back(UpgradePanel({SCREEN_WIDTH/2, (SCREEN_HEIGHT/4)+(260)}, "self"));
    panels.push_back(UpgradePanel({SCREEN_WIDTH/2, (SCREEN_HEIGHT/4)+(390)}, "building"));

    alreadyReset = true;
}

void UpgradeScreen::update(Player& p) {
    
    if (downArrow) {
        selected++;
    } else if (upArrow) {
        selected--;
    } if (selected <= -2 && upArrow) {
        selected = 2;
    } else if (selected <= -2 && downArrow) {
        selected = 0;
    }

    if (selected == -1)
        selected = 2;
    if (selected >= 3)
        selected = 0;

    for (int i=0; i < (int)panels.size(); i++) {
        if (i == selected)
            panels[i].update(true);
        else 
            panels[i].update(false);
    }


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
        panels[selected].pressed(p);
        alreadyReset = false;
        selected = -10;
        game_state = Running;
    }
}

void UpgradeScreen::draw(sf::RenderWindow& window) {

    window.draw(greyness);
    window.draw(upgrades);

    for (int i=0; i < (int)panels.size(); i++) {
        panels[i].draw(window);
    }
}
