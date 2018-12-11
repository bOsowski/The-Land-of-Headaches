//
//  TileMap.hpp
//  AssetManagerv1
//
//  Created by Denis Flynn on 19/09/2018.
//  Copyright © 2018 Denis Flynn. All rights reserved.
//

#ifndef TileMap_hpp
#define TileMap_hpp

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "ResourcePath.hpp"

class TileMap : public sf::Drawable, public sf::Transformable {
public:

    // Gets the actual location of a tile in the level.
    sf::Vector2f GetActualTileLocation(int columnIndex, int rowIndex) {
        sf::Vector2f location;
        location.x = static_cast<float>(m_origin.x + (columnIndex * m_tileSize.x) + (m_tileSize.x / 2));
        location.y = static_cast<float>(m_origin.y + (rowIndex * m_tileSize.y) + (m_tileSize.y / 2));
        return location;
    }

    sf::Vector2i GetActualTileLocation(sf::Vector2f location) {
        sf::Vector2i locationInt;
        locationInt.x = static_cast<int>((location.x - m_tileSize.x / 2 - m_origin.x) / (m_tileSize.x));
        locationInt.y = static_cast<int>((location.y - m_tileSize.y / 2 - m_origin.y) / (m_tileSize.y));

        return locationInt;
    }

    void rectangeOnTile(sf::Vector2i pos, sf::Color colour) {
        //store old tile colour getFillColour()
        m_rectangleArr[pos.x + pos.y * m_tileArrSize.y].setFillColor(colour);
    }


    void printOnTileArr(std::vector<sf::Text> textArr) {
        m_GridText = textArr;
    }

    void load(sf::Vector2u tileSize, unsigned int width, unsigned int height) {
        m_tileSize = tileSize;
        m_tileArrSize = sf::Vector2u(width, height);

        // resize the vertex array to fit the level size
        m_vertices.setPrimitiveType(sf::Quads);
        m_vertices.resize(width * height * 4);

        m_rectangle.setSize(sf::Vector2f(tileSize.x, tileSize.y));
        m_rectangle.setOutlineColor(sf::Color::Black);
        m_rectangle.setOutlineThickness(1);

        // populate the vertex array, with one quad per tile
        for (unsigned int i = 0; i < width; ++i) {
            for (unsigned int j = 0; j < height; ++j) {
                m_rectangle.setPosition(sf::Vector2f(i * tileSize.x, j * tileSize.y));
                m_rectangleArr.push_back(m_rectangle);
            }
        }
    }

private:

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const {
        // apply the transform
        states.transform *= getTransform();

        // draw the vertex array
        target.draw(m_vertices, states);
        for (auto const &i:m_rectangleArr) {
            target.draw(i);
        }

        for (auto const &i:m_GridText) {
            target.draw(i);
        }
    }

    sf::VertexArray m_vertices;
    sf::Vector2u m_tileSize;
    sf::Vector2u m_tileArrSize;
    sf::RectangleShape m_rectangle;
    std::vector<sf::RectangleShape> m_rectangleArr;
    sf::Vector2i m_origin;
    std::vector<sf::Text> m_GridText;

};

#endif /* TileMap_hpp */
