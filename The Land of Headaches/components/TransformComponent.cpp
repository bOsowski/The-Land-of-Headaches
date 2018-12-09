//
// Created by Bartosz Osowski on 07/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#include "TransformComponent.hpp"

TransformComponent::TransformComponent(b2BodyDef* __bodyDef)
        : BaseComponent("TransformComponent"),
        _bodyDef(__bodyDef){
}

void TransformComponent::update(float deltaTime) {

}

const b2Vec2& TransformComponent::position() {
    return body->GetPosition();
}

void TransformComponent::move(Direction direction) {
    body->SetLinearVelocity(direction.direction());
}

const b2BodyDef *TransformComponent::bodyDef() const{
    return _bodyDef;
}

