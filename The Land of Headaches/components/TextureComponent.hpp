//
// Created by Bartosz Osowski on 07/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#ifndef THE_LAND_OF_HEADACHES_GRAPHICSCOMPONENT_HPP
#define THE_LAND_OF_HEADACHES_GRAPHICSCOMPONENT_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "GameObject.hpp"
#include "AssetManager.hpp"

class BaseComponent;

class TextureComponent : public BaseComponent, public sf::Drawable{
public:
    TextureComponent(std::string textureName);

    void update(float deltaTime);

    void render(sf::RenderWindow& window);

    sf::Vector2u dimensions(){
        return sprite->getTexture()->getSize();
    }

    sf::Sprite* sprite;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif //THE_LAND_OF_HEADACHES_GRAPHICSCOMPONENT_HPP