//
// Created by Bartosz Osowski on 12/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#include "Dungeon.hpp"
#include "utils.hpp"

Dungeon::Dungeon(sf::FloatRect _bounds, unsigned int _minRoomSize, unsigned int _maxRoomSize, unsigned int _roomCreationAttempts):
    bounds(sf::FloatRect(_bounds.left, _bounds.top, _bounds.width*tileSize.x,_bounds.height*tileSize.y)),
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

    void Dungeon::resetNodes() {
        //std::cout<<"Dungeon cell size when calling method = "<<dungeonCells.size()<<std::endl;

        for (auto& cell: dungeonCells) {
            if (cell.second == nullptr) continue;
            cell.second->F = 0;
            cell.second->G = 0;
            cell.second->H = 0;
            cell.second->parentCell = nullptr;
        }
    }

    void Dungeon::createRooms(){
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

    void Dungeon::createMazes(){
        maze = new DungeonMaze(&bounds, &dungeonRooms);
        for(auto& mazeCell: maze->cells){
            dungeonCells.insert(std::pair<sf::Vector2f*, DungeonCell*>(mazeCell.first, mazeCell.second));
        }
    }

    void Dungeon::createWalls(){
        for(auto& cell: dungeonCells){
            cell.second->createWalls(dungeonCells);
        }
    }
