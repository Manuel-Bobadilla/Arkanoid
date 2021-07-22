//
// Created by Manuel on 30/5/2021.
//

#ifndef INCLUDE_POWERUPSMALLBASE_H
#define INCLUDE_POWERUPSMALLBASE_H

#include "../Player.h"
#include "../Powerup.h"

class PowerupSmallBase: public Powerup{
protected:
    Player *player;
    int frameCounter;
public:
    PowerupSmallBase(Player &p);
    void effect() override;
};

#endif//INCLUDE_POWERUPSMALLBASE_H
