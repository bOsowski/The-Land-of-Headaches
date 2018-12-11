//
// Created by Bartosz Osowski on 10/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#ifndef THE_LAND_OF_HEADACHES_INFLUENCECOMPONENT_HPP
#define THE_LAND_OF_HEADACHES_INFLUENCECOMPONENT_HPP


#include <SFML/Graphics/Text.hpp>
#include <sstream>
#include "IMap.hpp"
#include "ResourcePath.hpp"
#include "TileMap.hpp"
#include <memory>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <iomanip>
#include "GameObject.hpp"

class GameObject;

class InfluenceComponent : public BaseComponent {
public:
    InfluenceComponent(float _influence);

    void update(float deltaTime);

    void render(sf::RenderWindow& window);

    sf::Text utilityFn(float val, sf::Vector2i pos);

    float influence = 1;

    std::shared_ptr<InfluenceMap> imap;
    TileMap m_map;
    sf::Font font;

    bool showInfluenceMapColours = true;
    bool showInfluenceValues = true;
};


#endif //THE_LAND_OF_HEADACHES_INFLUENCECOMPONENT_HPP
