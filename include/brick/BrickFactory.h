//
// Created by juandubowez on 15/5/21.
//

#ifndef INCLUDE_BRICKFACTORY_H
#define INCLUDE_BRICKFACTORY_H

#include "Brick.h"
#include "BorderBrick.h"
#include "MapBrick.h"
#include "BrokenBrick.h"
#include "SFML/Graphics.hpp"
#include <string>
#include <tmxlite/Layer.hpp>
#include <tmxlite/ObjectGroup.hpp>
#include <tmxlite/TileLayer.hpp>
#include <unordered_map>

enum BrickId {
    borderBrick,
    blueMapBrick,
    purpleMapBrick,
    greenMapBrick,
    brokenBrick,
};

class BrickFactory {
private:
    std::unordered_map<BrickId, Brick*> brickHashMap;
public:
    virtual ~BrickFactory();
    Brick* getBrick(BrickId id);
};


#endif//PROJECTTEMAPLATE_BRICKFACTORY_H
