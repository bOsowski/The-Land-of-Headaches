//
// Created by Bartosz Osowski on 08/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#ifndef THE_LAND_OF_HEADACHES_UTILS_HPP
#define THE_LAND_OF_HEADACHES_UTILS_HPP

#include <cmath>

 //sf::Vector2i tileSize = sf::Vector2i(32,32);
 const sf::Vector2f tileSize {32,32};


 int getRandom();

/**
 * @param min inclusive
 * @param max inclusive
 * @return random within the range (both inclusive.)
 */
 int getRandom(int min, int max);

//sf::Vector2f* convertVector(b2Vec2 other){
//    return new sf::Vector2f(other.x, other.y);
//}
//
//
//b2Vec2* convertVector(sf::Vector2f other){
//    return new b2Vec2(other.x, other.y);
//}

sf::Vector2f normalize(sf::Vector2f vector) ;

inline float dot(const sf::Vector2f& lv, const sf::Vector2f& rv);

inline float length(const sf::Vector2f& source);


#endif //THE_LAND_OF_HEADACHES_UTILS_HPP
