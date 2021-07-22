//
// Created by facundo on 10/5/21.
//

#ifndef INCLUDE_INPUTMANAGER_H
#define INCLUDE_INPUTMANAGER_H

#include <SFML/Graphics.hpp>

class InputManager {
public:
    InputManager() {}
    ~InputManager() {}
    bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);
    bool IsTextClicked(sf::Text object, sf::Mouse::Button button, sf::RenderWindow &window);
    sf::Vector2i GetMousePosition(sf::RenderWindow &window);
    bool isMouseOnSprite(sf::Sprite &sprite, sf::RenderWindow &window);
    bool isMouseOnText(sf::Text &text, sf::RenderWindow &window);
};


#endif //INCLUDE_INPUTMANAGER_H
