#ifndef INCLUDE_GAME_H
#define INCLUDE_GAME_H

#include "StateMachine.h"
#include "manager/ActionManager.h"
#include "manager/AssetManager.h"
#include "manager/CollisionManager.h"
#include "manager/InputManager.h"
#include "manager/SoundManager.h"
#include "manager/TextureManager.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <memory>
#include <string>

struct GameData {
    StateMachine machine;
    sf::RenderWindow window;
    AssetManager assets;
    InputManager input;
    SoundManager sound;
};

typedef std::shared_ptr<GameData> GameDataPtr;

class Game {
private:
    const float dt = 1.0f / 60.0f;// tiempo delta (60fps)
    sf::Clock _clock;
    GameDataPtr _data = std::make_shared<GameData>();
    void run();
public:
    Game(int width, int height, std::string title);
};



#endif//INCLUDE_GAME_H
