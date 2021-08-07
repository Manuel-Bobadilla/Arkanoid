#ifndef INCLUDE_BRICKINTERFACE_H
#define INCLUDE_BRICKINTERFACE_H

#include "Brick.h"
#include "BorderBrick.h"
#include "MapBrick.h"
#include "BrokenBrick.h"
#include <vector>

class BrickInterface {
private:
    std::vector<BorderBrick*> borderB;
    std::vector<MapBrick*> mapB;
    std::vector<BrokenBrick*> brokenB;
public:
    void storeBrick(Brick* brick,sf::Vector2f pos);
    std::vector<BorderBrick*> &getBorderb();
    std::vector<MapBrick*> &getMapb();
    std::vector<BrokenBrick*> &getBrokenb();
};


#endif  //INCLUDE_BRICKINTERFACE_H
