//
// Created by Facundo Barafani on 24/4/21.
//

#ifndef INCLUDE_TEXTUREMANAGER_H_
#define INCLUDE_TEXTUREMANAGER_H_

#include "../Ball.h"
#include "../Player.h"
#include "../Powerup.h"
#include "../Bullet.h"
#include "../brick/BrickFactory.h"
#include "../brick/BrickInterface.h"
#include "SFML/Graphics.hpp"
#include <math.h>
#include <string>
#include <tmxlite/Layer.hpp>
#include <tmxlite/Map.hpp>
#include <tmxlite/Object.hpp>
#include <tmxlite/ObjectGroup.hpp>
#include <tmxlite/TileLayer.hpp>
#include <vector>

class TextureManager: public sf::Drawable {
private:
    // Como nosotros tenemos c/ tileset en un archivo distinto tenemos que guardar cada textura en uno solo sino se sobreescriben.
    uint32_t columns;
    sf::Vector2u tile_size;
    Ball* ball;
    Player* player;
    std::vector<Powerup*>* powerups;
    std::vector<Bullet>* bullets;
    BrickFactory* brickFactory = new BrickFactory;
    BrickInterface* brickInterface = new BrickInterface;
protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
public:
    TextureManager(Player& p, Ball& b, std::vector<Powerup*>& pu, std::vector<Bullet>& bu);
    BrickInterface* getBrickInterface();
};
#endif // INCLUDE_TEXTUREMANAGER_H_
