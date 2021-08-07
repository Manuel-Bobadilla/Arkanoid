//
// Created by Facundo Barafani on 24/4/21.
//

#ifndef INCLUDE_PLAYER_H_
#define INCLUDE_PLAYER_H_

#include <tmxlite/Layer.hpp>
#include <tmxlite/TileLayer.hpp>
#include <tmxlite/ObjectGroup.hpp>
#include "SFML/Graphics.hpp"
#include <string>
#include "manager/animation/AnimationManager.h"
#include "manager/animation/Container.h"

class Player {
private:
    sf::Sprite sp;
    sf::Texture tx;
    tmx::Vector2f pos;
    Container<sf::Texture> txs[4]; //Cantidad de contenedores de texturas para el player
    int containerSelected = 0;
    unsigned int lives = 3;
public:
    void setTexture(const std::string& path);
    void setTexture(const sf::Texture& t);
    void appendTexture(const std::string& path, int pos);
    Container<sf::Texture> &getTextureContainer(int pos);
    void setPosition(tmx::Vector2f p);
    sf::Texture getTexture();
    tmx::Vector2f getPosition();
    void setSpriteTxRect(sf::IntRect r);
    sf::Sprite &getSprite();
    void setContainerSelected(int index);
    int getContainerSelected();
    unsigned int getLives() const;
    void setLives(unsigned int lives);
};


#endif // INCLUDE_PLAYER_H_
