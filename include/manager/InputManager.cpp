//
// Created by facundo on 10/5/21.
//

#include "InputManager.h"




bool InputManager::IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window)
{
    if (sf::Mouse::isButtonPressed(button))
    {
        sf::IntRect playButtonRect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);

        if (playButtonRect.contains(sf::Mouse::getPosition(window)))
        {
            return true;
        }
    }

    return false;
}

bool InputManager::IsTextClicked(sf::Text object, sf::Mouse::Button button, sf::RenderWindow &window) {
    if (sf::Mouse::isButtonPressed(button))
    {
        sf::IntRect playButtonRect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);

        if (playButtonRect.contains(sf::Mouse::getPosition(window)))
        {
            return true;
        }
    }

    return false;
}

sf::Vector2i InputManager::GetMousePosition(sf::RenderWindow &window)
{
    return sf::Mouse::getPosition(window);
}

bool InputManager::isMouseOnSprite(sf::Sprite &sprite, sf::RenderWindow &window) {

    sf::IntRect playButtonRect(sprite.getPosition().x, sprite.getPosition().y, sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);

    if (playButtonRect.contains(sf::Mouse::getPosition(window))) {
        return true;
    }

    return false;
}

bool InputManager::isMouseOnText(sf::Text &text, sf::RenderWindow &window) {

    sf::IntRect playButtonRect(text.getPosition().x, text.getPosition().y, text.getGlobalBounds().width, text.getGlobalBounds().height);

    if (playButtonRect.contains(sf::Mouse::getPosition(window))) {
        return true;
    }

    return false;
}
