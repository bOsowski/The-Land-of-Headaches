//
// Created by Bartosz Osowski on 07/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#include "World.hpp"

World::World()
:
window(sf::VideoMode(800, 600), "The Land of Headaches"),
physicsWorld(b2World(b2Vec2()))
{
    physicsWorld.SetAllowSleeping(false);
    window.setActive(true);
}

void World::update() {
    std::cout<<"Delta time = "<<deltaTime<<std::endl;
    sf::Event event;
    while(window.pollEvent(event)){
        if (sf::Event::Closed == event.type) window.close();
    }

    for(auto object: gameObjects){
        for(auto component: object.getComponents()){
            component.second->update(deltaTime);
        }
    }
    physicsWorld.Step(deltaTime, 3, 1);
}

void World::render() {
    window.clear(sf::Color::Black);
    for(auto object: gameObjects){
        for(auto component: object.getComponents()){
            if(dynamic_cast<const TextureComponent*>(component.second) != nullptr){
                window.draw(*((TextureComponent*)component.second));
            }
        }
    }
    window.display();
    deltaTime = World::instance().clock.restart().asSeconds();
}

bool World::isOpened() {
    return window.isOpen();
}

World::~World() {
    printf("World deleting.");
}

