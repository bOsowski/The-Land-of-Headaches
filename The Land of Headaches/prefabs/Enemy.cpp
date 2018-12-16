//
// Created by Bartosz Osowski on 15/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#include <Box2D/Dynamics/b2Body.h>
#include "Enemy.hpp"
#include "AnimatorComponent.hpp"
#include "AIComponent.hpp"
#include "Player.hpp"

Enemy::Enemy(sf::Vector2f position, Dungeon* level){
    b2BodyDef* bodyDef = new b2BodyDef();
    bodyDef->type = b2BodyType::b2_dynamicBody;
    bodyDef->position = level->dungeonCells.begin()->second->cell->transform()->position();
    TransformComponent* transformComponent = new TransformComponent(bodyDef, 5);
    gameObject = new GameObject(transformComponent, 0);
    AnimatorComponent* animatorComponent = new AnimatorComponent("mage", 0.2, 8);
    animatorComponent->sprite->setColor(sf::Color::Red);
    gameObject->addComponent(animatorComponent);
    //InfluenceComponent* influenceComponent = new InfluenceComponent(1);
    //gameObject->addComponent(influenceComponent);
    AIComponent* aiComponent = new AIComponent();
    aiComponent->SetTargetPosition(Player::instance().gameObject->transform()->position());
    aiComponent->SetLevel(level);
    gameObject->addComponent(aiComponent);
    b2PolygonShape* collisionShape = new b2PolygonShape();
    collisionShape->SetAsBox(tileSize.x/3, tileSize.y/4, b2Vec2(0, 5), 0);
    b2FixtureDef* fixtureDef = new b2FixtureDef();
    fixtureDef->shape = collisionShape;
    fixtureDef->friction = 0;
    gameObject->transform()->body->CreateFixture(fixtureDef);
    gameObject->instantiate();

}
