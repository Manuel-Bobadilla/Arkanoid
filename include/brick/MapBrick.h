//
// Created by juandubowez on 15/5/21.
//

#ifndef INCLUDE_MAPBRICK_H
#define INCLUDE_MAPBRICK_H

#include "SFML/Graphics.hpp"
#include <string>
#include <iostream>
#include "Brick.h"

class MapBrick: public Brick {
    sf::Vector2f pos;
    std::string color;

public:
    void setPosition(sf::Vector2f p);
    sf::Vector2f getPosition();
    std::string getColor();
    void setColor(std::string color);
};


#endif  //INCLUDE_MAPBRICK_H
