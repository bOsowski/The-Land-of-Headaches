
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


int main(int, char const**) {
    // Program entry point.
    Player player = Player();

    while(World::instance().isOpened()){
        World::instance().update();
        World::instance().render();
    }

    return 0;
}
