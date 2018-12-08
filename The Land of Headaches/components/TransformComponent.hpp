//
// Created by Bartosz Osowski on 07/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#ifndef THE_LAND_OF_HEADACHES_TRANSFORMCOMPONENT_HPP
#define THE_LAND_OF_HEADACHES_TRANSFORMCOMPONENT_HPP


#include <Box2D.h>
#include "BaseComponent.hpp"

class GameObject;

class TransformComponent : public BaseComponent{
public:
    TransformComponent(b2Body* _body, GameObject &_delegate);

    void update(float deltaTime);

    const b2Vec2& position();

private:
    b2Body* body;
};


#endif //THE_LAND_OF_HEADACHES_TRANSFORMCOMPONENT_HPP
