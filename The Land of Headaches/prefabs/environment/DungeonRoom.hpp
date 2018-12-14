//
// Created by Bartosz Osowski on 12/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#ifndef THE_LAND_OF_HEADACHES_DUNGEONROOM_HPP
#define THE_LAND_OF_HEADACHES_DUNGEONROOM_HPP

#include <iostream>

class DungeonRoom {
public:
    DungeonRoom(unsigned int _minRoomSize, unsigned int _maxRoomSize, sf::IntRect *_parentArea, std::vector<DungeonRoom*>* _dungeonRooms)
    :
    minRoomSize(_minRoomSize),
    maxRoomSize(_maxRoomSize),
    parentArea(_parentArea),
    dungeonRooms(_dungeonRooms),
    bounds(sf::IntRect())
    {
        bounds.width = getRandom(minRoomSize, maxRoomSize);
        bounds.height = getRandom(minRoomSize, maxRoomSize);
        std::cout<<"Bound height = "<<bounds.height<<std::endl;
        std::cout<<"Bound width = "<<bounds.width<<std::endl;
        int x = ((getRandom(parentArea->left, (parentArea->left + parentArea->width - bounds.width*tileSize.x)) + tileSize.x/2) / tileSize.x) * tileSize.x;
        int y = ((getRandom(parentArea->top-parentArea->height+bounds.height*tileSize.x, (parentArea->top-bounds.height*tileSize.x)) + tileSize.x/2) / tileSize.x) * tileSize.x;
        bounds.left = x;
        bounds.top = y;
    }

    bool create(){
        //check if the generated room is colliding with other rooms
        for (auto &otherRoom: *dungeonRooms) {
            if (bounds.intersects(otherRoom->bounds)) {
                printf("Failed to create a room. Room intersects.\n");
                return false;
            }
        }

        //create the tiles
        int x = 0;
        while (x < bounds.width) {
            int y = 0;
            while (y < bounds.height) {
                insertRoom(sf::Vector2f(bounds.left + x*tileSize.x, bounds.top - y*tileSize.y));
                y ++;
            }
            x ++;
        }
        printf("Successfully created a room.\n");
        return true;
    }

    unsigned int minRoomSize;
    unsigned int maxRoomSize;
    sf::IntRect* parentArea;
    sf::IntRect bounds;

    std::vector<DungeonRoom*>* dungeonRooms;
    std::map<sf::Vector2f*, DungeonCell*> cells;
    void insertRoom(sf::Vector2f pos){
        DungeonCell* cell = new DungeonCell(sf::Vector2f(pos.x, pos.y));
        cells.insert(std::pair<sf::Vector2f*, DungeonCell*>(new sf::Vector2f(cell->cell->transform()->body->GetPosition().x,cell->cell->transform()->body->GetPosition().y), cell));
    }
};


#endif //THE_LAND_OF_HEADACHES_DUNGEONROOM_HPP
