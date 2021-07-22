//
// Created by Manuel on 30/5/2021.
//

#include "PowerupSmallBall.h"

PowerupSmallBall::PowerupSmallBall(Ball &b) : Powerup(){
    active = false;
    ball = &b;
    frameCounter = 0;
    setTexture("../assets/images/23-Breakout-Tiles.png");
    setSpriteTxRect(sf::IntRect (0,0,18,18));
}
void PowerupSmallBall::effect(){
    if(frameCounter == 0){
        ball->setTexture("../assets/images/smallBall.png");
        ball->setSpriteTxRect(sf::IntRect(0, 0, 9,9));
        active = true;
    }
    frameCounter++;
    if(frameCounter > 600){
        frameCounter = 0;
        ball->setTexture("../assets/images/58-Breakout-Tiles.png");
        ball->setSpriteTxRect(sf::IntRect(0, 0, 18,18));
        active = false;
    }
}