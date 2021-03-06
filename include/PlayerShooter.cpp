//
// Created by Manuel on 3/6/2021.
//

#include "PlayerShooter.h"

PlayerShooter::PlayerShooter(Player &p) {
    player = &p;
    player->setContainerSelected(3);
    if (player->getTextureContainer(player->getContainerSelected()).isEmpty()) {
        sf::Texture t;
        t.loadFromFile("../assets/images/BaseDisparo1.png");
        player->getTextureContainer(3).add(t);
        t.loadFromFile("../assets/images/BaseDisparo2.png");
        player->getTextureContainer(3).add(t);
        t.loadFromFile("../assets/images/BaseDisparo3.png");
        player->getTextureContainer(3).add(t);
    }
}

Bullet* PlayerShooter::shoot() {
    Bullet* bullet = new Bullet[2];
    tmx::Vector2f displacement;
    displacement.x = player->getSprite().getGlobalBounds().width;
    displacement.y = 0;
    bullet[0].setPosition(player->getPosition());
    bullet[1].setPosition(player->getPosition() + displacement);
    return bullet;
}