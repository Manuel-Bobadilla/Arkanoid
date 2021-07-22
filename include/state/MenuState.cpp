//
// Created by Facundo Barafani on 9/5/21.
//

#include "MenuState.h"
#include "../../Constants.h"
#include "GameState.h"
#include <SFML/Audio.hpp>

MenuState::MenuState(GameDataPtr data) : _data(data) {
}

void MenuState::init() {
    this->_data->assets.loadTexture("Background", MENU_BACKGROUND_FILEPATH);
    this->_data->assets.loadTexture("GameIcon", MENU_ICON_FILEPATH);
    this->_data->assets.loadTexture("SoundEnabledIcon", MENU_SOUND_ENABLED_FILEPATH);
    this->_data->assets.loadTexture("SoundDisabledIcon", MENU_SOUND_DISABLED_FILEPATH);
    this->_data->assets.loadFont("RetroFont", RETRO_FONT_FILEPATH);

    this->_background.setTexture(this->_data->assets.getTexture("Background"));

    this->_gameIcon.setTexture(this->_data->assets.getTexture("GameIcon"));
    this->_gameIcon.setScale(0.75,0.75);
    this->_gameIcon.setPosition((SCREEN_WIDTH / 2) - this->_gameIcon.getGlobalBounds().width/2, 40);

    this->_playButton.setFont(this->_data->assets.getFont("RetroFont"));
    this->_playButton.setString("PLAY");
    this->_playButton.setPosition((SCREEN_WIDTH / 2) - this->_playButton.getGlobalBounds().width/2, SCREEN_HEIGHT / 2);
    this->_playButton.setCharacterSize(32);
    this->_playButton.setOutlineColor(sf::Color::Black);

    this->_quitButton.setFont(this->_data->assets.getFont("RetroFont"));
    this->_quitButton.setCharacterSize(24);
    this->_quitButton.setString("QUIT");
    this->_quitButton.setPosition((SCREEN_WIDTH / 2) - (this->_quitButton.getGlobalBounds().width)/2, (SCREEN_HEIGHT / 2) + 120);

    this->_data->sound.playMusic(gameMusic,GAME_MUSIC_FILEPATH);
    this->_data->sound.loadSoundBuffer("SelectSB",SELECTION_SOUND_FILEPATH);
    this->_data->sound.playSound("SelectSB");

    this->_soundIcon.setTexture(this->_data->assets.getTexture("SoundEnabledIcon"));
    this->_soundIcon.setScale(0.25,0.25);
    this->_soundIcon.setPosition(SCREEN_WIDTH - 100, SCREEN_HEIGHT - 200);
}

void MenuState::handleInput() {
    sf::Event event;
    while (this->_data->window.pollEvent(event)) {
        if (sf::Event::Closed == event.type) {
            this->_data->window.close();
        }
        if (this->_data->input.IsTextClicked(this->_playButton, sf::Mouse::Left, this->_data->window))
        {
            this->gameMusic.stop();
            // Cambiar a Game State
            this->_data->machine.addState(StateRef(new GameState(_data)), true);
        }

        if (this->_data->input.IsTextClicked(this->_quitButton, sf::Mouse::Left, this->_data->window))
        {

            this->_data->window.close();
        }

        if (this->_data->input.IsSpriteClicked(this->_soundIcon, sf::Mouse::Left, this->_data->window))
        {
            if (isSoundEnabled()){
                this->_soundIcon.setTexture(this->_data->assets.getTexture("SoundDisabledIcon"));
                this->gameMusic.stop();
            } else {
                this->gameMusic.play();
                this->_soundIcon.setTexture(this->_data->assets.getTexture("SoundEnabledIcon"));
            }


        }

        // En caso de poner el mouse sobre Play se cambia el color a amarillo
        if (this->_data->input.isMouseOnText(this->_playButton, this->_data->window)) {
            this->_playButton.setFillColor(sf::Color().Yellow);
        } else {
            this->_playButton.setFillColor(sf::Color().White);
        }

        // En caso de poner el mouse sobre Quit se cambia el color a amarillo
        if (this->_data->input.isMouseOnText(this->_quitButton, this->_data->window)) {
            this->_quitButton.setFillColor(sf::Color().Yellow);
        } else {
            this->_quitButton.setFillColor(sf::Color().White);
        }
    }
}

void MenuState::update() {

}

void MenuState::draw() {
    this->_data->window.clear();

    this->_data->window.draw(this->_background);
    this->_data->window.draw(this->_gameIcon);
    this->_data->window.draw(this->_playButton);
    this->_data->window.draw(this->_quitButton);
    this->_data->window.draw(this->_soundIcon);

    this->_data->window.display();
}

bool MenuState::isSoundEnabled() {
    if (gameMusic.getStatus() == sf::SoundSource::Playing) {
        return true;
    }
    return false;
}