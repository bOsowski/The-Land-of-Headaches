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
    b2FixtureDef *fixtureDef = new b2FixtureDef();

    switch(direction) {
        case UP:
            wallBody->position = b2Vec2(cell->transform()->position().x, cell->transform()->position().y - tileSize.y-2);
            wallShape->Set(wallBody->position, b2Vec2(wallBody->position.x+tileSize.x, wallBody->position.y));
            break;
        case DOWN:
            wallBody->position = b2Vec2(cell->transform()->position().x, cell->transform()->position().y-2);
            wallShape->Set(wallBody->position, b2Vec2(wallBody->position.x+tileSize.x, wallBody->position.y));
            break;
        case LEFT:
            wallBody->position = b2Vec2(cell->transform()->position().x, cell->transform()->position().y- tileSize.y-2);
            wallShape->Set(wallBody->position, b2Vec2(wallBody->position.x, wallBody->position.y+tileSize.y));
            break;
        case RIGHT:
            wallBody->position = b2Vec2(cell->transform()->position().x+tileSize.x, cell->transform()->position().y- tileSize.y-2);
            wallShape->Set(wallBody->position, b2Vec2(wallBody->position.x, wallBody->position.y+tileSize.y));
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
    //wallTransformComponent->body->CreateFixture(fixtureDef);  //todo: fix collision line positioning.
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
    TextureComponent* cellTextureComponent = new TextureComponent("floor4.png");
    cell->addComponent(cellTextureComponent);
    cell->instantiate();
    //printf("Created cell at (%f,%f)\n", cell->transform()->position().x, cell->transform()->position().y);
}
