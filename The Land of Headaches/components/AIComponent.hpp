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

    void SetLevel(Dungeon* _level);

    void SetTargetPosition(const b2Vec2& targetPosition);

private:
    void UpdatePathFinding();
    void RetracePath(DungeonCell* startCell, DungeonCell* targetCell);
    int GetDistance(DungeonCell* cellA, DungeonCell* cellB);
    int GetDistance(sf::Vector2f pt1, sf::Vector2f pt2);

    Dungeon* level;
    const b2Vec2* m_targetPosition;
    std::vector<DungeonCell*> path;
};



#endif //THE_LAND_OF_HEADACHES_AICOMPONENT_H
