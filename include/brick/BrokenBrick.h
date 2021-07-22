//
// Created by juandubowez on 21/5/21.
//

#ifndef INCLUDE_BROKENBRICK_H
#define INCLUDE_BROKENBRICK_H

#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>
#include <tmxlite/Layer.hpp>
#include <tmxlite/ObjectGroup.hpp>
#include <tmxlite/TileLayer.hpp>
#include "Brick.h"

class BrokenBrick : public Brick{
private:
    sf::Vector2f pos;

public:
    void setPosition(sf::Vector2f p);
    sf::Vector2f getPosition();
};


#endif//INCLUDE_BROKENBRICK_H
