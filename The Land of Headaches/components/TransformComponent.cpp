//
// Created by Bartosz Osowski on 07/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#include "TransformComponent.hpp"

TransformComponent::TransformComponent(b2Body* _body, GameObject &_delegate)
        : BaseComponent("TransformComponent", _delegate),
        body(_body){
}

void TransformComponent::update(float deltaTime) {

}

const b2Vec2& TransformComponent::position() {
    return body->GetPosition();
}

