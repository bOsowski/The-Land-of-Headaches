//
// Created by Bartosz Osowski on 11/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#include "DungeonWall.hpp"

DungeonWall::DungeonWall(Direction direction){
    b2BodyDef* wallBody = new b2BodyDef();
    TransformComponent* wallTransform;

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
            printf("Wall not created. Invalid direction.");
            break;
    }
    wallBody->type = b2_staticBody;
    TransformComponent* wallTransform = new TransformComponent(wallBody);
    wall = new GameObject(wallTransform);
}
