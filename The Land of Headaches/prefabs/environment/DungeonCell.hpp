//
// Created by Bartosz Osowski on 11/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#ifndef THE_LAND_OF_HEADACHES_DUNGEONCELL_HPP
#define THE_LAND_OF_HEADACHES_DUNGEONCELL_HPP

#include "GameObject.hpp"
#include "Direction.hpp"
#include "utils.hpp"
#include "TransformComponent.hpp"

class DungeonCell{

public:
    int H;
    int G;
    int F;
    DungeonCell* parentCell;

    GameObject* cell;
    std::map<Direction, GameObject*> walls;
    DungeonCell(sf::Vector2f position);
    void createWalls(std::map<sf::Vector2f*, DungeonCell*>& dungeonCells);

    std::vector<DungeonCell*> getNeighbours(std::map<sf::Vector2f*, DungeonCell*> otherCells);


private:
    void addWall(Direction direction);
};

#endif //THE_LAND_OF_HEADACHES_DUNGEONCELL_HPP
