//
// Created by Bartosz Osowski on 12/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#ifndef THE_LAND_OF_HEADACHES_DUNGEONROOM_HPP
#define THE_LAND_OF_HEADACHES_DUNGEONROOM_HPP

#include <iostream>
#include <SFML/Graphics/Rect.hpp>
#include "DungeonCell.hpp"

class DungeonRoom {
public:
    DungeonRoom(unsigned int _minRoomSize, unsigned int _maxRoomSize, sf::IntRect *_parentArea, std::vector<DungeonRoom*>* _dungeonRooms);

    bool create();

    unsigned int minRoomSize;
    unsigned int maxRoomSize;
    sf::IntRect* parentArea;
    sf::IntRect bounds;

    std::vector<DungeonRoom*>* dungeonRooms;
    std::map<sf::Vector2f*, DungeonCell*> cells;
    void insertRoom(sf::Vector2f pos);
};


#endif //THE_LAND_OF_HEADACHES_DUNGEONROOM_HPP
