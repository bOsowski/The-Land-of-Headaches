//
// Created by Bartosz Osowski on 07/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#include "GameObject.hpp"

GameObject::GameObject(TransformComponent* transformComponent, int _layer):
layer(_layer),
_transform(transformComponent)
{
    _transform->body = World::instance().physicsWorld.CreateBody(transform()->bodyDef());
    addComponent(transformComponent);
}

void GameObject::addComponent(BaseComponent* component) {
    component->delegate = this;
    components.insert(std::pair<std::string, BaseComponent*>(component->name(), component));
}

const std::map<std::string, BaseComponent *> GameObject::getComponents() {
    return components;
}

TransformComponent *GameObject::transform() const{
    return _transform;
}

void GameObject::instantiate() {
    World::instance().gameObjects.push_back(*this);
}


