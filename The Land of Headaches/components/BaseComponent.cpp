//
// Created by Bartosz Osowski on 07/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#include "BaseComponent.hpp"


std::string BaseComponent::name() {
    return _name;
}

BaseComponent::BaseComponent(std::string name, GameObject &_delegate) :
        _name(name),
        delegate(_delegate) {}
