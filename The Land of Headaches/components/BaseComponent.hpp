//
// Created by Bartosz Osowski on 07/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#ifndef THE_LAND_OF_HEADACHES_BASECOMPONENT_HPP
#define THE_LAND_OF_HEADACHES_BASECOMPONENT_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include "GameObject.hpp"

class GameObject;

class BaseComponent {

public:
    BaseComponent(std::string name);

    virtual void update(float deltaTime) = 0;

    virtual void render(sf::RenderWindow& window) = 0;

    std::string name();

    GameObject* delegate;

private:
    std::string _name;
};


#endif //THE_LAND_OF_HEADACHES_BASECOMPONENT_HPP
