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
        delegate->transform()->move(LEFT);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        delegate->transform()->move(RIGHT);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        delegate->transform()->move(UP);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        delegate->transform()->move(DOWN);
    }
    else{
        delegate->transform()->move(NONE);
    }
}


