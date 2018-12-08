//
// Created by Bartosz Osowski on 07/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#ifndef THE_LAND_OF_HEADACHES_GAMEOBJECT_HPP
#define THE_LAND_OF_HEADACHES_GAMEOBJECT_HPP

#include <vector>
#include <map>
#include <string>
#include "BaseComponent.hpp"

class BaseComponent;

class GameObject {

public:
    GameObject();
    std::map<std::string, BaseComponent*> components;
};




#endif //THE_LAND_OF_HEADACHES_GAMEOBJECT_HPP
