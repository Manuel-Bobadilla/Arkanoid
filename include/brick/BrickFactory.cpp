//
// Created by juandubowez on 15/5/21.
//

#include "BrickFactory.h"

Brick* BrickFactory::getBrick(BrickId id){
    Brick* b = NULL;
    if (brickHashMap.find(id) == brickHashMap.end()) {
        switch (id) {
            case BrickId::borderBrick:
                b = new Brick();
                b->setId(BrickId::borderBrick);
                break;
            case BrickId::blueMapBrick:
                b = new Brick();
                b->setId(BrickId::blueMapBrick);
                break;
            case BrickId::purpleMapBrick:
                b = new Brick();
                b->setId(BrickId::purpleMapBrick);
                break;
            case BrickId::greenMapBrick:
                b = new Brick();
                b->setId(BrickId::greenMapBrick);
                break;
            case BrickId::brokenBrick:
                b = new Brick();
                b->setId(BrickId::brokenBrick);
                break;
            default:
                std::cout << "Unreachable code!" << std::endl;
        }
        brickHashMap[id] = b;
    }
    else{
        b = brickHashMap[id];
    }
    return b;
};

BrickFactory::~BrickFactory() {
        while(!brickHashMap.empty())
        {
            std::unordered_map<BrickId, Brick*>::iterator it = brickHashMap.begin();
            delete it->second;
            brickHashMap.erase(it);
        }
}
