//
// Created by Manuel on 3/6/2021.
//

#ifndef INCLUDE_POWERUPBASESHOOT_H
#define INCLUDE_POWERUPBASESHOOT_H

#include "../Powerup.h"
#include "../PlayerShooter.h"

class PowerupBaseShoot: public Powerup{
protected:
    Player* player;
    PlayerShooter *playerShooter;
    std::vector<Bullet> *bullets;
    int frameCounter;
public:
    PowerupBaseShoot(Player &p, std::vector<Bullet>&b);
    void effect() override;
};

#endif//INCLUDE_POWERUPBASESHOOT_H
