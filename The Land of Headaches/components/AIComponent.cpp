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
    //SetTargetPosition(sf::Vector2f((Player::player->transform()->position()).x, (Player::player->transform()->position()).y));
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
    auto shortestDistance = MAXFLOAT;
    for(auto& cell: level->dungeonCells){
        //float currentDistance = dot(*cell.first, sf::Vector2f(delegate->transform()->position().x, delegate->transform()->position().y));
        sf::Vector2f pt1 = *cell.first;
        sf::Vector2f pt2 = sf::Vector2f(delegate->transform()->position().x, delegate->transform()->position().y);
        float currentDistance = sqrt(static_cast<float>(pow((pt2.x - pt1.x), 2) + pow((pt2.y - pt1.y), 2)));
        if(currentDistance < shortestDistance){
            shortestDistance = currentDistance;
            startTile = cell.second;
        }
    }
    std::cout<<"Shortest distance = "<<shortestDistance<<"\n";
    std::cout<<"First cell coords = "<<startTile->cell->transform()->position().x << ", "<<startTile->cell->transform()->position().y << " | Second cell coords = "<< delegate->transform()->position().x << ", " << delegate->transform()->position().y << "\n";

    //std::cout<<"Start tile = "<<startTile->cell->transform()->position().x<<", "<<startTile->cell->transform()->position().y<<"\n";

    printf("Shortest distance to itself = %f\n", shortestDistance);
    DungeonCell* endTile;
    shortestDistance = MAXFLOAT;
    for(auto& cell: level->dungeonCells){
        sf::Vector2f pt1 = *cell.first;
        sf::Vector2f pt2 = sf::Vector2f(m_targetPosition->x, m_targetPosition->y);
        float currentDistance = sqrt(static_cast<float>(pow((pt2.x - pt1.x), 2) + pow((pt2.y - pt1.y), 2)));
        if(currentDistance < shortestDistance){
            shortestDistance = currentDistance;
            endTile = cell.second;
        }
    }
    //std::cout<<"End tile = "<<endTile->cell->transform()->position().x<<", "<<endTile->cell->transform()->position().y<<"\n";

    //printf("Shortest distance to target = %f\n", shortestDistance);

    //if (startTile == endTile) printf("OH NO\n");

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

            //printf("Distance to neighbour : %d\n", GetDistance(currentTile, neighbour));
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
        //std::cout << currentTile->cell->transform()->position().x << ", "<<currentTile->cell->transform()->position().y << std::endl;
        currentTile = currentTile->parentCell;
    }

    std::reverse(path.begin(), path.end());
}

int AIComponent::GetDistance(DungeonCell* tileA, DungeonCell* tileB) {
//    auto x = abs(tileA->cell->transform()->position().x - tileB->cell->transform()->position().x);
//    auto y = abs(tileA->cell->transform()->position().y - tileB->cell->transform()->position().y);
//    int distX = static_cast<int>(x);
//    int distY = static_cast<int>(y);
//
//    // srt(2) * 10 = 14
//    if (distX > distY) return 14 * distY + 10 * (distX - distY);
//    else return 14 * distX + 10 * (distY - distX);
    sf::Vector2f pt1 = sf::Vector2f(tileA->cell->transform()->position().x, tileA->cell->transform()->position().y);
    sf::Vector2f pt2 = sf::Vector2f(tileB->cell->transform()->position().x, tileB->cell->transform()->position().y);
    float currentDistance = sqrt(static_cast<float>(pow((pt2.x - pt1.x), 2) + pow((pt2.y - pt1.y), 2)));
    return static_cast<int>(currentDistance);
}

void AIComponent::SetLevel(Dungeon* _level) {
    level = _level;
}

void AIComponent::SetTargetPosition(const b2Vec2& targetPosition) {
    m_targetPosition = &targetPosition;
}