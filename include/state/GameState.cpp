//
// Created by Facundo Barafani on 14/5/21.
//

#include "GameState.h"
#include "../../Constants.h"
#include "PauseState.h"
#include "GameOverState.h"
#include "conio.h"

GameState::GameState(GameDataPtr data) : _data(data) {
}

void GameState::init() {
    this->playerInitialPos = player.getPosition();
    this->ballInitialPos = ball.getPosition();
    this->ballInitialVel = ball.getVelocity();
    this->_data->assets.loadTexture("Background", GAME_BACKGROUND_FILEPATH);
    this->background.setTexture(this->_data->assets.getTexture("Background"));
    this->_data->assets.loadFont("RetroFont", RETRO_FONT_FILEPATH);

    this->_vidas.setFont(this->_data->assets.getFont("RetroFont"));
    this->_vidas.setCharacterSize(16);
    this->_vidas.setString("VIDAS  ");
    this->_vidas.setPosition((75), (this->_data->window.getSize().y - 75));
    this->_vidas.setFillColor(sf::Color().Red);

    this->_cantVidas.setFont(this->_data->assets.getFont("RetroFont"));
    this->_cantVidas.setCharacterSize(16);
    this->_cantVidas.setString(std::to_string(player.getLives()));
    this->_cantVidas.setPosition((this->_vidas.getPosition().x + this->_vidas.getGlobalBounds().width + 6), (this->_vidas.getPosition().y));
    this->_cantVidas.setFillColor(sf::Color().White);
}

void GameState::handleInput() {
    // TODO: Migrate ActionManager to handleInput State method
    sf::Event event;

    while (this->_data->window.pollEvent(event)) {
        if (sf::Event::Closed == event.type) this->_data->window.close();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
        this->_data->machine.addState(StateRef(new PauseState(_data)), false);
    }
}

void GameState::update() {
    if (counter != player.getContainerSelected()) {
        it = player.getTextureContainer(player.getContainerSelected()).createIterator();
    }

    if (it->getDelay() % 6 == 0){
        it->next();
        if (it->isDone()) {
            it->first();
        }
        player.setTexture(*it->current());
    }

    it->incrementDelay();
    counter = player.getContainerSelected();

    if(ball.getPosition().y > 1100){
        if (player.getLives() == 1){
            this->_data->machine.addState(StateRef(new GameOverState(_data)), true);
        }else {
            player.setPosition(playerInitialPos);
            ball.setPosition(ballInitialPos);
            ball.setVelocity(ballInitialVel);
            player.setLives(player.getLives() - 1);
            this->_cantVidas.setString(std::to_string(player.getLives()));
        }
    }


    brickInterface = tm.getBrickInterface();

    cm.setBrickInterface(brickInterface);

    cm.collision();

    ball.move();

    for(auto & bullet : bullets){
        bullet.move();
    }
  
    for(unsigned int i = 0; i < powerup.size(); i++){
        powerup.at(i)->move();
        if(powerup.at(i)->isActive()){
            powerup.at(i)->effect();
        }
        else{
            if(powerup.at(i)->getPosition().y > 1800){
                powerup.erase(powerup.begin() + i);
            }
        }
    }
    ActionManager(player, this->_data->window.getSize().x);
    if(brickInterface->getMapb().empty()){
        this->_data->machine.addState(StateRef(new GameOverState(_data)), true);
    }
}

void GameState::draw() {
    this->_data->window.clear();
    this->_data->window.draw(background);
    this->_data->window.draw(tm);
    this->_data->window.draw(this->_vidas);
    this->_data->window.draw(this->_cantVidas);
    this->_data->window.display();
}