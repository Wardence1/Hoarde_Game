#include "runScreen.h"

RunScreen::RunScreen() {

    kills_t.setPosition(10, 10);
    kills_t.setCharacterSize(25);
    kills_t.setFont(PIXEL_F);

    health_t.setPosition(10, 45);
    health_t.setCharacterSize(25);
    health_t.setFont(PIXEL_F);

    heldObjectBox.setFillColor(sf::Color(45, 45, 45));
    heldObjectBox.setOutlineColor(sf::Color::Black);
    heldObjectBox.setOutlineThickness(5);
    heldObjectBox.setSize({50, 50});
    heldObjectBox.setOrigin(heldObjectBox.getLocalBounds().width/2, heldObjectBox.getLocalBounds().height/2);

    heldObjectBox.setPosition(SCREEN_WIDTH-50, 50);
}

void RunScreen::update(Player& p) {
    std::string kills_s = "Kills: " + std::to_string(kills);
    std::string health_s = "Health: " + std::to_string(p.health) + "/" + std::to_string(p.maxHealth);
    kills_t.setString(kills_s);
    health_t.setString(health_s);

    // Object
    if (p.heldObject != nullptr) {
        p.heldObject->sprite.setOrigin(p.heldObject->sprite.getLocalBounds().width/2, p.heldObject->sprite.getLocalBounds().height/2);
        p.heldObject->sprite.setPosition(heldObjectBox.getPosition().x-(p.heldObject->sprite.getLocalBounds().width/2), heldObjectBox.getPosition().y-(p.heldObject->sprite.getLocalBounds().height/2));
    }
}

void RunScreen::draw(sf::RenderWindow& window, Player& p) {

    window.draw(kills_t);
    window.draw(health_t);
    window.draw(heldObjectBox);

    if (p.heldObject != nullptr) {
        window.draw(p.heldObject->sprite);
    }
}
