//
// Created by ginoa on 26/4/2021.
//

#ifndef INCLUDE_ACTIONMANAGER_H
#define INCLUDE_ACTIONMANAGER_H

#include "../Player.h"
#include <vector>

class ActionManager{
private:
    Player* player;
    tmx::Vector2f posicion;
public:
    //Player movement constructor
    ActionManager(Player& p, tmx::Vector2f pos, int window);
};

#endif // INCLUDE_ACTIONMANAGER_H
