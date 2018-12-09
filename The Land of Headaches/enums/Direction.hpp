//
// Created by Bartosz Osowski on 08/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#ifndef THE_LAND_OF_HEADACHES_DIRECTION_HPP
#define THE_LAND_OF_HEADACHES_DIRECTION_HPP

#include <Box2D.h>
#include <string>

class Direction{
    int index;
public:
    static constexpr int length() {return 5;}
    Direction() : index(0) {}
    constexpr explicit Direction(int index) : index(index) {}
    constexpr operator int() const { return index; }

    const b2Vec2& value() const;
    const std::string& name() const;
};

constexpr Direction UP(0);
constexpr Direction DOWN(1);
constexpr Direction LEFT(2);
constexpr Direction RIGHT(3);
constexpr Direction NONE(4);

#endif //THE_LAND_OF_HEADACHES_DIRECTION_HPP
