//
// Created by Bartosz Osowski on 08/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#ifndef THE_LAND_OF_HEADACHES_UTILS_HPP
#define THE_LAND_OF_HEADACHES_UTILS_HPP

#include <cmath>
#include "utils.hpp"
#include <SFML/Audio.hpp>
#include <Box2D/Common/b2Math.h>

sf::Vector2i tileSize = sf::Vector2i(32,32);

int getRandom(){
    int random = rand();
    //printf("Generated random number = %i\n", random);
    return random;
}

/**
 * @param min inclusive
 * @param max inclusive
 * @return random within the range (both inclusive.)
 */
int getRandom(int min, int max){
    int random = (getRandom() % (max - min + 1)) + min;
    //printf("Generated random number in range %i - %i = %i\n", min, max, random);
    return random;
}

//sf::Vector2f* convertVector(b2Vec2 other){
//    return new sf::Vector2f(other.x, other.y);
//}
//
//
//b2Vec2* convertVector(sf::Vector2f other){
//    return new b2Vec2(other.x, other.y);
//}

sf::Vector2f normalize(sf::Vector2f vector) {
    float length = sqrt((vector.x * vector.x) + (vector.y * vector.y));
    if (length != 0) return sf::Vector2f(vector.x / length, vector.y / length);
    else return vector;
}

 float dot(const sf::Vector2f& lv, const sf::Vector2f& rv)
{
    return lv.x * rv.x + lv.y * rv.y;
}

float distance(const b2Vec2& a, const b2Vec2& b){
    return sqrt(static_cast<float>(pow((b.x - (a.x)), 2) + pow((b.y - a.y), 2)));
}

 float length(const sf::Vector2f& source)
{
    return std::sqrt(dot(source, source));
}


#endif //THE_LAND_OF_HEADACHES_UTILS_HPP
