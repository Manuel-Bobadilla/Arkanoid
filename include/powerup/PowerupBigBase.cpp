//
// Created by Manuel on 30/5/2021.
//

#include "PowerupBigBase.h"

PowerupBigBase::PowerupBigBase(Player &p) : Powerup(){
    active = false;
    player = &p;
    frameCounter = 0;
    setTexture("../assets/images/22-Breakout-Tiles.png");
    setSpriteTxRect(sf::IntRect (0,0,18,18));
}
void PowerupBigBase::effect() {
    if(frameCounter == 0){
        player->setContainerSelected(1);
        if (player->getTextureContainer(player->getContainerSelected()).isEmpty()) {
            sf::Texture t;
            t.loadFromFile("../assets/images/baseGrande1.png");
            player->getTextureContainer(player->getContainerSelected()).add(t);
            t.loadFromFile("../assets/images/baseGrande2.png");
            player->getTextureContainer(player->getContainerSelected()).add(t);
            t.loadFromFile("../assets/images/baseGrande3.png");
            player->getTextureContainer(player->getContainerSelected()).add(t);
        }
        player->setSpriteTxRect(sf::IntRect(0, 0, 97,18));
        active = true;
    }
    frameCounter++;
    if(frameCounter > 600){
        frameCounter = 0;
        if(player->getSprite().getTextureRect().width == 97){
            player->setContainerSelected(0);
            player->setSpriteTxRect(sf::IntRect(0, 0, 68,18));
        }
        active = false;
    }
}