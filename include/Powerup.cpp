//
// Created by Manuel on 25/5/2021.
//

#include "Powerup.h"
Powerup::Powerup(){
    vel.x = 0;
    vel.y = 2;
}
void Powerup::setTexture(std::string path){
    tx.loadFromFile(path);
    sp.setTexture(tx);
}
void Powerup::setPosition(tmx::Vector2f p){
    pos = p;
    sp.setPosition(p.x, p.y);
}
sf::Texture Powerup::getTexture(){
    return tx;
}
tmx::Vector2f Powerup::getPosition(){
    return pos;
}
void Powerup::setSpriteTxRect(sf::IntRect r){
    sp.setTextureRect(r);
}
sf::Sprite &Powerup::getSprite(){
    return sp;
}
void Powerup::setVelocity(tmx::Vector2f v){
    vel = v;
}
tmx::Vector2f Powerup::getVelocity(){
    return vel;
}
void Powerup::move(){
    pos.x += vel.x;
    pos.y += vel.y;
}
bool Powerup::isActive(){
    return active;
}