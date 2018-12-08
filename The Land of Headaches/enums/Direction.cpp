//
// Created by Bartosz Osowski on 08/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#include "Direction.hpp"

const b2Vec2& Direction::direction() const{
    switch(index) {
        case UP: return b2Vec2(0,1);
        case DOWN: return b2Vec2(0,-1);
        case LEFT: return b2Vec2(-1,0);
        case RIGHT: return b2Vec2(1,0);
    }
}