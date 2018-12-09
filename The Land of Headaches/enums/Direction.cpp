//
// Created by Bartosz Osowski on 08/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#include "Direction.hpp"

const b2Vec2& Direction::direction() const{
    switch(index) {
        case UP: return *new b2Vec2(0,-1);
        case DOWN: return *new b2Vec2(0,1);
        case LEFT: return *new b2Vec2(-1,0);
        case RIGHT: return *new b2Vec2(1,0);
        case NONE: return *new b2Vec2(0,0);
    }
}