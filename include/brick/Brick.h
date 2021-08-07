//
// Created by juandubowez on 15/5/21.
//

#ifndef PROJECTTEMAPLATE_BRICK_H
#define PROJECTTEMAPLATE_BRICK_H

#include "SFML/Graphics.hpp"
#include <string>

class Brick {
protected:
    unsigned int id;
    sf::Sprite sp;
    sf::Texture *tx;
    std::optional<std::string> color;
public:
    virtual ~Brick(){};
    void setId(int id);
    unsigned int getId();
    void setTexture(std::string path);
    void setTexture(sf::Texture &tx);
    sf::Texture &getTexture();
    void setSpriteTxRect(sf::IntRect r);
    sf::Sprite &getSprite();
    void setColor(std::string color);
};


#endif//PROJECTTEMAPLATE_BRICK_H
