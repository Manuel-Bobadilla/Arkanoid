//
// Created by facundo on 27/4/21.
//

#ifndef INCLUDE_BORDER_H_
#define INCLUDE_BORDER_H_

#include "SFML/Graphics.hpp"
#include <string>
#include "Brick.h"

class BorderBrick: public Brick {
private:
    sf::Vector2f pos;
public:
    void setPosition(sf::Vector2f p);
    sf::Vector2f getPosition();
};


#endif  // INCLUDE_BORDER_H_
