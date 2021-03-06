//
//  IMap.h
//  GameIMap
//
//  Created by River Liu on 1/4/2018.
//  Copyright � 2018 River Liu. All rights reserved.
//

#ifndef THE_LAND_OF_HEADACHES_IMAP_HPP
#define THE_LAND_OF_HEADACHES_IMAP_HPP

#include <cmath>

enum class PropCurve {
    Linear,
};

class InfluenceMap {
public:
    sf::Vector2f m_AnchorLocation;        // world location
    float m_fCellSize;                // cell size in world units
    int m_iWidth;
    int m_iHeight;
    std::vector<std::vector<float>> m_Grid;    // actual contents

public:
    InfluenceMap(int _width, int _height, float _x = 0.0f, float _y = 0.0f, int _cellSize = 1) :
            m_AnchorLocation(_x, _y), m_iWidth(_width), m_iHeight(_height), m_fCellSize(_cellSize) {
        m_Grid.resize(m_iHeight);
        for (int i = 0; i < m_iHeight; i++) m_Grid[i].resize(m_iWidth, 0.0f);
    }

    void setCellValue(int _x, int _y, float _value) {
        if (_x >= 0 && _x < m_iWidth && _y >= 0 && _y < m_iHeight) {
            m_Grid[_x][_y] = _value;
        }
    }

    float getCellValue(int _x, int _y) {
        return (_x >= 0 && _x < m_iWidth && _y >= 0 && _y < m_iHeight) ? m_Grid[_x][_y] : 0.0f;
    }

    void addCellValue(int _x, int _y, float _value) {
        if (_x >= 0 && _x < m_iWidth && _y >= 0 && _y < m_iHeight) {
            m_Grid[_x][_y] += _value;
        }
    }

    void propagateInfluence(int _centerX, int _centerY, int _radius, PropCurve _propType, float _magnitude = 1.0f) {
        if (_centerX < 0 || _centerX >= m_iWidth || _centerY < 0 || _centerY >= m_iHeight) return;

        int startX = _centerX - _radius;
        int startY = _centerY - _radius;
        int endX = _centerX + _radius;
        int endY = _centerY + _radius;

        int minX = std::max(0, startX);
        int maxX = std::min(endX, m_iWidth);
        int minY = std::max(0, startY);
        int maxY = std::min(endY, m_iHeight);

        for (int y = minY; y < maxY; y++) {
            for (int x = minX; x < maxX; x++) {
                float distance = getNormalizedDistance(y, _centerY, x, _centerX, _radius);
                m_Grid[x][y] += propValue(distance, _propType) * _magnitude;
            }
        }
    }

    float getNormalizedDistance(float _y, float _centerY, float _x, float _centerX, float _radius) {
        float result = std::sqrt((_y - _centerY) * (_y - _centerY) + (_x - _centerX) * (_x - _centerX)) / _radius;
        return (result > 1) ? 1 : result;
    }

    float propValue(float _distance, PropCurve _propCurve) {
        assert(_distance >= 0.0f && _distance <= 1.0f);

        switch (_propCurve) {
            case PropCurve::Linear:
                return 1.0f - _distance;
        }
    }

    void copyMap(InfluenceMap *_sourceMap, float _magnitude = 1.0f) {
        if (_sourceMap == nullptr) return;
        if (m_iHeight != _sourceMap->m_iHeight || m_iWidth != _sourceMap->m_iWidth) return;

        for (int y = 0; y < m_iHeight; y++) {
            for (int x = 0; x < m_iWidth; x++) {
                m_Grid[x][y] = _sourceMap->getCellValue(x, y) * _magnitude;
            }
        }
    }

    void addMap(InfluenceMap *_sourceMap, float _magnitude = 1.0f) {
        if (_sourceMap == nullptr) return;
        if (m_iHeight != _sourceMap->m_iHeight || m_iWidth != _sourceMap->m_iWidth) return;

        for (int y = 0; y < m_iHeight; y++) {
            for (int x = 0; x < m_iWidth; x++) {
                m_Grid[x][y] += _sourceMap->getCellValue(x, y) * _magnitude;
            }
        }
    }

    void clear() {
        for (int y = 0; y < m_iHeight; y++) {
            for (int x = 0; x < m_iWidth; x++) {
                m_Grid[x][y] = 0;
            }
        }
    }


//    void addMap(InfluenceMap *_sourceMap, int _centerX, int _centerY, float _magnitude = 1.0f, int _offsetX = 0, int _offsetY = 0) {
//        if (_sourceMap == nullptr) return;
//
//        int startX = _centerX + _offsetX - (_sourceMap->m_iWidth >> 1);
//        int startY = _centerY + _offsetY - (_sourceMap->m_iHeight >> 1);
//
//        for (int y = 0; y < _sourceMap->m_iHeight; y++) {
//            for (int x = 0; x < _sourceMap->m_iWidth; x++) {
//                int targetX = x + startX;
//                int targetY = y + startY;
//
//                if (targetX >= 0 && targetX < m_iWidth && targetY >= 0 && targetY < m_iHeight) {
//                    m_Grid[targetX][targetY] += _sourceMap->getCellValue(x, y) * _magnitude;
//                }
//            }
//        }
//    }

        void addToMap(InfluenceMap *_targetMap, int _centerX, int _centerY, float _magnitude = 1.0f, int _offsetX = 0, int _offsetY = 0) {
            if (_targetMap == nullptr) return;

            int targetMapWidth = _targetMap->m_iWidth;
            int targetMapHeight = _targetMap->m_iHeight;
            int startX = _centerX + _offsetX - (targetMapWidth >> 1);
            int startY = _centerY + _offsetY - (targetMapHeight >> 1);
            int negAdjX = 0;
            int negAdjY = 0;

            if (m_AnchorLocation.x < 0.0f) {negAdjX = -1;}
            if (m_AnchorLocation.y < 0.0f) {negAdjY = -1;}

            int minX = std::max(0, negAdjX - startX);
            int maxX = std::min(targetMapWidth, m_iWidth - startX + negAdjX);
            int minY = std::max(0, negAdjY - startY);
            int maxY = std::min(targetMapHeight, m_iHeight - startY + negAdjY);

            for (int y = minY; y < maxY; y++) {
                for (int x = minX; x < maxX; x++) {
                    int sourceX = x + startX - negAdjX;
                    int sourceY = y + startY - negAdjY;

                    _targetMap->addCellValue(x, y, getCellValue(sourceX, sourceY) * _magnitude);
                }
            }
        }
    };

    class LayerMapCollection {
    private:
        std::map<int, InfluenceMap *> m_Collection;

    public:
        void addLayer(const int _layerId, InfluenceMap *_imap) {
            if (m_Collection.count(_layerId) == false)    // if it doesn't already exist
            {
                m_Collection[_layerId] = _imap;
            }
        }

        InfluenceMap *getLayer(int _id) {
            if (m_Collection.count(_id)) {
                return m_Collection[_id];
            }
            return nullptr;
        }

        std::vector<InfluenceMap *> getLayers(std::vector<int> _ids) {
            std::vector<InfluenceMap *> result;
            for (auto it = _ids.begin(); it != _ids.end(); it++) {
                if (m_Collection.count(*it)) {
                    result.push_back(m_Collection[*it]);
                }
            }
            return result;
        }

        std::vector<InfluenceMap *> getOtherLayers(int _id) {
            std::vector<InfluenceMap *> result;
            for (auto it = m_Collection.begin(); it != m_Collection.end(); it++) {
                if (it->first != _id) {
                    result.push_back(it->second);
                }
            }
            return result;
        }
    };

    class InterestMap : public InfluenceMap {
    private:
        PropCurve m_FallCurve;
        std::vector<std::vector<float>> m_Template;

    public:
        InterestMap(PropCurve _fallCurve, int _width, int _height, float _x = 0.0f, float _y = 0.0f, int _cellSize = 1)
                :
                InfluenceMap(_width, _height, _x, _y, _cellSize) {
            propagateInfluence(_width >> 1, _height >> 1, std::max(_width, _height), _fallCurve, 1.0f);
            m_Template = m_Grid;
        }

        void applyInterest() {
            for (int y = 0; y < m_iHeight; y++) {
                for (int x = 0; x < m_iWidth; x++) {
                    m_Grid[x][y] *= m_Template[x][y];
                }
            }
        }

        void addInterest(InfluenceMap *_targetMap, int _centerX, int _centerY, float _magnitude = 1.0f, int _offsetX = 0, int _offsetY = 0) {
            _targetMap->addToMap(this, _centerX, _centerY, _magnitude, _offsetX, _offsetY);
        }

        sf::Vector2f getHighestCell() {
            sf::Vector2f result = sf::Vector2f(0,0);
            int randomX = rand() % m_iWidth;
            int randomY = rand() % m_iHeight;
            float maxValue = m_Grid[randomX][randomY];

            for (int y = randomY; y < m_iHeight + randomY; y++) {
                for (int x = randomX; x < m_iWidth + randomX; x++) {
                    int targetX = x % m_iWidth;
                    int targetY = y % m_iHeight;
                    if (m_Grid[targetX][targetY] > maxValue) {
                        maxValue = m_Grid[targetX][targetY];
                        result.x = targetX;
                        result.y = targetY;
                    }
                }
            }
            return result;
        }
    };


#endif //THE_LAND_OF_HEADACHES_IMAP_HPP
