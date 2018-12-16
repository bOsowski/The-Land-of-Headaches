//
// Created by Bartosz Osowski on 11/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#include "DungeonCell.hpp"
#include "TextureComponent.hpp"
#include "AnimationComponent.hpp"
#include "Player.hpp"

void DungeonCell::addWall(Direction direction) {
    b2BodyDef* wallBody = new b2BodyDef();
    wallBody->position = cell->transform()->position();
    wallBody->type = b2_staticBody;
    b2EdgeShape* wallShape = new b2EdgeShape();
    b2FixtureDef *fixtureDef = new b2FixtureDef();

    switch(direction) {
        case UP: {
            wallBody->position = b2Vec2(cell->transform()->position().x, cell->transform()->position().y - tileSize.y - 2);
            wallShape->Set(b2Vec2(-tileSize.x/2, 0), b2Vec2(tileSize.x/2, 0));
        }
            break;
        case DOWN:
            wallBody->position = b2Vec2(cell->transform()->position().x, cell->transform()->position().y-2);
            wallShape->Set(b2Vec2(-tileSize.x/2, 0), b2Vec2(tileSize.x/2, 0));
            break;
        case LEFT:
            wallBody->position = b2Vec2(cell->transform()->position().x, cell->transform()->position().y- tileSize.y-2);
            wallShape->Set(b2Vec2(-tileSize.x/2, 0), b2Vec2(-tileSize.x/2, tileSize.y/2));
            break;
        case RIGHT:
            wallBody->position = b2Vec2(cell->transform()->position().x+tileSize.x, cell->transform()->position().y- tileSize.y-2);
            wallShape->Set(b2Vec2(-tileSize.x/2, 0), b2Vec2(-tileSize.x/2, tileSize.y/2));
            break;
        default:
            printf("Wall has not been set up properly. Invalid direction.");
            break;
    }

    TransformComponent *wallTransformComponent = new TransformComponent(wallBody);
    GameObject *wall = new GameObject(wallTransformComponent, 0);
    TextureComponent *wallTextureComponent = new TextureComponent("wall" + direction.name() + ".png");
    wall->addComponent(wallTextureComponent);
    fixtureDef->shape = wallShape;
    fixtureDef->friction = 0.0f;
    wallTransformComponent->body->CreateFixture(fixtureDef);  //todo: fix collision line positioning.
    wall->instantiate();
    walls.insert(std::pair<Direction, GameObject *>(direction, wall));

}

DungeonCell::DungeonCell(sf::Vector2f position)
{
    b2BodyDef* cellBody = new b2BodyDef();
    cellBody->type = b2_staticBody;
    cellBody->position = b2Vec2(position.x, position.y);
    TransformComponent* cellTransformComponent = new TransformComponent(cellBody);
    cell = new GameObject(cellTransformComponent, -1);
    TextureComponent* cellTextureComponent;
    if(getRandom(1,100) < 5){
        cellTextureComponent = new AnimationComponent("floorSpikes.png", 0.1, 4);
        class Spikes : public BaseComponent{
        public:
            Spikes() : BaseComponent("Spikes"){

            }
            void update(float deltaTime){
                if(distance(delegate->transform()->position(), Player::instance().gameObject->transform()->position()) < tileSize.x/2){

                }
                else{
                    AnimationComponent* animationComponent = (AnimationComponent *) delegate->getComponents().at("TextureComponent");
                    animationComponent->currentFrame = 0;
                    animationComponent->timer = 0;
                }
            }

            void render(sf::RenderWindow& window){}
        };
        Spikes* spikes = new Spikes();
        cell->addComponent(spikes);
    }
    else{
        cellTextureComponent = new TextureComponent("floor4.png");
    }
    cell->addComponent(cellTextureComponent);
    cell->instantiate();
    //printf("Created cell at (%f,%f)\n", cell->transform()->position().x, cell->transform()->position().y);
}

std::vector<DungeonCell*> DungeonCell::getNeighbours(std::map<sf::Vector2f*, DungeonCell*> otherCells) {
    std::vector<DungeonCell*> neighbours;
    for (int i = 0; i < Direction::length()-1; i++) {
        sf::Vector2f neighbourPosition = sf::Vector2f(cell->transform()->position().x, cell->transform()->position().y) + sf::Vector2f(Direction(i).value().x * tileSize.x, Direction(i).value().y * tileSize.y);
        for(auto& otherCell: otherCells){
            if(otherCell.first->x == neighbourPosition.x && otherCell.first->y == neighbourPosition.y){
                neighbours.push_back(otherCell.second);
                break;
            }
        }
    }
    return neighbours;
}

void DungeonCell::createWalls(std::map<sf::Vector2f*, DungeonCell*>& dungeonCells){
    for(int i = 0; i<Direction::length()-1; i++){
        bool hasNeighbour = false;
        for(auto& otherCell: dungeonCells){
            if(otherCell.first->x == cell->transform()->position().x+Direction(i).value().x*tileSize.x && otherCell.first->y == cell->transform()->position().y+Direction(i).value().y*tileSize.y){
                hasNeighbour = true;
                break;
            }
        }
        if(!hasNeighbour){
            addWall(Direction(i));
        }
    }
}