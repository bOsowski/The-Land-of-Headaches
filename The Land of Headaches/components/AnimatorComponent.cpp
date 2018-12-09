//
// Created by Bartosz Osowski on 09/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#include "AnimatorComponent.hpp"

AnimatorComponent::AnimatorComponent(std::string stateAnimationName, float _frameChangeTime, int frameCount)
        : AnimationComponent("undefined.png", _frameChangeTime, frameCount) {
}
