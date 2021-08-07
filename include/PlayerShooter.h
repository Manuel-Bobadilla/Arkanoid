//
// Created by Manuel on 3/6/2021.
//

#ifndef INCLUDE_PLAYERSHOOTER_H
#define INCLUDE_PLAYERSHOOTER_H

#include "Player.h"
#include "Bullet.h"
#include "manager/BulletTextureManager.h"

class PlayerShooter{
private:
    Player* player;
public:
    PlayerShooter(Player& p);
    Bullet* shoot();
};

#endif//INCLUDE_PLAYERSHOOTER_H
