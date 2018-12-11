//
// Created by Bartosz Osowski on 08/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#ifndef THE_LAND_OF_HEADACHES_ANIMATIONCOMPONENT_HPP
#define THE_LAND_OF_HEADACHES_ANIMATIONCOMPONENT_HPP

#include "TextureComponent.hpp"

class AnimationComponent : public TextureComponent{
public:
    AnimationComponent(std::string textureName, float _frameChangeTime, int frameCount);

    void update(float deltaTime);

private:
    const float frameChangeTime;
    const int frameWidth;
    const int frameHeight;
    const int frameCount;
    float timer;
    int currentFrame;
};

#endif //THE_LAND_OF_HEADACHES_ANIMATIONCOMPONENT_HPP
