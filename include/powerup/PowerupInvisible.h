//
// Created by Manuel on 27/5/2021.
//

#ifndef INCLUDE_POWERUPINVISIBLE_H
#define INCLUDE_POWERUPINVISIBLE_H

#include "../Ball.h"
#include "../Powerup.h"

class PowerupInvisible: public Powerup{
protected:
    Ball *ball;
    int frameCounter;
public:
    PowerupInvisible(Ball &b);
    void effect() override;
};

#endif//INCLUDE_POWERUPINVISIBLE_H
