#include "goblin.h"

Goblin::Goblin(point pos) {

    sprite.setTexture(GOBLIN_T);
    this->pos = pos;
    sprite.setPosition(pos.x, pos.y);
    sprite.setScale(SCALE, SCALE);

    width = sprite.getTextureRect().width*SCALE;
    height = sprite.getTextureRect().height*SCALE;

    speed = 5;
    damage = 2;
    health = 6;
}

void Goblin::update(Player& p, EnemyManager& eMan, HitNumManager& hMan)  {

    Enemy::update(p, eMan, hMan);
}
