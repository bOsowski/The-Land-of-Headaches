//
// Created by Bartosz Osowski on 09/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#ifndef THE_LAND_OF_HEADACHES_ANIMATORCOMPONENT_HPP
#define THE_LAND_OF_HEADACHES_ANIMATORCOMPONENT_HPP


#include "AnimationComponent.hpp"

class AnimatorComponent : public AnimationComponent {
public:
    AnimatorComponent(std::string textureName, float _frameChangeTime, int frameCount);

};


#endif //THE_LAND_OF_HEADACHES_ANIMATORCOMPONENT_HPP
