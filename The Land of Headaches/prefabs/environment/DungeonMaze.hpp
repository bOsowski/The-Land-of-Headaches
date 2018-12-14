//
// Created by Bartosz Osowski on 12/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#ifndef THE_LAND_OF_HEADACHES_DUNGEONMAZE_HPP
#define THE_LAND_OF_HEADACHES_DUNGEONMAZE_HPP

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stack>
#include "World.hpp"
#include "DungeonRoom.hpp"
#include "DungeonCell.hpp"

class DungeonMaze {
public:
    DungeonMaze(sf::IntRect* bounds, std::vector<DungeonRoom*>* _dungeonRooms);

    std::map<sf::Vector2f*, DungeonCell*> cells;

    void create();

private:
    sf::IntRect* parentArea;
    std::vector<DungeonRoom*>* dungeonRooms;


    bool isMoveValid(sf::Vector2f& currentPos, sf::Vector2f chosenDirValue);

    bool isFree(sf::Vector2f& pos);

};


#endif //THE_LAND_OF_HEADACHES_DUNGEONMAZE_HPP
