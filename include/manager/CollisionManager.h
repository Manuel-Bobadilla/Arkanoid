//
// Created by Manuel on 10/5/2021.
//

#ifndef INCLUDE_COLLISIONMANAGER_H
#define INCLUDE_COLLISIONMANAGER_H

#include "../Ball.h"
#include "../Player.h"
#include "../PowerupFactory.h"
#include "../brick/BorderBrick.h"
#include "../brick/BrickInterface.h"
#include <cmath>
#include <cstdlib>
#include <ctime>

class CollisionManager{
private:
    Player *player;
    Ball *ball;
    PowerupFactory* factory;
    std::vector<Powerup*>* powerups;
    std::vector<Bullet>* bullets;
    BrickInterface* brickInterface;
public:
    CollisionManager(Player &p, Ball &b, std::vector<Powerup*> &pu, std::vector<Bullet> &bu);
    void setBrickInterface(BrickInterface* brickInterface);
    void collision();
    bool collisionBlock(Brick &b, int j);
    void collisionPlayer();
    void collisionPowerup(Powerup &p);
    bool collisionBullet(Bullet &b,Brick &br, int i, int j);
};





#endif//PROJECTTEMAPLATE_COLLISIONMANAGER_H
