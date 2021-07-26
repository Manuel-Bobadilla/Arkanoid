//
// Created by Manuel on 3/6/2021.
//

#include "PowerupBaseShoot.h"

PowerupBaseShoot::PowerupBaseShoot(Player &p,std::vector<Bullet> &b, BulletTextureManager &txb) : Powerup(){
    active = false;
    bullets = &b;
    player = &p;
    txBullets = &txb;
    frameCounter = 0;
    setTexture("../assets/images/26-Breakout-Tiles.png");
    setSpriteTxRect(sf::IntRect (0,0,18,18));
}
void PowerupBaseShoot::effect() {
    if(frameCounter == 0){
        playerShooter = new PlayerShooter(*player);
        active = true;
    }
    if(frameCounter % 100 == 0){
        Bullet* balas = playerShooter->shoot();
        balas[0].setTexture(txBullets->getTextureBullet());
        balas[1].setTexture(txBullets->getTextureBullet());
        bullets->push_back(balas[0]);
        bullets->push_back(balas[1]);
    }
    frameCounter++;
    if(frameCounter > 600){
        frameCounter = 0;
        if(player->getSprite().getTextureRect().width == 68){
            player->setContainerSelected(0);
        }
        active = false;
    }
}
