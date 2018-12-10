//
// Created by Bartosz Osowski on 07/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#include "World.hpp"

World::World()
:
_window(sf::VideoMode(800, 600), "The Land of Headaches"),
physicsWorld(b2World(b2Vec2()))
{
    _window.setActive(true);
    physicsWorld.SetAllowSleeping(false);
}

void World::update() {
    sf::Event event;
    while(_window.pollEvent(event)){
        // catch the resize events
        if (event.type == sf::Event::Resized)
        {
            // update the view to the new size of the window
            sf::FloatRect visibleArea(0.f, 0.f, event.size.width, event.size.height);
            _window.setView(sf::View(visibleArea));
        }
        if (sf::Event::Closed == event.type) _window.close();
    }

    for(auto object: gameObjects){
        for(auto component: object.getComponents()){
            component.second->update(deltaTime);
        }
    }
    physicsWorld.Step(1.0f/60.0f, 6, 2);
}

void World::render() {
    _window.clear(sf::Color::Black);
    for(auto object: gameObjects){
        for(auto component: object.getComponents()){
            if(dynamic_cast<const TextureComponent*>(component.second) != nullptr){
                _window.draw(*((TextureComponent*)component.second));
            }
        }
    }
    _window.display();
    deltaTime = World::instance().clock.restart().asSeconds();
}

bool World::isOpened() {
    return _window.isOpen();
}

World::~World() {
    printf("World deleting.");
}

sf::RenderWindow& World::window() {
    return *&_window;
}

