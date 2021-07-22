//
// Created by Manuel on 30/5/2021.
//

#include "PowerupSmallBase.h"

PowerupSmallBase::PowerupSmallBase(Player &p) : Powerup(){
    active = false;
    player = &p;
    frameCounter = 0;
    setTexture("../assets/images/24-Breakout-Tiles.png");
    setSpriteTxRect(sf::IntRect (0,0,18,18));
}
void PowerupSmallBase::effect(){
    if(frameCounter == 0){
        player->setContainerSelected(2);
        if(player->getTextureContainer(player->getContainerSelected()).isEmpty()){
            sf::Texture t;
            t.loadFromFile("../assets/images/57-Breakout-Tiles.png");
            player->getTextureContainer(player->getContainerSelected()).add(t);
        }
        player->setSpriteTxRect(sf::IntRect(0, 0, 32,18));
        active = true;
    }
    frameCounter++;
    if(frameCounter > 600){
        frameCounter = 0;
        if(player->getSprite().getTextureRect().width == 32){
            player->setContainerSelected(0);
            player->setSpriteTxRect(sf::IntRect(0, 0, 68,18));
        }
        active = false;
    }
}