//
// Created by Bartosz Osowski on 08/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#include "Direction.hpp"

const b2Vec2& Direction::value() const{
    switch(index) {
        case UP: return *new b2Vec2(0,-1);
        case DOWN: return *new b2Vec2(0,1);
        case LEFT: return *new b2Vec2(-1,0);
        case RIGHT: return *new b2Vec2(1,0);
        case NONE: return *new b2Vec2(0,0);
    }
}

const std::string& Direction::name() const{
    switch(index) {
        case UP: return *new std::string("up");
        case DOWN: return *new std::string("down");
        case LEFT: return *new std::string("left");
        case RIGHT: return *new std::string("right");
        case NONE: return *new std::string("none");
    }
}
