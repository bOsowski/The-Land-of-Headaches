//
// Created by Bartosz Osowski on 07/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#ifndef THE_LAND_OF_HEADACHES_WORLD_HPP
#define THE_LAND_OF_HEADACHES_WORLD_HPP

#include <SFML/System/Clock.hpp>
#include "TextureComponent.hpp"
#include "GameObject.hpp"
#include <iostream>     //todo: remove this later.

class World {\

public:

    std::vector<GameObject> gameObjects;

    void update();

    void render();

    bool isOpened();

    static World& instance(){
        static World* instance = new World();
        return *instance;
    }

    sf::RenderWindow& window();

    b2World physicsWorld;

private:
    float deltaTime;

    ~World();

    World();

    sf::RenderWindow _window;

    sf::Clock clock;
};



#endif //THE_LAND_OF_HEADACHES_WORLD_HPP
