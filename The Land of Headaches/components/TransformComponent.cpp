//
// Created by Bartosz Osowski on 07/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#include "TransformComponent.hpp"

namespace headache{
    TransformComponent::TransformComponent(GameObject &_delegate)
            : BaseComponent("TransformComponent", _delegate) {
    }

    void TransformComponent::update(float deltaTime) {

    }

}
