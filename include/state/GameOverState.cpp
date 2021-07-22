
#include <sstream>
#include "GameOverState.h"
#include "../../Constants.h"
#include "GameState.h"
#include "MenuState.h"

GameOverState::GameOverState(GameDataPtr data) : _data(data) { }

void GameOverState::init()
{
    this->_data->assets.loadTexture("PauseBackground", PAUSE_BACKGROUND_FILEPATH);
    this->_data->assets.loadFont("RetroFont", RETRO_FONT_FILEPATH);

    this->background.setTexture(this->_data->assets.getTexture("PauseBackground"));
    this->retryButton.setFont(this->_data->assets.getFont("RetroFont"));
    this->retryButton.setString("TRY AGAIN");
    this->homeButton.setFont(this->_data->assets.getFont("RetroFont"));
    this->homeButton.setString("GO TO MENU");

    this->retryButton.setPosition((this->_data->window.getSize().x / 2) - (this->retryButton.getLocalBounds().width / 2), (this->_data->window.getSize().y / 3) - (this->retryButton.getLocalBounds().height / 2));
    this->homeButton.setPosition((this->_data->window.getSize().x / 2) - (this->homeButton.getLocalBounds().width / 2), (this->_data->window.getSize().y / 3 * 1.5) - (this->homeButton.getLocalBounds().height / 2));
}

void GameOverState::handleInput()
{
    sf::Event event;

    while (this->_data->window.pollEvent(event)) {
        if (sf::Event::Closed == event.type) {
            this->_data->window.close();
        }

        if (this->_data->input.IsTextClicked(this->retryButton, sf::Mouse::Left, this->_data->window)) {
            // Reinstance Game By Popping Of The Current State with a new Game State (Game State)
            this->_data->machine.addState(StateRef(new GameState(_data)));

        }

        if (this->_data->input.IsTextClicked(this->homeButton, sf::Mouse::Left, this->_data->window)) {
            // Remove The GameOver State Off The Stack
            this->_data->machine.removeState();

            // Switch To Main Menu State By Replacing The Game State
            this->_data->machine.addState(StateRef(new MenuState(_data)), true);

        }

        // En caso de poner el mouse sobre Resume se cambia el color a amarillo
        if (this->_data->input.isMouseOnText(this->retryButton, this->_data->window)) {
            this->retryButton.setFillColor(sf::Color().Yellow);
        } else {
            this->retryButton.setFillColor(sf::Color().White);
        }

        // En caso de poner el mouse sobre Go To Menu se cambia el color a amarillo
        if (this->_data->input.isMouseOnText(this->homeButton, this->_data->window)) {
            this->homeButton.setFillColor(sf::Color().Yellow);
        } else {
            this->homeButton.setFillColor(sf::Color().White);
        }
    }
}

void GameOverState::update() {

}

void GameOverState::draw() {
    this->_data->window.clear(sf::Color::Black);

    this->_data->window.draw(this->background);
    this->_data->window.draw(this->retryButton);
    this->_data->window.draw(this->homeButton);

    this->_data->window.display();
}
