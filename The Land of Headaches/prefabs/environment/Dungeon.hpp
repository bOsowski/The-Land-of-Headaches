//
// Created by Bartosz Osowski on 12/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#ifndef THE_LAND_OF_HEADACHES_DUNGEON_HPP
#define THE_LAND_OF_HEADACHES_DUNGEON_HPP


#include <Box2D/Common/b2Math.h>
#include "DungeonCell.hpp"
#include "DungeonRoom.hpp"
#include "DungeonMaze.hpp"

class Dungeon {
public:

    Dungeon(sf::IntRect _bounds, unsigned int _minRoomSize, unsigned int _maxRoomSize, unsigned int _roomCreationAttempts):
    bounds(sf::IntRect(_bounds.left, _bounds.top, _bounds.width*tileSize.x,_bounds.height*tileSize.y)),
    minRoomSize(_minRoomSize),
    maxRoomSize(_maxRoomSize),
    roomCreationAttempts(_roomCreationAttempts)
    {
        printf("creating rooms.\n");
        createRooms();
        printf("created rooms.\n");
        printf("creating mazes.\n");
        createMazes();
        printf("created mazes.\n");
        createWalls();
    }

private:
    sf::IntRect bounds;
    unsigned int minRoomSize;
    unsigned int maxRoomSize;
    unsigned int roomCreationAttempts;

    std::map<sf::Vector2f*, DungeonCell*> dungeonCells;
    std::vector<DungeonRoom*> dungeonRooms;
    DungeonMaze* maze;

    void createRooms(){
        for(unsigned int i = 0; i < roomCreationAttempts; i++){

            DungeonRoom* room = new DungeonRoom(minRoomSize, maxRoomSize, &bounds, &dungeonRooms);
            if (room->create()) {
                dungeonRooms.push_back(room);
                for(auto cell: room->cells){
                    dungeonCells.insert(std::pair<sf::Vector2f*, DungeonCell*>(cell.first, cell.second));
                }
            }
        }
    }

    void createMazes(){
        maze = new DungeonMaze(&bounds, &dungeonRooms);
    }

    void createWalls(){
        for(auto cell: dungeonCells){
            cell.second->createWalls(dungeonCells);
        }
    }
};


#endif //THE_LAND_OF_HEADACHES_DUNGEON_HPP
