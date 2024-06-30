#include "textures.h"

sf::Texture WIZARD_T;
sf::Texture KNIGHT_T;
sf::Texture SKELETON_T;
sf::Texture BASIC_SPELL_T;
sf::Texture SLASH_T;
sf::Texture GOBLIN_T;
sf::Font PIXEL_F; // This is a font. EHH, same thing.

void loadTextures() {

    WIZARD_T.loadFromFile("res/wizard.png");
    KNIGHT_T.loadFromFile("res/knight.png");
    SKELETON_T.loadFromFile("res/skeleton.png");
    BASIC_SPELL_T.loadFromFile("res/basic_spell.png");
    SLASH_T.loadFromFile("res/slash.png");
    GOBLIN_T.loadFromFile("res/goblin.png");
    PIXEL_F.loadFromFile("res/Pixel_Font.ttf");
}