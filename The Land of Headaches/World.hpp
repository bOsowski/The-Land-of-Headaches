//
// Created by Bartosz Osowski on 07/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#ifndef THE_LAND_OF_HEADACHES_WORLD_HPP
#define THE_LAND_OF_HEADACHES_WORLD_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <iostream>     //todo: remove this later.
#include <Box2D/Dynamics/b2World.h>
#include <SFML/Network/UdpSocket.hpp>
#include <SFML/Network/TcpListener.hpp>
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

    sf::RenderWindow& window();

    b2World physicsWorld;

    sf::UdpSocket socket;
    std::vector<unsigned short> receivers;

    unsigned long seed;
private:
    float deltaTime;

    ~World();

    World();

    sf::RenderWindow _window;

    sf::Clock clock;

    void sortGameObjects();



};



#endif //THE_LAND_OF_HEADACHES_WORLD_HPP
