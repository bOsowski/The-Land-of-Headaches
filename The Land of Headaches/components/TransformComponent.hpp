//
// Created by Bartosz Osowski on 07/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#ifndef THE_LAND_OF_HEADACHES_TRANSFORMCOMPONENT_HPP
#define THE_LAND_OF_HEADACHES_TRANSFORMCOMPONENT_HPP

#include "BaseComponent.hpp"
#include "Direction.hpp"

class GameObject;

class TransformComponent : public BaseComponent{
public:
    TransformComponent(b2BodyDef* __bodyDef, float _movementSpeed = 0);

    void update(float deltaTime);

    void move(Direction direction, float deltaTime);

    const b2Vec2& position();

    const b2BodyDef* bodyDef() const;

    b2Body* body;


private:
    b2BodyDef* _bodyDef;
    float movementSpeed;
};


#endif //THE_LAND_OF_HEADACHES_TRANSFORMCOMPONENT_HPP
