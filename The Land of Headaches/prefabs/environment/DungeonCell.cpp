//
// Created by Bartosz Osowski on 11/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#include "DungeonCell.hpp"

void DungeonCell::addWall(Direction direction) {
    b2BodyDef* wallBody = new b2BodyDef();
    wallBody->position = cell->transform()->position();
    wallBody->type = b2_staticBody;
    b2EdgeShape* wallShape = new b2EdgeShape();

    wallShape->Set(b2Vec2(0,0), b2Vec2(0,0));   //todo: change this based on direction.
    switch(direction){
        case UP:
            break;
        case DOWN:
            break;
        case LEFT:
            break;
        case RIGHT:
            break;
        default:
            printf("Wall has not been set up properly. Invalid direction.");
            break;
    }

    TransformComponent* wallTransformComponent = new TransformComponent(wallBody);
    GameObject* wall = new GameObject(wallTransformComponent);
    TextureComponent* wallTextureComponent = new TextureComponent("wall"+direction.name()+".png");
    wall->addComponent(wallTextureComponent);
    b2FixtureDef* fixtureDef = new b2FixtureDef();
    fixtureDef->shape = wallShape;
    fixtureDef->friction = 0.0f;
    wallTransformComponent->body->CreateFixture(fixtureDef);
    wall->instantiate();
    walls.insert(std::pair<Direction, GameObject*>(direction, wall));
}

DungeonCell::DungeonCell(sf::Vector2f position)
{
    b2BodyDef* cellBody = new b2BodyDef();
    cellBody->type = b2_staticBody;
    cellBody->position = b2Vec2(position.x, position.y);
    TransformComponent* cellTransformComponent = new TransformComponent(cellBody);
    cell = new GameObject(cellTransformComponent);
    TextureComponent* cellTextureComponent = new TextureComponent("floor4.png");
    cell->addComponent(cellTextureComponent);
    cell->instantiate();
    //printf("Created cell at (%f,%f)\n", cell->transform()->position().x, cell->transform()->position().y);
}
