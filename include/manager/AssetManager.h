//
// Created by Facundo Barafani on 9/5/21.
//

#ifndef PROJECTTEMAPLATE_ASSETMANAGER_H
#define PROJECTTEMAPLATE_ASSETMANAGER_H

#include <map>
#include <SFML/Graphics.hpp>

class AssetManager {
private:
    std::map<std::string, sf::Texture> _textures;
    std::map<std::string, sf::Font> _fonts;
public:
    AssetManager(){};
    ~AssetManager(){};
    void loadTexture(std::string name, std::string fileName);
    sf::Texture &getTexture(std::string name);
    void loadFont(std::string name, std::string fileName);
    sf::Font &getFont(std::string name);
};


#endif//PROJECTTEMAPLATE_ASSETMANAGER_H
