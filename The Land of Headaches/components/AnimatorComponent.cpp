//
// Created by Bartosz Osowski on 09/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#include "AnimatorComponent.hpp"
#include "TransformComponent.hpp"

AnimatorComponent::AnimatorComponent(std::string stateAnimationName, float _frameChangeTime, int frameCount)
        : AnimationComponent(stateAnimationName+"_"+IDLE.name()+"_"+DOWN.name()+".png", _frameChangeTime, frameCount) {

    //load in the sprites per state per direction. The convention is: 'stateAnimationName_state_direction.png'
    for(int i = 0; i < State::length(); i++){
        sprites.insert(std::pair<State, std::map<Direction, sf::Sprite*>>(State(i), *new std::map<Direction, sf::Sprite*>()));
        for(int j = 0; j < Direction::length()-1; j++){
            sprites.at(State(i)).insert(std::pair<Direction, sf::Sprite*>(Direction(j), new sf::Sprite(AssetManager::instance().textures.at(stateAnimationName+"_"+State(i).name()+"_"+Direction(j).name()+".png"))));
            std::cout<<"map: "<<State(i).name()<<" >> "<<Direction(j).name() << ".\n";
        }
    }
}

void AnimatorComponent::update(float deltaTime) {
    if(delegate->transform()->body->GetLinearVelocity().x == 0 && delegate->transform()->body->GetLinearVelocity().y == 0){
        sprite = sprites.at(IDLE).at(delegate->transform()->direction);
    }
    else{
        sprite = sprites.at(WALK).at(delegate->transform()->direction);
    }
    AnimationComponent::update(deltaTime);
}


