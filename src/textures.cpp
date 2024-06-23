#include "textures.h"

sf::Texture WIZARD_T;
sf::Texture SKELETON_T;

void loadTextures() {

    WIZARD_T.loadFromFile("res/wizard.png");
    SKELETON_T.loadFromFile("res/skeleton.png");
}