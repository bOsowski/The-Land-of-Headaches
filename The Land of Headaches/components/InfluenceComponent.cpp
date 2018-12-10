//
// Created by Bartosz Osowski on 10/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#include "InfluenceComponent.hpp"


InfluenceComponent::InfluenceComponent(float _influence)
:
BaseComponent("InfluenceComponent"),
influence(_influence)
{
    font.loadFromFile(resourcePath() + "sansation.ttf");
}

void InfluenceComponent::update(float deltaTime) {

}

sf::Text InfluenceComponent::utilityFn(float val, sf::Vector2i pos) {
    std::stringstream stream;
    stream << fixed << setprecision(1) << val;
    string s = stream.str();

    sf::Text sfTxt;

    sfTxt.setString(s);
    sfTxt.setFont(font);
    sfTxt.setCharacterSize(10);//magic number - change based on tilesize
    sfTxt.setFillColor(sf::Color::White);

    sf::Vector2f text_pos;
    text_pos = m_map.GetActualTileLocation(pos.x, pos.y);

    sfTxt.setPosition(text_pos);
    return sfTxt;
}

void InfluenceComponent::render(sf::RenderWindow &window) {
    sf::Color color = sf::Color::Black;
    bool showInfluenceMapColours = true;
    bool showInfluenceValues = true;

    std::stringstream stream;
    stream << std::fixed << std::setprecision(1) << influence;
    std::string s = stream.str();
    std::vector<sf::Text> sfTextArr;
    for (auto j = 0; j < imap->m_iHeight; j++)
        for (auto i = 0; i < imap->m_iWidth; i++) {
            if (showInfluenceMapColours) {
                if (imap->getCellValue(j, i) < 0) {
                    color.b = (imap->getCellValue(j, i) * 128 / 2.5 + 128);
                    color.r = -1 * (imap->getCellValue(j, i) * 128 / 2.5 + 128);
                }
                if (imap->getCellValue(j, i) > 0) {
                    color.r = -1 * imap->getCellValue(j, i) * 128 / 2.5 + 128;
                    color.b = imap->getCellValue(j, i) * 128 / 2.5 + 128;
                }
                if (imap->getCellValue(j, i) == 0) {
                    color.b = (imap->getCellValue(j, i) * 128 / 2.5 + 128);
                    color.r = (imap->getCellValue(j, i) * 128 / 2.5 + 128);
                }
            }
            m_map.rectangeOnTile(sf::Vector2i(i, j), color);
            sfTextArr.push_back(utilityFn(imap->getCellValue(j, i), sf::Vector2i(j, i)));
        }

    if (!showInfluenceValues) {
        sfTextArr.clear();
    }
    m_map.printOnTileArr(sfTextArr);
}
