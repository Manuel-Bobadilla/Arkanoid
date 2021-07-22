//
// Created by juandubowez on 15/5/21.
//

#include "MapBrick.h"

void MapBrick::setPosition(sf::Vector2f p){
    pos = p;
}

sf::Vector2f MapBrick::getPosition(){
    return pos;
}

std::string MapBrick::getColor(){
    return color;
}

void MapBrick::setColor(std::string color){
    this->color = color;
}