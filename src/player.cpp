#include "player.h"
#include "enemies/enemyManager.h"
#include <iostream>
#include "projectile.h"

Player::Player() {

    sprite.setTexture(KNIGHT_T);

    width = sprite.getTextureRect().width*SCALE;
    height = sprite.getTextureRect().height*SCALE;

    pos = {(SCREEN_WIDTH/2)-(width/2), (SCREEN_HEIGHT/2)-(height/2)};

    sprite.setPosition({pos.x, pos.y});
    sprite.setScale(SCALE, SCALE);

    facing = Down;
    hitDir = Down;

    slash_s.setTexture(SLASH_T);
    slash_s.setScale(0, 0);
}

void Player::update(ProjManager& pMan, HitNumManager& nMan, Player& p) {

    // Update the object being held
    if (heldObject != nullptr)
        if (heldObject->held) {
            heldObject->heldUpdate(p, nMan);
        }

    // Set speed equal to zero or slow it down
    if (abs(velo.x) <= speed) {
        velo.x = 0;
    } else {
        velo.x > 0 ? velo.x -= speed+2 : velo.x += speed+2;
    }

    if (abs(velo.y) <= speed) {
        velo.y = 0;
    } else {
        velo.y > 0 ? velo.y -= speed+2 : velo.y += speed+2;
    }



    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        if (!knockBacked) velo.y -= speed;
        facing = Up;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        if (!knockBacked) velo.x -= speed;
        facing = Left;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        if (!knockBacked) velo.y += speed;
        facing = Down;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        if (!knockBacked) velo.x += speed;
        facing = Right;
    }


    // Regeneration
    if (tTime != 0)
        if (tTime%(regenTime*FPS) == 0) {
            if (health+regenAmount <= maxHealth) {
                health += regenAmount;
                nMan.addN({pos.x, pos.y}, regenAmount, false, false, true);
            } else if (health != maxHealth) {
                nMan.addN({pos.x, pos.y}, maxHealth-health, false, false, true);
                health += maxHealth-health;
            }

        }


    if (knockBacked && abs(velo.x) <= speed && abs(velo.y) <= speed)
        knockBacked = false;

    // Enemy collision
    if (immunityF > 0) {
        immunityF--;
        hitDam = 0;
    }
    else if (hitDam > 0 && godMode == false) {
        if ((health-hitDam) > 0) nMan.addN(pos, -hitDam, false, true);
        immunityF = FPS;
        sprite.setColor(sf::Color::Red);
        if (!knockBacked)
            switch (hitDir) { // TODO * make each enemy have their own knockback
                case Up:
                    velo.y = -40;
                    break;
                case Down:
                    velo.y = 40;
                    break;
                case Left:
                    velo.x = -40;
                    break;
                case Right:
                    velo.x = 40;
                    break;
            }
        health -= hitDam;
        knockBacked = true;
        hitDam = 0;
    }
    // Projectile Collision
    else if (!godMode) {
        for (auto& projectile : pMan.projectiles) {
            if (slash_s.getGlobalBounds().intersects(projectile.sprite.getGlobalBounds())) {
                projectile.gone = true;
            }
            else if (projectile.sprite.getGlobalBounds().intersects(sprite.getGlobalBounds())) {
                immunityF = FPS/2;
                health -= projectile.damage;
                nMan.addN(pos, -projectile.damage, false, true);
                projectile.gone = true;
            }
        }
    }

    if (health <= 0) {
        game_state = Dead;
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
        pos.x += velo.x/1.414;
        pos.y += velo.y/1.414; // square root of 2
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

    if ((immunityF & 3) == 0) window.draw(sprite);

    sprite.setColor(sf::Color::White);
}

void Player::attack(ProjManager& pMan) {

    if (atkCool < FPS*10) atkCool++;

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
}
        

void Player::createSlash(point spawn, int rotation) {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && atkCool >= atkCoolTime) {
            attacking = true;
    }

    if (attacking) {
        slash_s.setPosition(spawn.x, spawn.y);
        slash_s.setRotation((float)rotation);
        slash_s.setScale(SCALE, SCALE);
        atkTime++;

        if (atkTime == 1) {
            for (auto& e : Enemy::enemy_list)
                if (slash_s.getGlobalBounds().intersects(e->sprite.getGlobalBounds())) {
                    if (rand()%4 == 3) {
                        e->hitDam = damage*1.5;
                        e->crit = true;
                    }
                    else {
                        e->hitDam = damage;
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
}
