//
// Created by Bartosz Osowski on 07/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#include "TextureComponent.hpp"

TextureComponent::TextureComponent(sf::Sprite* _sprite) :
        BaseComponent("GraphicsComponent"),
        sprite(_sprite)
{}

void TextureComponent::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(*sprite, states);
}

void TextureComponent::update(float deltaTime){}