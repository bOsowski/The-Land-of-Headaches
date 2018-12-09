//
// Created by Bartosz Osowski on 09/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#include "InputComponent.hpp"

InputComponent::InputComponent()
:
BaseComponent("InputComponent"){
}

void InputComponent::update(float deltaTime) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        delegate->transform()->move(LEFT, deltaTime);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        delegate->transform()->move(RIGHT, deltaTime);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        delegate->transform()->move(UP, deltaTime);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        delegate->transform()->move(DOWN, deltaTime);
    }
    else{
        delegate->transform()->move(NONE, deltaTime);
    }
}


