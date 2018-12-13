//
// Created by Bartosz Osowski on 13/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#include "AbstractSoundComponent.hpp"

AbstractSoundComponent::AbstractSoundComponent() : BaseComponent("SoundComponent") {
}

void AbstractSoundComponent::addSound(std::string soundName, sf::SoundBuffer* buffer) {
    sf::Sound* sound = new sf::Sound();
    sound->setBuffer(*buffer);
    sounds.insert(std::pair<std::string, sf::Sound*>(soundName, sound));
}
