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
        transform.direction = LEFT;
        transform.move(LEFT.value(), deltaTime);
        std::cout<<"Moving "<<transform.direction.name()<<std::endl;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        transform.direction = RIGHT;
        transform.move(RIGHT.value(), deltaTime);
        std::cout<<"Moving "<<transform.direction.name()<<std::endl;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        transform.direction = UP;
        transform.move(UP.value(), deltaTime);
        std::cout<<"Moving "<<transform.direction.name()<<std::endl;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        transform.direction = DOWN;
        transform.move(DOWN.value(), deltaTime);
        std::cout<<"Moving "<<transform.direction.name()<<std::endl;
    }
    else{
        transform.move(NONE.value(), deltaTime);
    }
}


