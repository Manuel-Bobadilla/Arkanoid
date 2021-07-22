//
// Created by Facundo Barafani on 14/5/21.
//

#ifndef INCLUDE_GAMESTATE_H
#define INCLUDE_GAMESTATE_H

#include "../Game.h"
#include "../State.h"
#include <SFML/Graphics.hpp>

class GameState: public State {
private:
    GameDataPtr _data;
    Player player;
    Ball ball;
    BrickInterface* brickInterface;
    std::vector<Powerup*> powerup;
    std::vector<Bullet> bullets;
    TextureManager tm = TextureManager(player, ball, powerup, bullets);
    CollisionManager cm = CollisionManager(player, ball, powerup, bullets);
    AnimationManager<sf::Texture, Container<sf::Texture>> *it = player.getTextureContainer(0).createIterator();
    tmx::Vector2f position; //almacena la posicion para modificarla y sobreescribirla
    tmx::Vector2f playerPos;
    tmx::Vector2f ballPosition;
    sf::Sprite background;
    int counter = 0;
    sf::Text _vidas;
    sf::Text _cantVidas;

public:
    GameState(GameDataPtr data);

    void init();

    void handleInput();
    void update(float dt);
    void draw(float dt);
};


#endif //INCLUDE_GAMESTATE_H
