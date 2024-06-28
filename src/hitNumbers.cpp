#include "hitNumbers.h"

HitNumber::HitNumber(point pos, int amount, bool crit, bool red) {

    this->pos = pos;
    this->amount = amount;
    this->red = red;
    num.setPosition(pos.x, pos.y);
    num.setFont(PIXEL_F);
    num.setStyle(sf::Text::Bold);
    if (crit) num.setStyle(sf::Text::Underlined);
    num.setString(std::to_string(amount));
    num.setCharacterSize(34);

    num.setFillColor(sf::Color::White);
    num.setOutlineColor(sf::Color::Black);
}

void HitNumber::update() {

    pos.y -= speed;
    if (red) {
        num.setFillColor({255, 0, 0, (unsigned char)time});
    } else {
        num.setFillColor({255, 255, 255, (unsigned char)time});
    }
    


    if (time <= 0)
        dead = true;
    else {
        num.setPosition(pos.x, pos.y);
        time-=6;
    }
}

void HitNumber::draw(sf::RenderWindow& window) {

    window.draw(num);
}


void HitNumManager::updateM() {

    for (long unsigned int i=0; i<list.size(); i++) {
        list[i].update();
        if (list[i].dead) 
            list.erase(i+list.begin());
    }
}

void HitNumManager::drawM(sf::RenderWindow& window) {
    for (auto& n : list) {
        n.draw(window);
    }
}


void HitNumManager::addN(point pos, int amount, bool crit, bool red) {

    list.push_back(HitNumber(pos, amount, crit, red));
}
