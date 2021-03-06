//
// Created by Bartosz Osowski on 09/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#ifndef THE_LAND_OF_HEADACHES_INPUTCOMPONENT_HPP
#define THE_LAND_OF_HEADACHES_INPUTCOMPONENT_HPP


#include "GameObject.hpp"
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class InputComponent : public BaseComponent{
public:
    InputComponent();
    void update(float deltaTime);
    void render(sf::RenderWindow& window);

private:
};


#endif //THE_LAND_OF_HEADACHES_INPUTCOMPONENT_HPP
