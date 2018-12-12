//
// Created by Bartosz Osowski on 11/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#ifndef THE_LAND_OF_HEADACHES_DUNGEONCELL_HPP
#define THE_LAND_OF_HEADACHES_DUNGEONCELL_HPP


#include "GameObject.hpp"

class DungeonCell{

private:

public:
    GameObject* cell;
    std::map<Direction, GameObject*> walls;
    DungeonCell(sf::Vector2f position);

private:
    void addWall(Direction direction);
};

#endif //THE_LAND_OF_HEADACHES_DUNGEONCELL_HPP
