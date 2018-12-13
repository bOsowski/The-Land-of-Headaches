//
// Created by Bartosz Osowski on 08/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#ifndef THE_LAND_OF_HEADACHES_UTILS_HPP
#define THE_LAND_OF_HEADACHES_UTILS_HPP

#include<cstdlib>
#include <ctime>

static sf::Vector2i tileSize = sf::Vector2i(32,32);


static int getRandom(){
    int random = rand();
    //printf("Generated random number = %i\n", random);
    return random;
}


/**
 * @param min inclusive
 * @param max inclusive
 * @return random within the range (both inclusive.)
 */
static int getRandom(int min, int max){
    int random = (getRandom() % (max - min + 1)) + min;
    //printf("Generated random number in range %i - %i = %i\n", min, max, random);
    return random;
}

#endif //THE_LAND_OF_HEADACHES_UTILS_HPP
