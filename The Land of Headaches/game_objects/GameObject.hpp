//
// Created by Bartosz Osowski on 07/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#ifndef THE_LAND_OF_HEADACHES_GAMEOBJECT_HPP
#define THE_LAND_OF_HEADACHES_GAMEOBJECT_HPP

#include <vector>
#include <map>
#include "TransformComponent.hpp"
#include "World.hpp"

class TransformComponent;
class BaseComponent;

class GameObject {

public:
    GameObject(TransformComponent* transformComponent);
    void addComponent(BaseComponent* component);
    const std::map<std::string, BaseComponent*> getComponents();
    TransformComponent* transform();
    void instantiate();

protected:
    TransformComponent* _transform;

private:
    std::map<std::string, BaseComponent*> components;
};




#endif //THE_LAND_OF_HEADACHES_GAMEOBJECT_HPP
