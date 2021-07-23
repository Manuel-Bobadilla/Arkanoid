//
// Created by Manuel on 3/6/2021.
//

#include "PlayerShooter.h"

PlayerShooter::PlayerShooter(Player &p) {
    player = &p;
    player->setContainerSelected(3);
    if (player->getTextureContainer(player->getContainerSelected()).isEmpty()) {
        sf::Texture t;
        t.loadFromFile("../assets/images/53-Breakout-Tiles.png");
        player->getTextureContainer(player->getContainerSelected()).add(t);
    }
}

Bullet* PlayerShooter::shoot() {
    Bullet* bullet = new Bullet[2];
    tmx::Vector2f displacement;
    displacement.x = player->getSprite().getGlobalBounds().width;
    displacement.y = 0;
    bullet[0].setPosition(player->getPosition());
    bullet[1].setPosition(player->getPosition() + displacement);
    for(int i = 0; i < 2 ; i++){
        bullet[i].setTexture("../assets/images/61-Breakout-Tiles.png");
    }
    return bullet;
}