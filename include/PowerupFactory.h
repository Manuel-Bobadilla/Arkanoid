//
// Created by Manuel on 25/5/2021.
//

#ifndef INCLUDE_POWERUPFACTORY_H
#define INCLUDE_POWERUPFACTORY_H

#include "powerup/PowerupBigBase.h"
#include "powerup/PowerupInvisible.h"
#include "powerup/PowerupSmallBall.h"
#include "powerup/PowerupSmallBase.h"
#include "powerup/PowerupBaseShoot.h"
#include <cstdlib>
#include <ctime>

class PowerupFactory{
private:
    Ball *ball;
    Player *player;
    std::vector<Bullet> *bullets;
public:
    PowerupFactory(Ball &b, Player &p, std::vector<Bullet> &bu);
    Powerup* getPowerup();
};

#endif//INCLUDE_POWERUPFACTORY_H
