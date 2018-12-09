
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include "World.hpp"
#include "AssetManager.hpp"
#include "AnimationComponent.hpp"
#include "InputComponent.hpp"


int main(int, char const**) {
    // Program entry point.
    AssetManager::instance();   //instantiate asset manager here.

    b2BodyDef* bodyDef = new b2BodyDef();
    bodyDef->position = b2Vec2(250,250);
    bodyDef->type = b2BodyType::b2_dynamicBody;
    TransformComponent* transformComponent = new TransformComponent(bodyDef, 100);
    GameObject gameObject = GameObject(transformComponent);
    AnimationComponent* animationComponent = new AnimationComponent("mage_walk_down.png", 0.2, 8);
    gameObject.addComponent(animationComponent);
    InputComponent* inputComponent = new InputComponent();
    gameObject.addComponent(inputComponent);
    gameObject.instantiate();
//    gameObject.transform()->body->SetLinearVelocity(b2Vec2(100,100));

    while(World::instance().isOpened()){
        World::instance().update();
        World::instance().render();
    }

    return EXIT_SUCCESS;
}
