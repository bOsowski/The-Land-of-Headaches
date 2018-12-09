//
// Created by Bartosz Osowski on 09/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#ifndef THE_LAND_OF_HEADACHES_STATE_HPP
#define THE_LAND_OF_HEADACHES_STATE_HPP

#include <string>

class State{
    int index;
public:
    static constexpr int length() {return 2;}
    State() : index(0) {}
    constexpr explicit State(int index) : index(index) {}
    constexpr operator int() const { return index; }

    const std::string& name() const;
};

constexpr State IDLE(0);
constexpr State WALK(1);



#endif //THE_LAND_OF_HEADACHES_STATE_HPP
