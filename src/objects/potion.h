#include "object.h"
#include <iostream>
#include "../textures.h"


class Potion : public Object {

public:
    Potion(point pos, std::string type, bool held=false);
    void update(Player&) override;
    void draw(sf::RenderWindow&) override;
    void heldUpdate(Player&, HitNumManager&) override;
    std::string type;
};