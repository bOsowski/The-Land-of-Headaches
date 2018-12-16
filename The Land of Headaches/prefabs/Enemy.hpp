//
// Created by Bartosz Osowski on 15/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#ifndef THE_LAND_OF_HEADACHES_ENEMY_HPP
#define THE_LAND_OF_HEADACHES_ENEMY_HPP


#include "GameObject.hpp"
#include "Dungeon.hpp"

class Enemy {
public:
    Enemy(sf::Vector2f position, Dungeon* level);

public:
    GameObject* gameObject;
};


#endif //THE_LAND_OF_HEADACHES_ENEMY_HPP
