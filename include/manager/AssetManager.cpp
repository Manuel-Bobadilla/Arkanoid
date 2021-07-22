//
// Created by Facundo Barafani on 9/5/21.
//

#include "AssetManager.h"

void AssetManager::loadTexture(std::string name, std::string fileName) {
    sf::Texture tx;

    if (tx.loadFromFile(fileName)) {
        this->_textures[name] = tx;
    }
}
sf::Texture &AssetManager::getTexture(std::string name) {
        return this->_textures.at(name);
    }

void AssetManager::loadFont(std::string name, std::string fileName) {
    sf::Font font;

    if (font.loadFromFile(fileName)) {
        this->_fonts[name] = font;
    }
}
sf::Font &AssetManager::getFont(std::string name) {
    return this->_fonts.at(name);
}