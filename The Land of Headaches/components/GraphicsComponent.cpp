//
// Created by Bartosz Osowski on 07/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#include "GraphicsComponent.hpp"

namespace headache{
    GraphicsComponent::GraphicsComponent(sf::Sprite* _sprite, GameObject &_delegate) :
            BaseComponent("GraphicsComponent", _delegate),
            sprite(_sprite)
    {}

    void GraphicsComponent::draw(sf::RenderTarget& target, sf::RenderStates states) const{
        target.draw(*sprite, states);
    }

    void GraphicsComponent::update(float deltaTime){

    }
}