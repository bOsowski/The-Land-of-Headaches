//
// Created by Bartosz Osowski on 13/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#ifndef THE_LAND_OF_HEADACHES_SOUNDCOMPONENT_HPP
#define THE_LAND_OF_HEADACHES_SOUNDCOMPONENT_HPP


#include <SFML/Audio/SoundBuffer.hpp>
#include <map>
#include "BaseComponent.hpp"
#include <SFML/Audio/Sound.hpp>

class AbstractSoundComponent : public BaseComponent{
public:
    AbstractSoundComponent();
    void render(sf::RenderWindow& window){}
    void addSound(std::string soundName, sf::SoundBuffer* buffer);

protected:
    std::map<std::string, sf::Sound*> sounds;
};


#endif //THE_LAND_OF_HEADACHES_SOUNDCOMPONENT_HPP
