//
// Created by Bartosz Osowski on 12/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#include "DungeonMaze.hpp"
#include "Direction.hpp"


DungeonMaze::DungeonMaze(sf::FloatRect* bounds, std::vector<DungeonRoom*>* _dungeonRooms):
        dungeonRooms(_dungeonRooms),
        parentArea(bounds)
{
    create();
}

void DungeonMaze::create(){
    int x = parentArea->left;
    while (x < (parentArea->left + parentArea->width)) {
        int y = parentArea->top - parentArea->height;
        while (y < (parentArea->top)) {
            DungeonCell* cell;
            std::stack<sf::Vector2f> stack;
            sf::Vector2f currentPosition = sf::Vector2f(x, y);

            if (isFree(currentPosition)) {
                stack.push(currentPosition);
                cell = new DungeonCell(sf::Vector2f(currentPosition.x, currentPosition.y));
                cells.insert(std::pair<sf::Vector2f*, DungeonCell*>(new sf::Vector2f(currentPosition),cell));

                while (!stack.empty()) {
                    std::vector<Direction> directions = {UP, LEFT, RIGHT, DOWN};
                    while (!directions.empty()) {
                        int random = (getRandom(0, (directions.size()-1)));
                        Direction chosenDir = directions.at(random);
                        sf::Vector2f chosenDirValue = sf::Vector2f(chosenDir.value().x*tileSize.x, chosenDir.value().y*tileSize.y);
                        currentPosition = sf::Vector2f(currentPosition.x + chosenDirValue.x*2, currentPosition.y + chosenDirValue.y*2);
                        if (!isMoveValid(currentPosition, chosenDirValue)) {
                            directions.erase(directions.begin()+random);
                            currentPosition = sf::Vector2f(stack.top());
                        } else {
                            World::instance().render();
                            cell = new DungeonCell(sf::Vector2f(currentPosition.x, currentPosition.y));
                            cells.insert(std::pair<sf::Vector2f*, DungeonCell*>(new sf::Vector2f(currentPosition),cell));
                            stack.push(currentPosition);
                            sf::Vector2f* secondTile = new sf::Vector2f(currentPosition.x - chosenDirValue.x, currentPosition.y - chosenDirValue.y);
                            cell = new DungeonCell(sf::Vector2f(secondTile->x, secondTile->y));
                            cells.insert(std::pair<sf::Vector2f*, DungeonCell*>(secondTile,cell));
                            break;
                        }
                    }
                    if (directions.empty()) {
                        currentPosition = sf::Vector2f(stack.top());
                        stack.pop();
                    }
                }
            }
            y += 2*tileSize.y;
        }
        x += 2*tileSize.x;
    }
}

bool DungeonMaze::isMoveValid(sf::Vector2f& currentPos, sf::Vector2f chosenDirValue){
    sf::Vector2f backStep = sf::Vector2f(currentPos.x - chosenDirValue.x, currentPos.y - chosenDirValue.y);
    for(auto cell: cells){
        if(cell.first->x == currentPos.x && cell.first->y == currentPos.y){
            return false;
        }
        if(cell.first->x == backStep.x && cell.first->y == backStep.y){
            return false;
        }
    }
    if (currentPos.x < parentArea->left || currentPos.x > parentArea->left + parentArea->width || currentPos.y < parentArea->top - parentArea->height|| currentPos.y > parentArea->top ) {
        return false;
    }
    for (auto room: *dungeonRooms) {
        if (room->cells.count(&currentPos) || room->cells.count(&backStep)) {
            return false;
        }
    }
    return true;
}

bool DungeonMaze::isFree(sf::Vector2f& pos){
    if (cells.count(&pos)) {
        return false;
    }

    for (auto room: *dungeonRooms) {
        if (room->cells.count(&pos)) {
            return false;
        }
    }
    return true;
}

