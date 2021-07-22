//
// Created by Manuel on 30/5/2021.
//

#ifndef INCLUDE_POWERUPSMALLBALL_H
#define INCLUDE_POWERUPSMALLBALL_H

#include "../Ball.h"
#include "../Powerup.h"

class PowerupSmallBall: public Powerup{
protected:
    Ball *ball;
    int frameCounter;
public:
    PowerupSmallBall(Ball &b);
    void effect() override;
};

#endif//INCLUDE_POWERUPSMALLBALL_H
