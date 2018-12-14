//
// Created by Bartosz Osowski on 09/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#ifndef THE_LAND_OF_HEADACHES_ANIMATORCOMPONENT_HPP
#define THE_LAND_OF_HEADACHES_ANIMATORCOMPONENT_HPP


#include "AnimationComponent.hpp"
#include "State.hpp"
#include "Direction.hpp"
#include <map>


class AnimatorComponent : public AnimationComponent {
public:
    AnimatorComponent(std::string stateAnimationName, float _frameChangeTime, int frameCount);

    void update(float deltaTime);

private:
    std::map<State, std::map<Direction, sf::Sprite*>> sprites;
};


#endif //THE_LAND_OF_HEADACHES_ANIMATORCOMPONENT_HPP
