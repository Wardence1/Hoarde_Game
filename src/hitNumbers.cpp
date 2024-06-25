#include "hitNumbers.h"

HitNumber::HitNumber(point pos, int amount) {

    this->pos = pos;
    num.setPosition(pos.x, pos.y);
    num.setFont(PIXEL_F);
    num.setString(std::to_string(amount));
    num.setCharacterSize(34);
}

void HitNumber::update() {

    pos.y -= speed;
    num.setFillColor({0, 0, 0, time});
    time++;

    if (time > 100)
        num.setCharacterSize(.1); // TODO Delete it
}

void HitNumber::draw(sf::RenderWindow& window) {

    window.draw(num);
}


void HitNumManager::updateM() {

    for (auto n : list) {
        n.update();
    }
}

void HitNumManager::drawM(sf::RenderWindow& window) {
    for (auto n : list) {
        n.draw(window);
    }
}


void HitNumManager::addN(point pos, int amount) {

    list.push_back(HitNumber(pos, amount));
}
