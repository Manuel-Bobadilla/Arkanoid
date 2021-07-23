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
    int windowWidth;
public:
    ActionManager(Player& p, int window);//Player movement constructor
    void movePlayer();
};

#endif // INCLUDE_ACTIONMANAGER_H
