//
// Created by Bartosz Osowski on 08/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#include "AnimationComponent.hpp"

AnimationComponent::AnimationComponent(sf::Sprite *_sprite, GameObject &_delegate)
        : TextureComponent(_sprite, _delegate) {
}
