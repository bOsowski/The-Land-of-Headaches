//
// Created by Bartosz Osowski on 08/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#include "AnimationComponent.hpp"

AnimationComponent::AnimationComponent(sf::Sprite *_sprite, float _frameChangeTime, int _frameCount)
:
TextureComponent(_sprite),
frameChangeTime(_frameChangeTime),
frameWidth(_sprite->getTexture()->getSize().x / _frameCount),
frameHeight(_sprite->getTexture()->getSize().y),
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
