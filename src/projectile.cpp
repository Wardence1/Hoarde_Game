#include "projectile.h"
#include "enemy.h"

Projectile::Projectile(const std::string type, point origin, point going) {

    going.x -= width/2;
    going.y -= height/2;

    rise = origin.y - going.y; // *TODO* Get this to work
    run = origin.x - going.x;
    pos = origin;

    //rise /= rise/run;
    //run /= rise/run;


    if (type == "basic spell") {
        sprite.setTexture(BASIC_SPELL_T);
        rise/20;
        run/20;
    }

    sprite.scale(SCALE, SCALE);
    width = sprite.getTextureRect().width*SCALE;
    height = sprite.getTextureRect().height*SCALE;
}

void Projectile::update() {

    pos.x += run;
    pos.y += rise;

    if (pos.x > SCREEN_WIDTH || pos.x+width < 0 || pos.y+height < 0 || pos.y > SCREEN_HEIGHT)
        ;// delete it here

    sprite.setPosition(pos.x, pos.y);
}

void Projectile::draw(sf::RenderWindow& window) {

    window.draw(sprite);
}