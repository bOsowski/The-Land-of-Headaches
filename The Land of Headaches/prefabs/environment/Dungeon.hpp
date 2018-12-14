//
// Created by Bartosz Osowski on 12/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#ifndef THE_LAND_OF_HEADACHES_DUNGEON_HPP
#define THE_LAND_OF_HEADACHES_DUNGEON_HPP

#include "DungeonRoom.hpp"
#include "DungeonMaze.hpp"
#include "DungeonCell.hpp"

class Dungeon {
public:

    std::map<sf::Vector2f*, DungeonCell*> dungeonCells;
    std::vector<DungeonRoom*> dungeonRooms;
    DungeonMaze* maze;
    DungeonCell* lastCell;

    Dungeon(sf::IntRect _bounds, unsigned int _minRoomSize, unsigned int _maxRoomSize, unsigned int _roomCreationAttempts);

    void resetNodes();

private:
    sf::IntRect bounds;
    unsigned int minRoomSize;
    unsigned int maxRoomSize;
    unsigned int roomCreationAttempts;

    void createRooms();

    void createMazes();

    void createWalls();
};


#endif //THE_LAND_OF_HEADACHES_DUNGEON_HPP
