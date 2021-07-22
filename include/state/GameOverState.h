#ifndef INCLUDE_STATE_GAMEOVERSTATE_H
#define INCLUDE_STATE_GAMEOVERSTATE_H

#include <SFML/Graphics.hpp>
#include "../State.h"
#include "../Game.h"

class GameOverState: public State {
private:
    GameDataPtr _data;
    sf::Sprite background;
    sf::Text retryButton;
    sf::Text homeButton;
public:
    GameOverState(GameDataPtr data);
    void init();
    void handleInput();
    void update();
    void draw();
};


#endif  //INCLUDE_STATE_GAMEOVERSTATE_H
