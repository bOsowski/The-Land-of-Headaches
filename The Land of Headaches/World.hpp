//
// Created by Bartosz Osowski on 07/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#ifndef THE_LAND_OF_HEADACHES_WORLD_HPP
#define THE_LAND_OF_HEADACHES_WORLD_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include "GraphicsComponent.hpp"
#include "GameObject.hpp"

namespace headache{
    class World {

    public:

        World();

        std::vector<GameObject> gameObjects;

        void update();

        void render();

        bool isOpened();

    private:

        sf::RenderWindow window;

        sf::Clock clock;
        float deltaTime;
    };
}



#endif //THE_LAND_OF_HEADACHES_WORLD_HPP
