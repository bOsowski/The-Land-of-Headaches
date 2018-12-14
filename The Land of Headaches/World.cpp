//
// Created by Bartosz Osowski on 07/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#include <SFML/Window/Event.hpp>
#include "World.hpp"
#include "TransformComponent.hpp"

World::World()
:
_window(sf::VideoMode(600, 480), "The Land of Headaches"),
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
            //sf::FloatRect visibleArea(0.f, 0.f, event.size.width, event.size.height);
            //_window.setView(sf::View(visibleArea));
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
    sortGameObjects();
    _window.clear(sf::Color::Black);
    physicsWorld.DrawDebugData();
    for(auto object: gameObjects){
        for(auto component: object.getComponents()){
            component.second->render(_window);
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

void World::sortGameObjects() {
    std::sort( gameObjects.begin(), gameObjects.end(), []( const GameObject& lhs, const GameObject& rhs )
    {
        if(lhs.layer != rhs.layer)  return (lhs.layer < rhs.layer);
        else return lhs.transform()->position().y < rhs.transform()->position().y;
    });
}



