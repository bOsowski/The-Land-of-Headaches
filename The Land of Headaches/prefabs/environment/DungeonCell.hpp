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
    void createWalls(std::map<sf::Vector2f*, DungeonCell*>& dungeonCells){
        for(int i = 0; i<Direction::length()-1; i++){
            bool hasNeighbour = false;
            for(auto otherCell: dungeonCells){
                if(otherCell.first->x == cell->transform()->position().x+Direction(i).value().x*tileSize.x && otherCell.first->y == cell->transform()->position().y+Direction(i).value().y*tileSize.y){
                    hasNeighbour = true;
                    break;
                }
            }
            if(!hasNeighbour){
                addWall(Direction(i));
            }
        }
    }

    std::vector<DungeonCell*> getNeighbours(std::map<sf::Vector2f*, DungeonCell*> otherCells) {
        std::vector<DungeonCell*> neighbours;
        for (int i = 0; i < Direction::length()-1; i++) {
            sf::Vector2f neighbourPosition = sf::Vector2f(cell->transform()->position().x, cell->transform()->position().y) + sf::Vector2f(Direction(i).value().x, Direction(i).value().y);
            if (otherCells.count(&neighbourPosition)) {
                neighbours.push_back(otherCells.at(&neighbourPosition));
            }
        }
        return neighbours;
    }


private:
    void addWall(Direction direction);
};

#endif //THE_LAND_OF_HEADACHES_DUNGEONCELL_HPP
