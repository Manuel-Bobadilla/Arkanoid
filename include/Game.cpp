//
// Created by juandubowez on 2/5/21.
//

#include "Game.h"
#include "state/MenuState.h"
#include <SFML/Graphics.hpp>

Game::Game(int width, int height, std::string title) {
    _data->window.create(sf::VideoMode(width,height), title, sf::Style::Close | sf::Style::Titlebar);
    _data->window.setFramerateLimit(60);
    _data->machine.addState(StateRef(new MenuState(this->_data)));

    this->run();
}

void Game::run() {

    // Set icon
    sf::Image img;
    img.loadFromFile( "../assets/images/icon.png" );
    _data->window.setIcon( 32, 32, img.getPixelsPtr() );

    while (this->_data->window.isOpen()){
        this->_data->machine.processStateChanges();
        this->_data->machine.getActiveState()->handleInput();
        this->_data->machine.getActiveState()->update();
        this->_data->machine.getActiveState()->draw();
    }
}
