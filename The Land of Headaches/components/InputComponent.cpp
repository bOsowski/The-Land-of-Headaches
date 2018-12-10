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
    TransformComponent& transform = *delegate->transform();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        transform.move(LEFT.value(), deltaTime);
        transform.direction = LEFT;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        transform.move(RIGHT.value(), deltaTime);
        transform.direction = RIGHT;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        transform.move(UP.value(), deltaTime);
        transform.direction = UP;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        transform.move(DOWN.value(), deltaTime);
        transform.direction = DOWN;
    }
    else{
        transform.move(NONE.value(), deltaTime);
    }
}


