#include "player.h"
#include "enemyManager.h"
#include <iostream>
#include "projectile.h"

Player::Player(std::string c_class) {

    pos = {400, 400};

    if (c_class == "warrior") {
        sprite.setTexture(WIZARD_T);
        character_class = Warrior;
    }
    else if (c_class == "wizard") {
        sprite.setTexture(WIZARD_T);
        character_class = Wizard;
    }
    else if (c_class == "archer") {
        sprite.setTexture(WIZARD_T);
        character_class = Archer;
    }
    else {
        std::cout << "Invalid character type.\n";
        exit(-1);
    }

    sprite.setPosition({pos.x, pos.y});
    sprite.setScale(SCALE, SCALE);

    width = sprite.getTextureRect().width*SCALE;
    height = sprite.getTextureRect().height*SCALE;
}

void Player::update(EnemyManager& eMan, ProjManager& pMan) {

    if (dead)
        sprite.setScale(0, 0);

    facing = {false, false, false, false};

    velo.y = 0;
    velo.x = 0;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        velo.y -= speed;
        facing.up = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        velo.x -= speed;
        facing.left = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        velo.y += speed;
        facing.down = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        velo.x += speed;
        facing.right = true;
    }

    attackTime(eMan, pMan);

    // Collision with sides
    if (pos.x + velo.x + width > SCREEN_WIDTH) {
        velo.x = 0;
        pos.x = SCREEN_WIDTH-width;
    }
    else if (pos.x + velo.x < 0) {
        velo.x = 0;
        pos.x = 0;
    }
    if (pos.y + velo.y + height > SCREEN_HEIGHT) {
        velo.y = 0;
        pos.y = SCREEN_HEIGHT-height;
    }
    else if (pos.y + velo.y < 0) {
        velo.y = 0;
        pos.y = 0;
    }

    if (velo.x && velo.y) { // Stops from moving faster diagonally
        pos.x += velo.x/1.4;
        pos.y += velo.y/1.4;
    }
    else {
        pos.x += velo.x;
        pos.y += velo.y;
    }


    sprite.setPosition(pos.x, pos.y);
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Player::attackTime(EnemyManager& eMan, ProjManager& pMan) {

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        switch (character_class) {
        case Wizard:
            pMan.addP("basic spell", {pos.x-(width/2), pos.y-(height/2)}, {(float)mPos.x, (float)mPos.y});
            break;
        case Archer:
            // TODO
            break;
        case Warrior:

            if (facing.up) {
                
            }
            else if (facing.down) {
                
            }
            else if (facing.left) {

            }
            else if (facing.right) {
                
            }


            break;
        }
    }
        

    for (auto& l : eMan.enemies)
        for (auto& e : l) {
            // Enemy collisions with attack
        }
}