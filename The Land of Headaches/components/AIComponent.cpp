//
// Created by Bartosz Osowski on 14/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#include "AIComponent.hpp"


AIComponent::AIComponent() : BaseComponent("AIComponent"), level(nullptr) {
}

void AIComponent::update(float deltaTime) {
//    SetTargetPosition(sf::Vector2f((Player::player->transform()->position()).x, (Player::player->transform()->position()).y));
    SetTargetPosition(sf::Vector2f());
    level->resetNodes();
    UpdatePathFinding();

    if (path.size() == 0) return;

    DungeonCell* target = path[0];
    sf::Vector2f position = sf::Vector2f(target->cell->transform()->position().x, target->cell->transform()->position().y);
    sf::Vector2f direction = position - sf::Vector2f(delegate->transform()->position().x, delegate->transform()->position().y);
    sf::Vector2f normalized = normalize(direction) * delegate->transform()->movementSpeed;
    delegate->transform()->body->SetLinearVelocity((b2Vec2(normalized.x,normalized.y)));
}

void AIComponent::UpdatePathFinding() {
    DungeonCell* startTile;
    float shortestDistance = MAXFLOAT;
    for(auto cell: level->dungeonCells){
        float currentDistance = sqrt(dot(*cell.first, sf::Vector2f(delegate->transform()->position().x, delegate->transform()->position().y)));
        if(currentDistance < shortestDistance){
            shortestDistance = currentDistance;
            startTile = cell.second;
        }
    }

    DungeonCell* endTile;
    shortestDistance = MAXFLOAT;
    for(auto cell: level->dungeonCells){
        float currentDistance = sqrt(dot(*cell.first, m_targetPosition));
        if(currentDistance < shortestDistance){
            shortestDistance = currentDistance;
            endTile = cell.second;
        }
    }

    std::vector<DungeonCell*> openSet;
    std::set<DungeonCell*> closedSet;

    openSet.push_back(startTile);

    while (openSet.size() > 0) {
        DungeonCell* currentNode = openSet[0];

        for (int i = 0; i < openSet.size(); ++i) {
            if (openSet[i]->F < currentNode->F || openSet[i]->F == currentNode->F && openSet[i]->H < currentNode->H)
                currentNode = openSet[i];
        }

        std::vector<DungeonCell*>::iterator it = std::find(openSet.begin(), openSet.end(), currentNode);
        long index = std::distance(openSet.begin(), it);
        openSet.erase(openSet.begin() + index);
        closedSet.insert(currentNode);

        if (currentNode == endTile) {
            RetracePath(startTile, endTile);
            return;
        }

        for (DungeonCell* neighbour : currentNode->getNeighbours(level->dungeonCells)) {
            if (closedSet.find(neighbour) != closedSet.end()) continue;

            int newMovementCostToNeighbour = currentNode->G + GetDistance(currentNode, neighbour);
            if (newMovementCostToNeighbour < neighbour->G || !(std::find(openSet.begin(), openSet.end(), neighbour) != openSet.end())) {
                neighbour->G = newMovementCostToNeighbour;
                neighbour->H = GetDistance(neighbour, endTile);
                neighbour->parentCell = currentNode;

                if (!(std::find(openSet.begin(), openSet.end(), neighbour) != openSet.end())) openSet.push_back(neighbour);
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
    int distX = static_cast<int>(abs(tileA->cell->transform()->position().x - tileB->cell->transform()->position().x));
    int distY = static_cast<int>(abs(tileA->cell->transform()->position().y - tileB->cell->transform()->position().y));

    // srt(2) * 10 = 14
    if (distX > distY) return 14 * distY + 10 * (distX - distY);
    else 14 * distX + 10 * (distY - distX);
}

void AIComponent::SetLevel(Dungeon* level) {
    level = level;
}

void AIComponent::SetTargetPosition(sf::Vector2f targetPosition) {
    m_targetPosition = targetPosition;
}