//
// Created by Bartosz Osowski on 07/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#ifndef THE_LAND_OF_HEADACHES_BASECOMPONENT_HPP
#define THE_LAND_OF_HEADACHES_BASECOMPONENT_HPP


#include <string>
#include "GameObject.hpp"

class GameObject;

class BaseComponent {

public:
    BaseComponent(std::string name, GameObject& _delegate);

    virtual void update(float deltaTime) = 0;

    std::string name();

protected:
    GameObject& delegate;

private:
    std::string _name;

};


#endif //THE_LAND_OF_HEADACHES_BASECOMPONENT_HPP
