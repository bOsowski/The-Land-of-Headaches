//
// Created by Bartosz Osowski on 07/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#ifndef THE_LAND_OF_HEADACHES_GAMEOBJECT_HPP
#define THE_LAND_OF_HEADACHES_GAMEOBJECT_HPP

#include <map>
#include "BaseComponent.hpp"

class TransformComponent;
class BaseComponent;

class GameObject {

public:
    GameObject(TransformComponent* transformComponent, int _layer);
    void addComponent(BaseComponent* component);
    const std::map<std::string, BaseComponent*> getComponents();
    TransformComponent* transform() const;
    void instantiate();
    int layer;

protected:
    TransformComponent* _transform;

private:
    std::map<std::string, BaseComponent*> components;
};




#endif //THE_LAND_OF_HEADACHES_GAMEOBJECT_HPP
