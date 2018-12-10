//
// Created by Bartosz Osowski on 07/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#include "TextureComponent.hpp"

TextureComponent::TextureComponent(std::string textureName) :
        BaseComponent("TextureComponent"),
        sprite(new sf::Sprite(AssetManager::instance().textures.at(textureName)))
{}

void TextureComponent::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    sprite->setPosition(delegate->transform()->position().x, delegate->transform()->position().y);
    target.draw(*sprite, states);
}

void TextureComponent::update(float deltaTime){}

void TextureComponent::render(sf::RenderWindow &window) {
    window.draw(*this);
}
