//
// Created by Bartosz Osowski on 07/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#include "World.hpp"

namespace headache{
    World::World() : window(sf::VideoMode(800, 600), "The Land of Headaches") {

    }

    void World::update() {
        for(auto object: gameObjects){
            for(auto component: object.components){
                component.second->update(0);
            }
        }
    }

    void World::render() {
        for(auto object: gameObjects){
            for(auto component: object.components){
                if(component.second->name() == "GraphicsComponent"){
                    window.draw(*((GraphicsComponent*)component.second));
                }
            }
        }
    }

}
