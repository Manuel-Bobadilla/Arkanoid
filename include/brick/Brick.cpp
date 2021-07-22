//
// Created by juandubowez on 15/5/21.
//

#include "Brick.h"

void Brick::setId(int id){
    this->id = id;
}
unsigned int Brick::getId(){
    return id;
}
void Brick::setTexture(std::string path){
    tx = new sf::Texture;
    tx->loadFromFile(path);
    sp.setTexture(*tx);
}
void Brick::setTexture(sf::Texture &tx){
    this->tx = &tx;
    sp.setTexture(this->tx[0]);
}
sf::Texture &Brick::getTexture(){
    return *tx;
}
void Brick::setSpriteTxRect(sf::IntRect r){
    sp.setTextureRect(r);
}
sf::Sprite &Brick::getSprite(){
    return sp;
}
void Brick::setColor(std::string color){
    this->color = color;
}