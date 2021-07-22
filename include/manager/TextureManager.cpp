//
// Created by Facundo Barafani on 24/4/21.
//

#include "TextureManager.h"

TextureManager::TextureManager(Player& p, Ball& b, std::vector<Powerup*>& pu, std::vector<Bullet>& bu) {
    player = &p;
    ball = &b;
    powerups = &pu;
    bullets = &bu;
    tmx::Map map;
    tmx::Vector2f displacement; //Avoid collision between the player and the ball at the start of the game
    if(map.load("../assets/map/map.tmx"))
    {
        const auto& layers = map.getLayers();

        tile_size.x = map.getTileSize().x;
        tile_size.y = map.getTileSize().y;

        const auto& tilesets = map.getTilesets();

        displacement.x = 0;
        displacement.y = -18;

        for(const auto& tileset : tilesets) {
//read out tile set properties, load textures etc...

            for (const auto& t: tileset.getTiles()){
//                    std::cout<<t.imagePath<<std::endl;
                if (tileset.getName() == "Fondo"){
//Insertar funcion para el tileset Fondo
                }
                if (tileset.getName() == "Jugador"){
//Insertar funcion para el tileset Jugador
                    player->appendTexture(t.imagePath, player->getContainerSelected());
                    player->setSpriteTxRect(sf::IntRect(0,0,68,18));
                }
                if (tileset.getName() == "Bola"){
                    ball->setTexture(t.imagePath);
                    ball->setSpriteTxRect(sf::IntRect(0,0,18,18));
                }
                if (tileset.getName() == "Ladrillo"){
                    Brick *brick;
                    switch (t.ID) {
                        case 0:
                            brick = brickFactory->getBrick(BrickId::blueMapBrick);
                            brick->setColor("blue");
                            break;
                        case 1:
                            break;
                        case 2:
                            brick = brickFactory->getBrick(BrickId::purpleMapBrick);
                            break;
                        case 3:
                            break;
                        case 4:
                            brick = brickFactory->getBrick(BrickId::greenMapBrick);
                            break;
                        case 5:
                            break;
                        case 6:
                            break;
                    }
                    brick->setTexture(t.imagePath);
                    brick->setSpriteTxRect(sf::IntRect(0,0,54,18));
                }
                if (tileset.getName() == "LadrilloRoto"){
                    Brick* brick = brickFactory->getBrick(BrickId::brokenBrick);
                    brick->setTexture(t.imagePath);
                    brick->setSpriteTxRect(sf::IntRect(0,0,54,18));
                }
                if (tileset.getName() == "LadrilloBorde"){
                    Brick* brick = brickFactory->getBrick(BrickId::borderBrick);
                    brick->setTexture(t.imagePath);
                    brick->setSpriteTxRect(sf::IntRect(0,0,54,36));
                }
            }
            columns = tileset.getColumnCount();
        }
        for(const auto& layer : layers) {
            if (layer->getType() == tmx::Layer::Type::Object) {
                const auto &objectLayer = layer->getLayerAs<tmx::ObjectGroup>();
                const auto &objects = objectLayer.getObjects();
                for (const auto &object : objects) {
//do stuff with object properties
                    if (objectLayer.getName() == "Pelota") {
                        ball->setPosition(object.getPosition() + displacement);
                    }
                    if (objectLayer.getName() == "Jugador") {
                        player->setPosition(object.getPosition());
                    }
                    if (objectLayer.getName() == "Borde") {
// En caso de ser el borde de arriba los bloques se alargan a lo ancho y no a lo largo
                        if (object.getProperties()[0].getStringValue() == "topBorder") {
                            float numberOfBlocks = round(object.getAABB().width/54);

                            for (int i=0;i<numberOfBlocks;i++) {
                                sf::Vector2f pos = sf::Vector2f((object.getAABB().width)-(i*54),object.getAABB().top);
                                Brick* b = brickFactory->getBrick(BrickId::borderBrick) ;
                                brickInterface->storeBrick(b,pos);
                            }

                        } else {
                            float numberOfBlocks = round(object.getAABB().height/36);

                            for (int i=0;i<numberOfBlocks+1;i++) {
                                sf::Vector2f pos = sf::Vector2f((object.getAABB().left),(object.getAABB().height)-(i*36));
                                Brick* b = brickFactory->getBrick(BrickId::borderBrick);
                                brickInterface->storeBrick(b,pos);

                            }
                        }
                    }

                    if (objectLayer.getName() == "Ladrillo") {
                        auto color = object.getProperties().begin()->getStringValue();
                        Brick* b;
                        if (color == "blue") b = brickFactory->getBrick(BrickId::blueMapBrick);

                        if (color == "purple") b = brickFactory->getBrick(BrickId::purpleMapBrick);

                        if (color == "green") b = brickFactory->getBrick(BrickId::greenMapBrick);

                        sf::Vector2f pos = sf::Vector2f(object.getPosition().x,object.getPosition().y);
                        brickInterface->storeBrick(b,pos);
                    }
                }
            } else {
                if (layer->getType() == tmx::Layer::Type::Tile) {
                    const auto &tileLayer = layer->getLayerAs<tmx::TileLayer>();
//read out tile layer properties etc...
                    if (tileLayer.getName() == "Fondo") {
//                        vLayers.emplace_back(tileLayer,backgroundTileSetTx);
                    }
                    if (tileLayer.getName() == "Frente") {
                    }
                }
            }
        }
    }
}

BrickInterface* TextureManager::getBrickInterface(){
    return brickInterface;
}

void TextureManager::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    ball->getSprite().setPosition(ball->getPosition().x, ball->getPosition().y);
    player->getSprite().setPosition(player->getPosition().x, player->getPosition().y);
    target.draw(ball->getSprite());
    target.draw(player->getSprite());
    for (auto & powerup : *powerups){
        powerup->getSprite().setPosition(powerup->getPosition().x, powerup->getPosition().y);
        target.draw(powerup->getSprite());
    }

    for (auto & bullet : *bullets){
        bullet.getSprite().setPosition(bullet.getPosition().x, bullet.getPosition().y);
        target.draw(bullet.getSprite());
    }

    for(const auto &borders : brickInterface->getBorderb()){
        borders->getSprite().setPosition(borders->getPosition().x,borders->getPosition().y);
        target.draw(borders->getSprite());
    }

    for(const auto &mapBricks : brickInterface->getMapb()){
        mapBricks->getSprite().setPosition(mapBricks->getPosition().x,mapBricks->getPosition().y);
        target.draw(mapBricks->getSprite());

    }

    for(const auto &brokenBricks : brickInterface->getBrokenb()){
        brokenBricks->getSprite().setPosition(brokenBricks->getPosition().x,brokenBricks->getPosition().y);
        target.draw(brokenBricks->getSprite());
    }

    target.draw(ball->getSprite());
    target.draw(player->getSprite());
}