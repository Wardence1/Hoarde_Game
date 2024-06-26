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

    facing = Down;


    slash_s.setTexture(SLASH_T);
    slash_s.setScale(0, 0);
}

void Player::update(ProjManager& pMan) {

    if (dead)
        ;//sprite.setScale(0, 0);

    velo.y = 0;
    velo.x = 0;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        velo.y -= speed;
        facing = Up;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        velo.x -= speed;
        facing = Left;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        velo.y += speed;
        facing = Down;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        velo.x += speed;
        facing = Right;
    }

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

    attack(pMan);

    sprite.setPosition(pos.x, pos.y);
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(slash_s);
    window.draw(sprite);
}

void Player::attack(ProjManager& pMan) {

    if (atkCool < FPS*10) atkCool++;

    switch (character_class) {
    case Wizard:
        pMan.addP("basic spell", {pos.x-(width/2), pos.y-(height/2)}, {(float)mPos.x, (float)mPos.y});
        break;
    case Archer:
        // TODO
        break;
    case Warrior:
        if (facing == Right) {
            createSlash({pos.x+width+slash_s.getTextureRect().width*SCALE, pos.y}, 90);
        }
        else if (facing == Down) {
            createSlash({pos.x+slash_s.getTextureRect().width*SCALE, pos.y+height*2}, 180);
        }
        else if (facing == Left) {
            createSlash({pos.x-width, pos.y + slash_s.getTextureRect().height*SCALE}, 270);
        }
        else if (facing == Up) {
            createSlash({pos.x, pos.y-height}, 0);
        }
        break;
    }
}
        

void Player::createSlash(point spawn, int rotation) {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        if (atkCool >= 4 && !sPressed) {
            attacking = true;
            sPressed = true;
        }
    } else
        sPressed = false;

    if (attacking) {
        slash_s.setPosition(spawn.x, spawn.y);
        slash_s.setRotation((float)rotation);
        slash_s.setScale(SCALE, SCALE);
        atkTime++;

        if (atkTime == 1)
            for (auto& e : Skeleton::enemy_list)
                if (slash_s.getGlobalBounds().intersects(e.sprite.getGlobalBounds())) {
                    if (rand()%4 == 3) {
                        e.hitDam = damage*1.5;
                        e.crit = true;
                    }
                    else {
                        e.hitDam = damage;
                    }
                }
    }


    if (atkTime > 1) {
        slash_s.setScale(0, 0);
        atkCool = 0;
        atkTime = 0;
        attacking = false;
    }
}
