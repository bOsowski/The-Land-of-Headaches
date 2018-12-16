//
// Created by Bartosz Osowski on 14/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#include "AIComponent.hpp"
#include "Player.hpp"
#include <cmath>


AIComponent::AIComponent() : BaseComponent("AIComponent") {
}

void AIComponent::update(float deltaTime) {
    level->resetNodes();
    UpdatePathFinding();

    sf::Vector2f selfPosition = sf::Vector2f(delegate->transform()->position().x, delegate->transform()->position().y);
    sf::Vector2f target = sf::Vector2f(path[0]->cell->transform()->position().x-tileSize.x/2, path[0]->cell->transform()->position().y-tileSize.y/2);
    sf::Vector2f position = sf::Vector2f(target.x, target.y);
    sf::Vector2f direction = position - sf::Vector2f(selfPosition.x-tileSize.x/2, selfPosition.y);
    sf::Vector2f normalized = normalize(direction) * delegate->transform()->movementSpeed;
    std::cout<<"Velocity to set = "<<normalized.x<<", " << normalized.y<<"\n";
    delegate->transform()->body->SetLinearVelocity((b2Vec2(normalized.x,normalized.y)));
}

void AIComponent::UpdatePathFinding() {
    DungeonCell* startTile;
    auto shortestDistance = MAXFLOAT;
    for(auto& cell: level->dungeonCells){
        //float currentDistance = dot(*cell.first, sf::Vector2f(delegate->transform()->position().x, delegate->transform()->position().y));
        sf::Vector2f pt1 = *cell.first;
        sf::Vector2f pt2 = sf::Vector2f(delegate->transform()->position().x, delegate->transform()->position().y);
        float currentDistance = sqrt(static_cast<float>(pow((pt2.x - (pt1.x)), 2) + pow((pt2.y - pt1.y), 2)));
        if(currentDistance < shortestDistance){
            shortestDistance = currentDistance;
            startTile = cell.second;
        }
    }

    DungeonCell* endTile;
    shortestDistance = MAXFLOAT;
    for(auto& cell: level->dungeonCells){
        sf::Vector2f pt1 = *cell.first;
        sf::Vector2f pt2 = sf::Vector2f(m_targetPosition->x, m_targetPosition->y);
        float currentDistance = sqrt(static_cast<float>(pow((pt2.x - (pt1.x)), 2) + pow((pt2.y - pt1.y), 2)));
        if(currentDistance < shortestDistance){
            shortestDistance = currentDistance;
            endTile = cell.second;
        }
    }

    std::vector<DungeonCell*> notVisited;
    std::set<DungeonCell*> visited;

    notVisited.push_back(startTile);

    while (notVisited.size() > 0) {
        DungeonCell* currentTile = notVisited[0];

        for (int i = 0; i < notVisited.size(); ++i) {
            if (notVisited[i]->F < currentTile->F || notVisited[i]->F == currentTile->F && notVisited[i]->H < currentTile->H)
                currentTile = notVisited[i];
        }

        // Get index of currentTile to remove from notVisited
        std::vector<DungeonCell*>::iterator it = std::find(notVisited.begin(), notVisited.end(), currentTile);
        long index = std::distance(notVisited.begin(), it);
        notVisited.erase(notVisited.begin() + index);
        // Insert currentTile into visited
        visited.insert(currentTile);

        if (currentTile == endTile) {
            RetracePath(startTile, endTile); //create path to endTile from startTile
            return;
        }

        for (DungeonCell* neighbour : currentTile->getNeighbours(level->dungeonCells)) {
            if (visited.find(neighbour) != visited.end()) continue;

            int newMovementCostToNeighbour = currentTile->G + GetDistance(currentTile, neighbour);
            if (newMovementCostToNeighbour < neighbour->G || !(std::find(notVisited.begin(), notVisited.end(), neighbour) != notVisited.end())) {
                neighbour->G = newMovementCostToNeighbour;
                neighbour->H = GetDistance(neighbour, endTile);
                neighbour->parentCell = currentTile;

                if (!(std::find(notVisited.begin(), notVisited.end(), neighbour) != notVisited.end())) notVisited.push_back(neighbour);
            }
        }
    }
}

void AIComponent::RetracePath(DungeonCell* startTile, DungeonCell* targetTile) {
    DungeonCell* currentTile = targetTile;
    path.clear();

    while (currentTile != startTile) {
        path.push_back(currentTile);
        currentTile = currentTile->parentCell;
    }

    std::reverse(path.begin(), path.end());
}

int AIComponent::GetDistance(DungeonCell* tileA, DungeonCell* tileB) {
    sf::Vector2f pt1 = sf::Vector2f(tileA->cell->transform()->position().x, tileA->cell->transform()->position().y);
    sf::Vector2f pt2 = sf::Vector2f(tileB->cell->transform()->position().x, tileB->cell->transform()->position().y);
    return static_cast<int>(GetDistance(pt1, pt2));
}

int AIComponent::GetDistance(sf::Vector2f pt1, sf::Vector2f pt2) {
    float currentDistance = sqrt(static_cast<float>(pow((pt2.x - pt1.x), 2) + pow((pt2.y - pt1.y), 2)));
    return static_cast<int>(currentDistance);
}

void AIComponent::SetLevel(Dungeon* _level) {
    level = _level;
}

void AIComponent::SetTargetPosition(const b2Vec2& targetPosition) {
    m_targetPosition = &targetPosition;
}