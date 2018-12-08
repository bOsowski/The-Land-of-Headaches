//
// Created by Bartosz Osowski on 07/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#include "World.hpp"

World::World() : window(sf::VideoMode(800, 600), "The Land of Headaches") {
    window.setActive(true);

    GameObject temp = GameObject();
    GameObject tempp;
    gameObjects.push_back(temp);
}

void World::update() {
    sf::Event event;
    while(window.pollEvent(event)){
        if (sf::Event::Closed == event.type) window.close();
    }

    for(auto object: gameObjects){
        for(auto component: object.components){
            component.second->update(0);
        }
    }
}

void World::render() {
    for(auto object: gameObjects){
        for(auto component: object.components){
            if(component.second->name() == "TextureComponent"){
                window.draw(*((TextureComponent*)component.second));
            }
        }
    }
}

bool World::isOpened() {
    return window.isOpen();
}

