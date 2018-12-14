//
// Created by Bartosz Osowski on 10/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#ifndef THE_LAND_OF_HEADACHES_TRAIT_HPP
#define THE_LAND_OF_HEADACHES_TRAIT_HPP

class Blackboard;

using namespace std;

namespace GameIMap {
    class Trait {
    public:
        typedef Trait *(*createInstanceFn)();

    public:
        Trait() {
        }

        inline virtual void updateInterestMap(InterestMap *_interest, LayerMapCollection *const _collection, int _centerX, int _centerY, int _radius, int _id) {
        }

        inline virtual GameMath::Vector2 getLocation(InterestMap *_interest, LayerMapCollection *const _collection, int _centerX, int _centerY, int _radius, int _id) {
            return GameMath::Vector2::zero();
        }

        inline virtual void onUpdate(Blackboard *_blackboard) {
        }

        inline virtual GameMath::Vector3 getWorldLocation(GameMath::Vector2 _location, int _centerX, int _centerY, InterestMap *_interest, InfluenceMap *_influence, float _cellSize, float _z) {
            return Vector3::zero();
        }

        inline static Trait *create() {
            return new Trait();
        }
    };

    class TraitFactory {
    private:
        TraitFactory(const TraitFactory &) {
        }

        TraitFactory &operator=(const TraitFactory &) {
            return *this;
        }

        typedef std::map<std::string, Trait::createInstanceFn> FactoryMap;
        FactoryMap m_FactoryMap;

    public:
        TraitFactory() {
        }

        ~TraitFactory() {
            m_FactoryMap.clear();
        }

        void registerClass(const std::string &name, Trait::createInstanceFn pfnCreate) {
            m_FactoryMap[name] = pfnCreate;
        }

    };
}


#endif //THE_LAND_OF_HEADACHES_TRAIT_HPP
