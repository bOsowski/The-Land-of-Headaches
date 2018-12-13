//
// Created by Bartosz Osowski on 10/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#include "Player.hpp"
#include "InfluenceComponent.hpp"

class b2BodyDef;

Player::Player() {
    b2BodyDef* bodyDef = new b2BodyDef();
    bodyDef->position = b2Vec2(World::instance().window().getSize().x/2,World::instance().window().getSize().y/2);
    bodyDef->type = b2BodyType::b2_dynamicBody;
    TransformComponent* transformComponent = new TransformComponent(bodyDef, 40000);
    gameObject = new GameObject(transformComponent, 0);
    AnimatorComponent* animatorComponent = new AnimatorComponent("mage", 0.2, 8);
    gameObject->addComponent(animatorComponent);
    InputComponent* inputComponent = new InputComponent();
    gameObject->addComponent(inputComponent);
    //todo: fix influence component
    //InfluenceComponent* influenceComponent = new InfluenceComponent(1);
    //gameObject->addComponent(influenceComponent);

    b2PolygonShape* collisionShape = new b2PolygonShape();
    collisionShape->SetAsBox(tileSize.x/3, tileSize.y/4, b2Vec2(0, -5), 0);
    b2FixtureDef* fixtureDef = new b2FixtureDef();
    fixtureDef->shape = collisionShape;
    fixtureDef->friction = 0;
    gameObject->transform()->body->CreateFixture(fixtureDef);
    gameObject->instantiate();
}
