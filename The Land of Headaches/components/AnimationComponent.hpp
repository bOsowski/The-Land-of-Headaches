//
// Created by Bartosz Osowski on 08/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#ifndef THE_LAND_OF_HEADACHES_ANIMATIONCOMPONENT_HPP
#define THE_LAND_OF_HEADACHES_ANIMATIONCOMPONENT_HPP

#include "TextureComponent.hpp"

class AnimationComponent : public TextureComponent{
public:
    AnimationComponent(sf::Sprite *_sprite, GameObject &_delegate);


};


#endif //THE_LAND_OF_HEADACHES_ANIMATIONCOMPONENT_HPP
