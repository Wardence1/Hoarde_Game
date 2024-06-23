#include "player.h"
#include <iostream>

Player::Player() {

    pos = {400, 400};

    sprite.setPosition({pos.x, pos.y});
    sprite.setTexture(WIZARD_T);
    sprite.setScale(SCALE, SCALE);

    width = sprite.getTextureRect().width*SCALE;
    height = sprite.getTextureRect().height*SCALE;
}

void Player::update() {

    if (dead)
        sprite.setScale(0, 0);

    velo.y = 0;
    velo.x = 0;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        velo.y -= speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        velo.x -= speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        velo.y += speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        velo.x += speed;


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