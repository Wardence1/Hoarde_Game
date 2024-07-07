#include "potion.h"
#include "../player.h"

Potion::Potion(point pos, std::string type, bool held) : Object(pos, held), type(type) {

    if (type == "healing potion"){
        sprite.setTexture(HEALING_POTION_T);
    }
    else if (type == "invincibility potion") {
        sprite.setTexture(INVINCIBILITY_POTION_T);
    }
    else {
        std::cout << "Invalid potion type\n";
        exit(1);
    }

    sprite.setScale(SCALE, SCALE);
    sprite.setOrigin(sprite.getLocalBounds().width/2, sprite.getLocalBounds().height/2);
    sprite.setPosition(pos.x, pos.y);
}

void Potion::update(Player& p) {

    despawnTime--;
    if (despawnTime <=0) {
        gone = true;
    }
    
    if (p.sprite.getGlobalBounds().intersects(sprite.getGlobalBounds()) && p.heldObject == nullptr) {
        p.heldObject = std::make_unique<Potion>(point{-200,-200}, type, true);
        gone = true;
    }
}

void Potion::heldUpdate(Player& p, HitNumManager& nMan) {

    if (type == "healing potion") {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
            p.heldObject = nullptr;
            if (p.health+p.healPotionAmount <= p.maxHealth) {
                p.health += p.healPotionAmount;
                nMan.addN(p.pos, p.healPotionAmount, false, false, true);
            } else {
                nMan.addN(p.pos, p.maxHealth - p.health, false, false, true);
                p.health += p.maxHealth - p.health;
            }
        }
    } else if (type == "invincibility potion") {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
            p.heldObject = nullptr;
            p.immunityF += FPS*1.5f;
        }
    } else {
        std::cout << "Invalid potion type.\n";
        exit(1);
    }
}

void Potion::draw(sf::RenderWindow& window) {

    if (despawnTime > FPS*2)
        window.draw(sprite);
    else if ((despawnTime & 4) != 0)
        window.draw(sprite);
}