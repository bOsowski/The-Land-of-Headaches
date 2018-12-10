//
// Created by Bartosz Osowski on 08/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#include "AnimationComponent.hpp"

AnimationComponent::AnimationComponent(std::string textureName, float _frameChangeTime, int _frameCount)
:
TextureComponent(textureName),
frameChangeTime(_frameChangeTime),
frameWidth(sprite->getTexture()->getSize().x / _frameCount),
frameHeight(sprite->getTexture()->getSize().y),
frameCount(_frameCount)
{
    sprite->setTextureRect(sf::IntRect(currentFrame*frameWidth, 0, frameWidth, frameHeight));
}

void AnimationComponent::update(float deltaTime) {
    timer += deltaTime;
    if(timer > frameChangeTime){
        if(currentFrame < frameCount -1){
            currentFrame++;
        }
        else{
            currentFrame = 0;
        }
        timer = 0;
    }
    sprite->setTextureRect(sf::IntRect(currentFrame*frameWidth, 0 ,frameWidth, frameHeight));
    TextureComponent::update(deltaTime);
}
