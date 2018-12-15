//
// Created by Bartosz Osowski on 09/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#include <SFML/Window/Keyboard.hpp>
#include "InputComponent.hpp"
#include "TransformComponent.hpp"
#include "AbstractSoundComponent.hpp"
#include "TextureComponent.hpp"
#include "GameObject.hpp"
#include "AnimationComponent.hpp"
#include "World.hpp"

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

//    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
//        auto mousePos = sf::Mouse::getPosition(World::instance().window());
//        std::cout<<"Mouse was clicked at "<< mousePos.x << ", " << mousePos.y <<std::endl;
//    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
//        b2BodyDef* bulletBodyDef = new b2BodyDef();
//        bulletBodyDef->type = b2BodyType::b2_dynamicBody;
//        bulletBodyDef->position = *new b2Vec2(transform.position());
//        GameObject* bullet = new GameObject(new TransformComponent(bulletBodyDef, 100000), 0);
//        TextureComponent* bulletTexture = new TextureComponent("coin_0.png");
//        bullet->addComponent(bulletTexture);
//        bullet->instantiate();
//        bullet->transform()->move(transform.direction.value(), deltaTime);

        class TorchSoundComponent : public AbstractSoundComponent{
        public:
            TorchSoundComponent(){
                sf::Sound* fireSound = addSound("fire.wav", AssetManager::instance().sounds.at("fire.wav"));
                fireSound->setLoop(true);
                fireSound->setMinDistance(100.f);
                fireSound->setAttenuation(1);
                fireSound->play();
                fireSound->setRelativeToListener(true);
            }

            void update(float deltaTime){

            }
        };

        b2BodyDef* torchBodyDef = new b2BodyDef();
        torchBodyDef->type = b2BodyType::b2_staticBody;
        torchBodyDef->position = *new b2Vec2(transform.position());
        GameObject* torch = new GameObject(new TransformComponent(torchBodyDef, 0), 0);
        TextureComponent* animationComponent = new AnimationComponent("torch.png", 0.2, 7);
        torch->addComponent(animationComponent);
        TorchSoundComponent* torchSoundComponent = new TorchSoundComponent();
        torch->addComponent(torchSoundComponent);
        torchSoundComponent->getSound("fire.wav")->setPosition(torchBodyDef->position.x, torchBodyDef->position.y, 0.5);
        torch->instantiate();
    }
}

void InputComponent::render(sf::RenderWindow &window) {}


