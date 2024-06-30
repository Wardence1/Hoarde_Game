#include "enemy.h"
#include "../player.h"
#include "enemyManager.h"

Enemy::Enemy() {

    Enemy::allCode++;
    code = Enemy::allCode;
    Enemy::amount++;
    facing = Down;
}

void Enemy::update(Player& p, EnemyManager& eManager, HitNumManager& nManager) {

    sprite.setColor(sf::Color::White);

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

    point eCenter {
        pos.x + width/2,
        pos.y + height/2
    };

    point pCenter {
        p.pos.x + p.width/2,
        p.pos.y + p.height/2
    };


    if (abs(eCenter.x - pCenter.x) > threshold) {
        if (eCenter.x > pCenter.x) { // left
            velo.x -= speed;
            facing = Left;
        }
        else { // right
            velo.x += speed;
            facing = Right;
        }
    }

    if (abs(eCenter.y - pCenter.y) > threshold) {
        if (eCenter.y > pCenter.y) { // up
            velo.y -= speed;
            facing = Up;
        }
        else { // down
            velo.y += speed;
            facing = Down;
        }
    }

    // Collisions with other enemies
    for (auto const& e : Enemy::enemy_list) {
        if (e.code != code) { // You can't collide with yourself
            if (e.sprite.getGlobalBounds().intersects(sprite.getGlobalBounds()) && pos.x < e.pos.x) { // hit from right
                if (velo.x > 0) 
                    velo.x = 0;
            }
            else if (e.sprite.getGlobalBounds().intersects(sprite.getGlobalBounds()) && pos.x > e.pos.x) { // hit from left
                if (velo.x < 0)
                    velo.x = 0;
            }

            if (e.sprite.getGlobalBounds().intersects(sprite.getGlobalBounds()) && pos.y < e.pos.y) { // hit from bottom
                if (velo.y > 0)
                    velo.y = 0;
            }
            else if (e.sprite.getGlobalBounds().intersects(sprite.getGlobalBounds()) && pos.y > e.pos.y) { // hit from top
                if (velo.y < 0)
                    velo.y = 0;
            }
        } 
    }

    if (hitDam > 0) {
        sprite.setColor(sf::Color::Red);
        health -= hitDam;
        nManager.addN({pos.x, pos.y-5}, hitDam, crit);
        crit=false;
        // Knockback
        switch (p.facing) {
            case Up:
                velo.y = -p.knockback;
                break;
            case Down:
                velo.y = p.knockback;
                break;
            case Left:
                velo.x = -p.knockback;
                break;
            case Right:
                velo.x = p.knockback;
                break;        
        }

        hitDam = 0;
    }

    if (health <= 0 && !dead) { // death checks
        Enemy::amount--;
        dead = true;
    }

    // Hitting the player
    if (p.sprite.getGlobalBounds().intersects(sprite.getGlobalBounds())) {
        p.hitDam = damage;
        p.hitDir = facing;
    }


    if (velo.x && velo.y) { // Stops from moving faster diagonally
        pos.x += velo.x/1.414;
        pos.y += velo.y/1.414; // square root of 2
    }
    else {
        pos.x += velo.x;
        pos.y += velo.y;
    }


    sprite.setPosition(pos.x, pos.y);
}

void Enemy::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

std::vector<Enemy> Enemy::enemy_list;
int Enemy::allCode = 0;
unsigned int Enemy::amount = 0;