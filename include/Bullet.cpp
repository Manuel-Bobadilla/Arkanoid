//
// Created by Manuel on 3/6/2021.
//

#include "Bullet.h"

Bullet::Bullet(){
    vel.y = -4;
    vel.x = 0;
}

void Bullet::setTexture(std::string path){
    tx.loadFromFile(path);
    sp.setTexture(tx);
}

void Bullet::setPosition(tmx::Vector2f p){
    pos = p;
    sp.setPosition(p.x, p.y);
}

sf::Texture Bullet::getTexture(){
    return tx;
}

tmx::Vector2f Bullet::getPosition(){
    return pos;
}

void Bullet::setSpriteTxRect(sf::IntRect r){
    sp.setTextureRect(r);
}

sf::Sprite &Bullet::getSprite(){
    return sp;
}

void Bullet::setVelocity(tmx::Vector2f v){
    vel = v;
}

tmx::Vector2f Bullet::getVelocity(){
    return vel;
}

void Bullet::move(){
    pos.x += vel.x;
    pos.y += vel.y;
}