//
// Created by Bartosz Osowski on 14/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#include "DungeonRoom.hpp"

DungeonRoom::DungeonRoom(unsigned int _minRoomSize, unsigned int _maxRoomSize, sf::FloatRect *_parentArea, std::vector<DungeonRoom*>* _dungeonRooms)
    :
    minRoomSize(_minRoomSize),
    maxRoomSize(_maxRoomSize),
    parentArea(_parentArea),
    dungeonRooms(_dungeonRooms),
    bounds(sf::FloatRect())
    {
        bounds.width = getRandom(minRoomSize, maxRoomSize);
        bounds.height = getRandom(minRoomSize, maxRoomSize);
       // std::cout<<"Bound height = "<<bounds.height<<std::endl;
        //std::cout<<"Bound width = "<<bounds.width<<std::endl;
        float x = ((getRandom(parentArea->left, (parentArea->left + parentArea->width - bounds.width*tileSize.x)) + tileSize.x/2) / tileSize.x) * tileSize.x;
        float y = ((getRandom(parentArea->top-parentArea->height+bounds.height*tileSize.x, (parentArea->top-bounds.height*tileSize.x)) + tileSize.x/2) / tileSize.x) * tileSize.x;
        bounds.left = x;
        bounds.top = y;
    }

// Returns true if two rectangles (l1, r1) and (l2, r2) overlap
bool doOverlap(sf::FloatRect RectA, sf::FloatRect RectB) {
    return (RectA.left < RectB.left+RectB.width && RectA.left+RectA.width > RectB.left &&
            RectA.top > RectB.top-RectB.height && RectA.top-RectA.height < RectB.top);
}

        bool DungeonRoom::create(){
        //check if the generated room is colliding with other rooms

        for (auto otherRoom: *dungeonRooms) {
            //std::cout<<"Rooms intersect? " << doOverlap(bounds, otherRoom->bounds) << "\n";
            if (doOverlap(bounds, otherRoom->bounds)) {
                //printf("Failed to create a room. Room intersects.\n");
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
        //printf("Successfully created a room.\n");
        return true;
    }

    void DungeonRoom::insertRoom(sf::Vector2f pos){
        DungeonCell* cell = new DungeonCell(sf::Vector2f(pos.x, pos.y));
        cells.insert(std::pair<sf::Vector2f*, DungeonCell*>(new sf::Vector2f(cell->cell->transform()->body->GetPosition().x,cell->cell->transform()->body->GetPosition().y), cell));
    }