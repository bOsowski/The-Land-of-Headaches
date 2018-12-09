//
// Created by Bartosz Osowski on 07/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#include <iostream>
#include "TransformComponent.hpp"

TransformComponent::TransformComponent(b2BodyDef* __bodyDef, float _movementSpeed)
        : BaseComponent("TransformComponent"),
        _bodyDef(__bodyDef),
        movementSpeed(_movementSpeed){
}

void TransformComponent::update(float deltaTime) {

}

const b2Vec2& TransformComponent::position() {
    return body->GetPosition();
}

void TransformComponent::move(Direction direction, float deltaTime) {
    body->SetLinearVelocity(b2Vec2(direction.value().x*movementSpeed*deltaTime, direction.value().y*movementSpeed*deltaTime));
}

const b2BodyDef *TransformComponent::bodyDef() const{
    return _bodyDef;
}