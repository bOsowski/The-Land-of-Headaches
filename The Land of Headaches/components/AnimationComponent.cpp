//
// Created by Bartosz Osowski on 08/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#include "AnimationComponent.hpp"

AnimationComponent::AnimationComponent(sf::Texture *texture, float _frameChangeTime, int _frameCount)
:
TextureComponent(texture),
frameChangeTime(_frameChangeTime),
frameWidth(texture->getSize().x / _frameCount),
frameHeight(texture->getSize().y),
frameCount(_frameCount)

{
    sprite->setTextureRect(sf::IntRect(currentFrame, 0, frameWidth, frameHeight));
}

void AnimationComponent::update(float deltaTime) {
    timer += deltaTime;
    if(timer > frameChangeTime){
        if(currentFrame < frameCount){
            currentFrame++;
        }
        else{
            currentFrame = 0;
        }

        sprite->setTextureRect(sf::IntRect(currentFrame, 0 ,frameWidth, frameHeight));
        timer = 0;
    }
    TextureComponent::update(deltaTime);
}
