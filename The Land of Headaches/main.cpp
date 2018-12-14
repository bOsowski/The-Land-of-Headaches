
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
#include "Player.hpp"
#include "Dungeon.hpp"
#include "SFMLDebugDraw.hpp"

int main(int, char const**) {
    sf::Music* music = new sf::Music();
    if (!music->openFromFile(resourcePath()+"audio/dungeon.ogg"))
        return -1; // error
    music->play();

    World& world = World::instance();
    SFMLDebugDraw debugDraw = SFMLDebugDraw(world.window());
    world.physicsWorld.SetDebugDraw(&debugDraw);

    srand((time(NULL)));
    // Program entry point.
    Player player = Player();
    Dungeon(sf::IntRect(128,512-128,10,10), 2, 4, 10);

    while(world.isOpened()){
        world.update();
        world.render();
    }

    return 0;
}
