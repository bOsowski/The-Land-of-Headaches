//
// Created by Bartosz Osowski on 08/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#ifndef THE_LAND_OF_HEADACHES_ASSETMANAGER_HPP
#define THE_LAND_OF_HEADACHES_ASSETMANAGER_HPP


class AssetManager {
public:
    static AssetManager& instance(){
        static AssetManager* instance = new AssetManager();
        return *instance;
    }

private:
    AssetManager();

};


#endif //THE_LAND_OF_HEADACHES_ASSETMANAGER_HPP
