//
// Created by Bartosz Osowski on 14/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#ifndef THE_LAND_OF_HEADACHES_AICOMPONENT_H
#define THE_LAND_OF_HEADACHES_AICOMPONENT_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "DungeonCell.hpp"
#include "Dungeon.hpp"
#include "BaseComponent.hpp"

class Dungeon;

class AIComponent : public BaseComponent {
public:
    AIComponent();

    void update(float deltaTime);

    void render(sf::RenderWindow& window){}

    void SetLevel(Dungeon* level);

    void SetTargetPosition(sf::Vector2f targetPosition);

private:
    void UpdatePathFinding();
    void RetracePath(DungeonCell* startCell, DungeonCell* targetCell);
    int GetDistance(DungeonCell* cellA, DungeonCell* cellB);

    Dungeon* level;
    sf::Vector2f m_targetPosition;
    std::vector<DungeonCell*> path;
};



#endif //THE_LAND_OF_HEADACHES_AICOMPONENT_H
