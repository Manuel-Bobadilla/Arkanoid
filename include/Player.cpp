#include "Player.h"
#include "manager/animation/Container.h"

void Player::setTexture(std::string path){
    tx.loadFromFile(path);
    sp.setTexture(tx);
}

void Player::setTexture(const sf::Texture& t){
    tx = t;
    sp.setTexture(t);
}
void Player::appendTexture(std::string path, int pos){
    sf::Texture t;
    t.loadFromFile(path);
    txs[pos].add(t);
}

Container<sf::Texture> &Player::getTextureContainer(int pos){
    return txs[pos];
}

void Player::setPosition(tmx::Vector2f p){
    pos = p;
    sp.setPosition(p.x, p.y);
}

sf::Texture Player::getTexture(){
    return tx;
}

tmx::Vector2f Player::getPosition(){
    return pos;
}

void Player::setSpriteTxRect(sf::IntRect r){
    sp.setTextureRect(r);
}

sf::Sprite &Player::getSprite(){
    return sp;
}

void Player::setContainerSelected(int index){
    this->containerSelected = index;
}
int Player::getContainerSelected(){
    return containerSelected;
}
unsigned int Player::getLives() const {
    return lives;
}
void Player::setLives(unsigned int lives) {
    Player::lives = lives;
}
