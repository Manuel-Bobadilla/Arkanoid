//
// Created by Manuel on 26/7/2021.
//

#include "BulletTextureManager.h"
BulletTextureManager::BulletTextureManager() {
    tx.loadFromFile("../assets/images/61-Breakout-Tiles.png");
}
sf::Texture &BulletTextureManager::getTextureBullet() {
    return tx;
}
