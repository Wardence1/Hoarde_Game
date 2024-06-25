#include "skeleton.h"
#include "player.h"

Skeleton::Skeleton(point pos) {

    sprite.setTexture(SKELETON_T);
    this->pos = pos;
    sprite.setPosition(pos.x, pos.y);
    sprite.setScale(SCALE, SCALE);

    width = sprite.getTextureRect().width*SCALE;
    height = sprite.getTextureRect().height*SCALE;

    speed = 3;
}

void Skeleton::update(Player& p, EnemyManager& eManager, HitNumManager& nManager) {

    Enemy::update(p, eManager, nManager);
}

