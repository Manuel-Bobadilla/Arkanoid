//
// Created by juandubowez on 2/5/21.
//

#include "Game.h"
#include "state/MenuState.h"
#include <SFML/Graphics.hpp>

Game::Game(int width, int height, std::string title) {
    _data->window.create(sf::VideoMode(width,height), title, sf::Style::Close | sf::Style::Titlebar);
    _data->machine.addState(StateRef(new MenuState(this->_data)));

    this->run();
}

void Game::run() {
    float newTime, frameTime, interpolation;

    // Set icon
    sf::Image img;
    img.loadFromFile( "../assets/images/icon.png" );
    _data->window.setIcon( 32, 32, img.getPixelsPtr() );

    float currentTime = this->_clock.getElapsedTime().asSeconds();
    float accumulator = 0.0f;

    while (this->_data->window.isOpen()){
        this->_data->machine.processStateChanges();

        newTime = this->_clock.getElapsedTime().asSeconds();

        frameTime = newTime - currentTime;

        if (frameTime > 0.25f) {
            frameTime = 0.25f;
        }

        currentTime = newTime;
        accumulator += frameTime;

        while (accumulator >= dt) {
            this->_data->machine.getActiveState()->handleInput();
            this->_data->machine.getActiveState()->update(dt);

            accumulator -= dt;
        }

        interpolation = accumulator / dt;
        this->_data->machine.getActiveState()->draw(interpolation);
    }
}
