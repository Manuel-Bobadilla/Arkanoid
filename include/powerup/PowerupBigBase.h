//
// Created by Manuel on 30/5/2021.
//

#ifndef INCLUDE_POWERUPBIGBASE_H
#define INCLUDE_POWERUPBIGBASE_H

#include "../Player.h"
#include "../Powerup.h"

class PowerupBigBase: public Powerup{
protected:
    Player *player;
    int frameCounter;
public:
    PowerupBigBase(Player &p);
    void effect() override;
};

#endif//INCLUDE_POWERUPBIGBASE_H
