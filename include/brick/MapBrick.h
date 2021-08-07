//
// Created by juandubowez on 15/5/21.
//

#ifndef INCLUDE_MAPBRICK_H
#define INCLUDE_MAPBRICK_H

#include "SFML/Graphics.hpp"
#include <string>
#include "Brick.h"

class MapBrick: public Brick {
private:
    sf::Vector2f pos;
public:
    void setPosition(sf::Vector2f p);
    sf::Vector2f getPosition();
};


#endif  //INCLUDE_MAPBRICK_H
