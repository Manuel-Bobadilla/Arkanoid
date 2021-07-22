//
// Created by Facundo Barafani on 21/5/21.
//

#ifndef INCLUDE_PAUSESTATE_H
#define INCLUDE_PAUSESTATE_H

#include "../Game.h"
#include "../State.h"
#include <SFML/Graphics.hpp>

class PauseState: public State {
private:
    GameDataPtr _data;
    bool isSoundEnabled();
    sf::Sprite _background;
    sf::Sprite _soundIcon;
    sf::Text _resumeButton;
    sf::Text _goToMenuButton;
    sf::Music gameMusic;
    sf::SoundBuffer selectSB;
    sf::Sound selectSound;
public:
    PauseState(GameDataPtr data);
    void init();
    void handleInput();
    void update(float dt);
    void draw(float dt);
};


#endif //INCLUDE_PAUSESTATE_H
