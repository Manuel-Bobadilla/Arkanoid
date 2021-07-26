//
// Created by Manuel on 25/5/2021.
//

#include "PowerupFactory.h"

PowerupFactory::PowerupFactory(Ball &b, Player &p,std::vector<Bullet> &bu){
    ball = &b;
    player = &p;
    bullets = &bu;
}
Powerup* PowerupFactory::getPowerup(){
    srand(time(NULL));

    Powerup *p = nullptr;

    switch (rand() % 1) {
        case 0: p = new PowerupBaseShoot(*player, *bullets, textureBullets);break;
        case 1: p = new PowerupBigBase(*player);break;
        case 2: p = new PowerupInvisible(*ball);break;
        case 3: p = new PowerupSmallBall(*ball);break;
        case 4: p = new PowerupSmallBase(*player);break;
        default: throw 1;
    }


    return p;
}