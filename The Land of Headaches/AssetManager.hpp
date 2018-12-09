//
// Created by Bartosz Osowski on 08/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#ifndef THE_LAND_OF_HEADACHES_ASSETMANAGER_HPP
#define THE_LAND_OF_HEADACHES_ASSETMANAGER_HPP

#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include <map>
#include <string>
#include <iostream>
#include <zconf.h>
#include "utils.hpp"
#include <dirent.h>
#include <iostream>


class AssetManager {
public:
    static AssetManager& instance(){
        static AssetManager* instance = new AssetManager();
        return *instance;
    }

    std::map<std::string, sf::Sprite> sprites;

private:
    AssetManager();
    AssetManager(const AssetManager& other) = delete;
};


#endif //THE_LAND_OF_HEADACHES_ASSETMANAGER_HPP
