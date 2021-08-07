//
// Created by Manuel on 26/7/2021.
//

#ifndef PROJECTTEMAPLATE_BULLETTEXTUREMANAGER_H
#define PROJECTTEMAPLATE_BULLETTEXTUREMANAGER_H

#include <SFML/Graphics/Texture.hpp>

class BulletTextureManager{
private:
    sf::Texture tx;
public:
    BulletTextureManager();
    sf::Texture& getTextureBullet();
};

#endif//PROJECTTEMAPLATE_BULLETTEXTUREMANAGER_H
