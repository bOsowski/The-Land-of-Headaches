//
// Created by Bartosz Osowski on 10/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#ifndef THE_LAND_OF_HEADACHES_PLAYER_HPP
#define THE_LAND_OF_HEADACHES_PLAYER_HPP

#include "GameObject.hpp"

class Player{
public:
    GameObject* gameObject;
    static Player& instance(){
        static Player* instance = new Player();
        return *instance;
    }

private:
    Player();
};

#endif //THE_LAND_OF_HEADACHES_PLAYER_HPP
