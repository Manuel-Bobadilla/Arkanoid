//
// Created by Manuel on 27/5/2021.
//

#include "PowerupInvisible.h"

PowerupInvisible::PowerupInvisible(Ball &b) : Powerup(){
    active = false;
    ball = &b;
    frameCounter = 0;
    setTexture("../assets/images/21-Breakout-Tiles.png");
    setSpriteTxRect(sf::IntRect (0,0,18,18));
}
void PowerupInvisible::effect(){
    if(frameCounter == 0){
        ball->setTexture("../assets/images/transparente.png");
        active = true;
    }
    frameCounter++;
    if(frameCounter > 120){
        frameCounter = 0;
        ball->setTexture("../assets/images/58-Breakout-Tiles.png");
        active = false;
    }
}