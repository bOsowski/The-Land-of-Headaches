//
// Created by Bartosz Osowski on 11/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#ifndef THE_LAND_OF_HEADACHES_DUNGEONWALL_HPP
#define THE_LAND_OF_HEADACHES_DUNGEONWALL_HPP


#include "GameObject.hpp"

class DungeonWall{
public:
    GameObject* wall;
    DungeonWall(Direction direction);

};


#endif //THE_LAND_OF_HEADACHES_DUNGEONWALL_HPP
