
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
    Player player = Player();


    sf::Music* music = new sf::Music();
    if (!music->openFromFile(resourcePath()+"audio/dungeon.ogg"))
        return -1; // error
    music->play();

    World& world = World::instance();

    //srand((time(NULL)));
    // Program entry point.
    Dungeon* dungeon = new Dungeon(sf::IntRect(128,512-128,10,10), 2, 4, 2);
    std::cout<<"Dungeon cell size = "<<dungeon->dungeonCells.size()<<std::endl;

    b2BodyDef* seekingMissileBodyDef = new b2BodyDef();
    seekingMissileBodyDef->type = b2BodyType::b2_dynamicBody;
    seekingMissileBodyDef->position = b2Vec2(144, 396);
    GameObject* seekingMissile = new GameObject(new TransformComponent(seekingMissileBodyDef, 10), 0);
    TextureComponent* seekingMissileTexture = new TextureComponent("coin_0.png");
    seekingMissile->addComponent(seekingMissileTexture);
    AIComponent* aiComponent = new AIComponent();
    aiComponent->SetTargetPosition(player.gameObject->transform()->position());
    aiComponent->SetLevel(dungeon);

//    b2PolygonShape* collisionShape = new b2PolygonShape();
//    collisionShape->SetAsBox(1, 1, b2Vec2(0, 0), 0);
//    b2FixtureDef* fixtureDef = new b2FixtureDef();
//    fixtureDef->shape = collisionShape;
//    fixtureDef->friction = 0;
//    seekingMissile->transform()->body->CreateFixture(fixtureDef);

    seekingMissile->addComponent(aiComponent);
    seekingMissile->instantiate();

    while(world.isOpened()){
        world.update();
        world.render();
    }

    return 0;
}
