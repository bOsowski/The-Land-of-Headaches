//
// Created by Bartosz Osowski on 07/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#include "GameObject.hpp"


GameObject::GameObject(TransformComponent* transformComponent) {
    _transform = transformComponent;
    addComponent(transformComponent);
}

void GameObject::addComponent(BaseComponent* component) {
    components.insert(std::pair<std::string, BaseComponent*>(component->name(), component));
}

const std::map<std::string, BaseComponent *> GameObject::getComponents() {
    return components;
}

const TransformComponent *GameObject::transform() {
    return _transform;
}


