
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

#include <Box2D/Dynamics/b2Body.h>
#include "ResourcePath.hpp"
#include "World.hpp"
#include "Player.hpp"
#include "TextureComponent.hpp"
#include "AIComponent.hpp"
#include "Dungeon.hpp"

class Dungeon;

int main(int, char const**) {
    sf::Music* music = new sf::Music();
    if (!music->openFromFile(resourcePath()+"audio/dungeon.ogg"))
        return -1; // error
    music->play();

    World& world = World::instance();

    srand((time(NULL)));
    // Program entry point.
    Player player = Player();
    Dungeon(sf::IntRect(128,512-128,10,10), 2, 4, 10);

//    b2BodyDef* bulletBodyDef = new b2BodyDef();
//    bulletBodyDef->type = b2BodyType::b2_dynamicBody;
//    bulletBodyDef->position = dungeon->lastCell->cell->transform()->position();
//    GameObject* bullet = new GameObject(new TransformComponent(bulletBodyDef, 1000), 0);
//    TextureComponent* bulletTexture = new TextureComponent("coin_0.png");
//    bullet->addComponent(bulletTexture);
//    AIComponent* aiComponent = new AIComponent();
//    aiComponent->SetLevel(dungeon);
//    bullet->addComponent(aiComponent);
//    bullet->instantiate();

    while(world.isOpened()){
        world.update();
        world.render();
    }

    return 0;
}
