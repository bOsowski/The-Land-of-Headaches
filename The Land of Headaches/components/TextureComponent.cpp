//
// Created by Bartosz Osowski on 07/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#include "TextureComponent.hpp"

TextureComponent::TextureComponent(sf::Texture* texture) :
        BaseComponent("TextureComponent"),
        sprite(new sf::Sprite(*texture))
{}

void TextureComponent::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    sprite->setPosition(delegate->transform()->position().x, delegate->transform()->position().y);
    target.draw(*sprite, states);
}

void TextureComponent::update(float deltaTime){}