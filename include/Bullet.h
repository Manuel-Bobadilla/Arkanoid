//
// Created by Manuel on 3/6/2021.
//

#ifndef INCLUDE_BULLET_H
#define INCLUDE_BULLET_H

#include <tmxlite/Layer.hpp>
#include <tmxlite/TileLayer.hpp>
#include <tmxlite/ObjectGroup.hpp>
#include "SFML/Graphics.hpp"
#include <string>

class Bullet {
private:
    sf::Sprite sp;
    sf::Texture tx;
    tmx::Vector2f pos;
    tmx::Vector2f vel;

public:
    Bullet();
    void setTexture(std::string path);
    void setPosition(tmx::Vector2f p);
    sf::Texture getTexture();
    tmx::Vector2f getPosition();
    void setSpriteTxRect(sf::IntRect r);
    sf::Sprite &getSprite();
    void setVelocity(tmx::Vector2f v);
    tmx::Vector2f getVelocity();
    void move();
};

#endif//INCLUDE_BULLET_H
