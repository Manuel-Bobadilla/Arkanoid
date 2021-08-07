//
// Created by Facundo Barafani on 27/5/21.
//

#include "BrickInterface.h"

void BrickInterface::storeBrick(Brick* brick,sf::Vector2f pos){
    switch (brick->getId()) {
        case 0: {
            BorderBrick* b = new BorderBrick();
            b->setTexture(brick->getTexture());
            b->setPosition(pos);
            b->setId(0);
            borderB.push_back(b);
            break;
        }
        case 1:
        case 2:
        case 3:
        case 4:
        {
            MapBrick* mB = new MapBrick();
            mB->setTexture(brick->getTexture());
            mB->setPosition(pos);
            mB->setId(1);
            mapB.push_back(mB);
            break;
        }

        case 5: {
            BrokenBrick* bB = new BrokenBrick();
            bB->setTexture(brick->getTexture());
            bB->setPosition(pos);
            bB->setId(2);
            brokenB.push_back(bB);
            break;
        }
        default:
            throw 1;
    }
}

std::vector<BorderBrick*> &BrickInterface::getBorderb() {
    return borderB;
}

std::vector<MapBrick*> &BrickInterface::getMapb() {
    return mapB;
}

std::vector<BrokenBrick*> &BrickInterface::getBrokenb() {
    return brokenB;
}