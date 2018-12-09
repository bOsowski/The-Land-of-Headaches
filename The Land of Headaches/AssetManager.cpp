//
// Created by Bartosz Osowski on 08/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#include "AssetManager.hpp"


AssetManager::AssetManager() {
    DIR *dir;
    struct dirent *ent;

    const char* textures = ((resourcePath()+"textures/").c_str());
    const std::string texturesPath = std::string(textures);

    if ((dir = opendir (textures)) != NULL) {
        std::cout<< "Found textures folder."<<std::endl;
        while ((ent = readdir (dir)) != NULL) {
            std::string fileName = std::string(ent->d_name);

            if(fileName == "." || fileName == "..")continue;

            std::string full_path = texturesPath + fileName;
            std::cout << "Trying to load from " + full_path << std::endl;
            sf::Texture& texture = *(new sf::Texture());
            if ( texture.loadFromFile(full_path)) {
                sf::Sprite sprite = sf::Sprite(texture);
                sprites.insert(std::pair<std::string, sf::Sprite>(fileName, sprite));
                std::cout << "Loaded '" + fileName << "'" << std::endl<<std::endl;
            }
            else{
                std::cout << "Failed to load '" + fileName << "'" << std::endl<<std::endl;
            }
        }
        closedir (dir);
    }
    else {
        /* could not open directory */
        perror ("Failed to open resources.");
    }
}
