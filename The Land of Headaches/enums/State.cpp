//
// Created by Bartosz Osowski on 09/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#include "State.hpp"

const std::string& State::name() const{
    switch(index) {
        case IDLE: return *new std::string("idle");
        case WALK: return *new std::string("walk");
    }
}