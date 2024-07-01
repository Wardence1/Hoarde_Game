#include "runScreen.h"

RunScreen::RunScreen() {

    kills_t.setPosition(10, 10);
    kills_t.setCharacterSize(25);
    kills_t.setFont(PIXEL_F);

    health_t.setPosition(10, 45);
    health_t.setCharacterSize(25);
    health_t.setFont(PIXEL_F);
}

void RunScreen::update(Player& p) {
    std::string kills_s = "Kills: " + std::to_string(kills);
    std::string health_s = "Health: " + std::to_string(p.health);
    kills_t.setString(kills_s);
    health_t.setString(health_s);
}

void RunScreen::draw(sf::RenderWindow& window) {

    window.draw(kills_t);
    window.draw(health_t);
}
