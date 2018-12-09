
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


int main(int, char const**) {
    // Program entry point.
    AssetManager::instance();   //instantiate asset manager here.

    b2BodyDef* bodyDef = new b2BodyDef();
    bodyDef->type = b2BodyType::b2_dynamicBody;
    TransformComponent* transformComponent = new TransformComponent(bodyDef);
    GameObject gameObject = GameObject(transformComponent);
    sf::Texture* texture = &(AssetManager::instance().textures.at("mage_walk_down.png"));
    AnimationComponent* animationComponent = new AnimationComponent(texture, 0.2, 8);
    gameObject.addComponent(animationComponent);
    gameObject.instantiate();
    gameObject.transform()->body->SetLinearVelocity(b2Vec2(100,100));

    while(World::instance().isOpened()){
        World::instance().update();
        World::instance().render();
    }

    return EXIT_SUCCESS;
}
