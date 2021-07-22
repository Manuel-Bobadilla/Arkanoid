//
// Created by Facundo Barafani on 9/5/21.
//

#ifndef INCLUDE_MENUSTATE_H
#define INCLUDE_MENUSTATE_H

#include "../Game.h"
#include "../State.h"
#include <SFML/Graphics.hpp>


class MenuState: public State {
private:
    GameDataPtr _data;
    bool isSoundEnabled();
    sf::Sprite _background;
    sf::Sprite _gameIcon;
    sf::Sprite _soundIcon;
    sf::Text _playButton;
    sf::Text _quitButton;
    sf::Music gameMusic;
    sf::SoundBuffer selectSB;
    sf::Sound selectSound;
public:
    MenuState(GameDataPtr data);
    void init();
    void handleInput();
    void update();
    void draw();
};


#endif //INCLUDE_MENUSTATE_H
