//
// Created by Facundo Barafani on 24/4/21.
//

#ifndef INCLUDE_BALL_H_
#define INCLUDE_BALL_H_
#include <tmxlite/Layer.hpp>
#include <tmxlite/TileLayer.hpp>
#include <tmxlite/ObjectGroup.hpp>
#include "SFML/Graphics.hpp"
#include <string>

class Ball {
private:
    sf::Sprite sp;
    sf::Texture tx;
    tmx::Vector2f pos;
    tmx::Vector2f vel;

public:
    Ball();
    void setTexture(std::string path);
    void setTexture(const sf::Texture& t);
    void setPosition(tmx::Vector2f p);
    sf::Texture getTexture();
    tmx::Vector2f getPosition();
    void setSpriteTxRect(sf::IntRect r);
    sf::Sprite &getSprite();
    void setVelocity(tmx::Vector2f v);
    tmx::Vector2f getVelocity();
    void move();
};


#endif // INCLUDE_BALL_H_
