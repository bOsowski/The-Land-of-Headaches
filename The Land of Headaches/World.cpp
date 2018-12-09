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
    window.setActive(true);
//    b2BodyDef* bodyDef = new b2BodyDef();
//    b2Body* body = new b2Body(bodyDef, );
//    TransformComponent transformComponent = TransformComponent();
}

void World::update() {
    sf::Event event;
    while(window.pollEvent(event)){
        if (sf::Event::Closed == event.type) window.close();
    }

    for(auto object: gameObjects){
        for(auto component: object.getComponents()){
            component.second->update(0);
        }
    }
}

void World::render() {
    for(auto object: gameObjects){
        for(auto component: object.getComponents()){
            if(component.second->name() == "TextureComponent"){
                window.draw(*((TextureComponent*)component.second));
            }
        }
    }
}

bool World::isOpened() {
    return window.isOpen();
}

