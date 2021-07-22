//
// Created by Manuel on 25/5/2021.
//

#ifndef INCLUDE_POWERUP_H
#define INCLUDE_POWERUP_H

#include <tmxlite/Layer.hpp>
#include <tmxlite/TileLayer.hpp>
#include <tmxlite/ObjectGroup.hpp>
#include "SFML/Graphics.hpp"
#include <string>

class Powerup {
protected:
    sf::Sprite sp;
    sf::Texture tx;
    tmx::Vector2f pos;
    tmx::Vector2f vel;
    bool active;
public:
    Powerup();
    void setTexture(std::string path);
    void setPosition(tmx::Vector2f p);
    sf::Texture getTexture();
    tmx::Vector2f getPosition();
    void setSpriteTxRect(sf::IntRect r);
    sf::Sprite &getSprite();
    void setVelocity(tmx::Vector2f v);
    tmx::Vector2f getVelocity();
    void move();
    bool isActive();
    virtual void effect() = 0;
};


#endif//INCLUDE_POWERUP_H
