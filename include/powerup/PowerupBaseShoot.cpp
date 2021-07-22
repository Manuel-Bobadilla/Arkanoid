//
// Created by Manuel on 3/6/2021.
//

#include "PowerupBaseShoot.h"

PowerupBaseShoot::PowerupBaseShoot(Player &p,std::vector<Bullet> &b) : Powerup(){
    active = false;
    bullets = &b;
    player = &p;
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
        bullets->push_back(playerShooter->shoot()[0]);
        bullets->push_back(playerShooter->shoot()[1]);
    }
    frameCounter++;
    if(frameCounter > 600){
        frameCounter = 0;
        if(player->getSprite().getTextureRect().width == 68){
            player->setTexture("../assets/images/50-Breakout-Tiles.png");
        }
        active = false;
    }
}
