//
// Created by Bartosz Osowski on 07/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#ifndef THE_LAND_OF_HEADACHES_WORLD_HPP
#define THE_LAND_OF_HEADACHES_WORLD_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include "TextureComponent.hpp"
#include "GameObject.hpp"

class World {

public:

    std::vector<GameObject> gameObjects;

    void update();

    void render();

    bool isOpened();

    static World& instance(){
        static World* instance = new World();
        return *instance;
    }

    b2World physicsWorld;

private:
    World();
    World(const World& other) = delete;

    sf::RenderWindow window;

    sf::Clock clock;
    float deltaTime;
};



#endif //THE_LAND_OF_HEADACHES_WORLD_HPP
