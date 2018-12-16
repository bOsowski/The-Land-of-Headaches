//
// Created by Bartosz Osowski on 08/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#include "AssetManager.hpp"


AssetManager::AssetManager() {
    DIR *dir;
    struct dirent *ent;

    bool fail = true;
    //loading textures
    while(fail){
        const char* textureDir = ((resourcePath()+"textures/").c_str());
        const std::string texturesPath = std::string(textureDir);

        if ((dir = opendir (textureDir)) != NULL) {
            std::cout<< "Found textures folder."<<std::endl;
            while ((ent = readdir (dir)) != NULL) {
                std::string fileName = std::string(ent->d_name);

                if(fileName == "." || fileName == "..")continue;

                std::string full_path = texturesPath + fileName;
                //std::cout << "Trying to load from " + full_path << std::endl;
                sf::Texture texture;
                if ( texture.loadFromFile(full_path)) {
                    textures.insert(std::pair<std::string, sf::Texture>(fileName, texture));
                    //std::cout << "Loaded '" + fileName << "'" << std::endl<<std::endl;
                }
                else{
                    std::cout << "Failed to load '" + fileName << "'" << std::endl<<std::endl;
                }
            }
            closedir (dir);
            fail = false;
        }
    }

    fail = true;
    //loading audio
    while(fail){
        const char* soundDir = ((resourcePath()+"audio/").c_str());
        const std::string audioPath = std::string(soundDir);

        if ((dir = opendir (soundDir)) != NULL) {
            std::cout<< "Found audio folder."<<std::endl;
            while ((ent = readdir (dir)) != NULL) {
                std::string fileName = std::string(ent->d_name);

                if(fileName == "." || fileName == "..")continue;

                std::string full_path = audioPath + fileName;
                //std::cout << "Trying to load from " + full_path << std::endl;
                sf::SoundBuffer* soundBuffer = new sf::SoundBuffer();
                if ( soundBuffer->loadFromFile(full_path)) {
                    sounds.insert(std::pair<std::string, sf::SoundBuffer*>(fileName, soundBuffer));
                   //std::cout << "Loaded '" + fileName << "'" << std::endl<<std::endl;
                }
                else{
                    std::cout << "Failed to load '" + fileName << "'" << std::endl<<std::endl;
                }
            }
            closedir (dir);
            fail = false;
        }
    }

}
