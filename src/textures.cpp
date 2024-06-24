#include "textures.h"

sf::Texture WIZARD_T;
sf::Texture SKELETON_T;
sf::Texture BASIC_SPELL_T;

void loadTextures() {

    WIZARD_T.loadFromFile("res/wizard.png");
    SKELETON_T.loadFromFile("res/skeleton.png");
    BASIC_SPELL_T.loadFromFile("res/basic_spell.png");
}