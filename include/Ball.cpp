//
// Created by Facundo Barafani on 24/4/21.
//

#include "Ball.h"

Ball::Ball(){
    vel.y = -5;
    vel.x = 0;
}

void Ball::setTexture(std::string path){
    tx.loadFromFile(path);
    sp.setTexture(tx);
}

void Ball::setTexture(const sf::Texture& t){
    tx = t;
}

void Ball::setPosition(tmx::Vector2f p){
    pos = p;
    sp.setPosition(p.x, p.y);
}

sf::Texture Ball::getTexture(){
    return tx;
}

tmx::Vector2f Ball::getPosition(){
    return pos;
}

void Ball::setSpriteTxRect(sf::IntRect r){
    sp.setTextureRect(r);
}

sf::Sprite &Ball::getSprite(){
    return sp;
}

void Ball::setVelocity(tmx::Vector2f v){
    vel = v;
}

tmx::Vector2f Ball::getVelocity(){
    return vel;
}

void Ball::move(){
    pos.x += vel.x;
    pos.y += vel.y;
}