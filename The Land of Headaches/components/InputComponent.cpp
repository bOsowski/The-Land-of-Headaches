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
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        transform.direction = RIGHT;
        transform.move(RIGHT.value(), deltaTime);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        transform.direction = UP;
        transform.move(UP.value(), deltaTime);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        transform.direction = DOWN;
        transform.move(DOWN.value(), deltaTime);
    }
    else{
        transform.move(NONE.value(), deltaTime);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        b2BodyDef* bulletBodyDef = new b2BodyDef();
        bulletBodyDef->type = b2BodyType::b2_dynamicBody;
        bulletBodyDef->position = *new b2Vec2(transform.position());
        GameObject* bullet = new GameObject(new TransformComponent(bulletBodyDef, 100000), 0);
        TextureComponent* bulletTexture = new TextureComponent("coin_0.png");
        bullet->addComponent(bulletTexture);
        bullet->instantiate();
        bullet->transform()->move(transform.direction.value(), deltaTime);
    }
}

void InputComponent::render(sf::RenderWindow &window) {}


