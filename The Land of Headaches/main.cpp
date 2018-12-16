
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
#include "Enemy.hpp"

class Dungeon;

int main(int, char const**) {
    //Player player = Player();
    Player::instance();

    sf::Music* music = new sf::Music();
    if (!music->openFromFile(resourcePath()+"audio/dungeon.ogg"))
        return -1; // error
    music->play();

    World& world = World::instance();

    srand((time(NULL)));
    // Program entry point.
    Dungeon* dungeon = new Dungeon(sf::FloatRect(128,512-128,10,10), 2, 2, 9);
    std::cout<<"Dungeon cell size = "<<dungeon->dungeonCells.size()<<std::endl;
    Enemy enemy = Enemy(sf::Vector2f(200, 346), dungeon);
    while(world.isOpened()){
        world.update();
        world.render();
    }

    return 0;
}
