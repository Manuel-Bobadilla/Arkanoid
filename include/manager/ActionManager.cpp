//
// Created by Facundo Barafani on 14/6/21.
//

#include "ActionManager.h"

ActionManager::ActionManager(Player& p, int window) {
    player = &p;
    windowWidth = window;
}
void ActionManager::movePlayer(){
    tmx::Vector2f posicion = player->getPosition();
// Key Management
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        if (posicion.x > 54){
            posicion.x -= 3;
            player->setPosition(posicion);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        if (windowWidth - posicion.x - 54 > player->getTexture().getSize().x ){
            posicion.x += 3;
            player->setPosition(posicion);
        }
    }
}
