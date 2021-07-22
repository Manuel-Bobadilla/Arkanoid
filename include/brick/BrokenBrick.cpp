//
// Created by juandubowez on 21/5/21.
//

#include "BrokenBrick.h"

void BrokenBrick::setPosition(sf::Vector2f p){
    pos = p;
    sp.setPosition(p.x, p.y);
}

sf::Vector2f BrokenBrick::getPosition(){
    return pos;
}