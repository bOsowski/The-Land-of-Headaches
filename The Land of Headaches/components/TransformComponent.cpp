//
// Created by Bartosz Osowski on 07/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#include <iostream>
#include "TransformComponent.hpp"

TransformComponent::TransformComponent(b2BodyDef* __bodyDef, float _movementSpeed)
        : BaseComponent("TransformComponent"),
        _bodyDef(__bodyDef),
        movementSpeed(_movementSpeed),
        direction(DOWN){
    std::cout<<"Initially assigned direction = " << direction << "\n";
}

void TransformComponent::update(float deltaTime) {

}

const b2Vec2& TransformComponent::position() {
    return body->GetPosition();
}

void TransformComponent::move(const b2Vec2& velocity, float deltaTime) {
    body->SetLinearVelocity(b2Vec2(velocity.x * deltaTime * movementSpeed, velocity.y * deltaTime * movementSpeed));

    if(velocity.x != 0 || velocity.y != 0){
        std::cout<<"Moving with velocity ("<<velocity.x << ", "<<velocity.y<<")\n";
        std::cout<<"Linear velocity of the body = ("<<body->GetLinearVelocity().x << ", "<<body->GetLinearVelocity().y<<")\n";
    }
}

const b2BodyDef *TransformComponent::bodyDef() const{
    return _bodyDef;
}
