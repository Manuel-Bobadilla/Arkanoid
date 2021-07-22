//
// Created by Facundo Barafani on 21/5/21.
//

#include "PauseState.h"
#include "../../Constants.h"
#include "GameState.h"
#include "MenuState.h"
#include <sstream>

PauseState::PauseState(GameDataPtr data) : _data(data) { }

void PauseState::init()
{
    this->_data->assets.loadTexture("PauseBackground", PAUSE_BACKGROUND_FILEPATH);
    this->_data->assets.loadFont("RetroFont", RETRO_FONT_FILEPATH);

    this->_background.setTexture(this->_data->assets.getTexture("PauseBackground"));
    this->_resumeButton.setFont(this->_data->assets.getFont("RetroFont"));
    this->_resumeButton.setString("RESUME");
    this->_goToMenuButton.setFont(this->_data->assets.getFont("RetroFont"));
    this->_goToMenuButton.setString("GO TO MENU");

    this->_resumeButton.setPosition((this->_data->window.getSize().x / 2) - (this->_resumeButton.getLocalBounds().width / 2), (this->_data->window.getSize().y / 3) - (this->_resumeButton.getLocalBounds().height / 2));
    this->_goToMenuButton.setPosition((this->_data->window.getSize().x / 2) - (this->_goToMenuButton.getLocalBounds().width / 2), (this->_data->window.getSize().y / 3 * 1.5) - (this->_goToMenuButton.getLocalBounds().height / 2));
}

void PauseState::handleInput()
{
    sf::Event event;

    while (this->_data->window.pollEvent(event)) {
        if (sf::Event::Closed == event.type) {
            this->_data->window.close();
        }

        if (this->_data->input.IsTextClicked(this->_resumeButton, sf::Mouse::Left, this->_data->window)) {
            // Resume Game By Popping Of The Current State (Pause State)
            this->_data->machine.removeState();

        }

        if (this->_data->input.IsTextClicked(this->_goToMenuButton, sf::Mouse::Left, this->_data->window)) {
            // Remove The Pause State Off The Stack
            this->_data->machine.removeState();

            // Switch To Main Menu State By Replacing The Game State
            this->_data->machine.addState(StateRef(new MenuState(_data)), true);

        }

        // En caso de poner el mouse sobre Resume se cambia el color a amarillo
        if (this->_data->input.isMouseOnText(this->_resumeButton, this->_data->window)) {
            this->_resumeButton.setFillColor(sf::Color().Yellow);
        } else {
            this->_resumeButton.setFillColor(sf::Color().White);
        }

        // En caso de poner el mouse sobre Go To Menu se cambia el color a amarillo
        if (this->_data->input.isMouseOnText(this->_goToMenuButton, this->_data->window)) {
            this->_goToMenuButton.setFillColor(sf::Color().Yellow);
        } else {
            this->_goToMenuButton.setFillColor(sf::Color().White);
        }
    }
}

void PauseState::update() {

}

void PauseState::draw() {
    this->_data->window.clear(sf::Color::Black);
    this->_data->window.draw(this->_background);
    this->_data->window.draw(this->_resumeButton);
    this->_data->window.draw(this->_goToMenuButton);
    this->_data->window.display();
}