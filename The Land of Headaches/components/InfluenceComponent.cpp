//
// Created by Bartosz Osowski on 10/12/2018.
// Copyright (c) 2018 Bartosz Osowski. All rights reserved.
//

#include <SFML/Audio.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "InfluenceComponent.hpp"
#include "ResourcePath.hpp"
#include "IMap.hpp"
#include "TransformComponent.hpp"

InfluenceComponent::InfluenceComponent(float _influence)
:
BaseComponent("InfluenceComponent"),
influence(_influence)
{
    font.loadFromFile(resourcePath() + "sansation.ttf");
    //Influence Map related
    sf::Vector2f anchorLoc(0, 0);
    sf::Vector2u mapDim(32, 32);//swapped x and y values due to run-time memory access error - revisit
    unsigned int tileSize = 32;
    imap = std::make_shared<InfluenceMap>(mapDim.x, mapDim.y, anchorLoc.x, anchorLoc.y, tileSize);

    m_map.load(sf::Vector2u(tileSize, tileSize), tileSize, tileSize);
}

void InfluenceComponent::update(float deltaTime) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::V)) {
        showInfluenceValues = !showInfluenceValues;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::C)) {
        showInfluenceMapColours = !showInfluenceMapColours;
    }

    static int updateCounterIMap = 0;
    static sf::Vector2i oldPlayerPosition(0, 0);
    static sf::Vector2i old_E_PlayerPosition(0, 0);
    ++updateCounterIMap;
    //window.Update();
//    float currentTime = m_clock.restart().asSeconds();
//    float newTime = m_clock.getElapsedTime().asSeconds();


    //m_player.Update(0.01);//use timeDelta, which needs to be calculated per frame
    //m_ePlayer.Update(0.01);
    // Store the player position as it's used many times.



    if (updateCounterIMap % 10 == 0) {
        sf::Vector2i playerPosition = m_map.GetActualTileLocation(sf::Vector2f(delegate->transform()->body->GetPosition().x, delegate->transform()->body->GetPosition().y));
        sf::Vector2i ePlayerPosition = m_map.GetActualTileLocation(sf::Vector2f(0,0));
//
        imap->clear();//if not done here,
        if (oldPlayerPosition != playerPosition) {
            imap->setCellValue(playerPosition.x, playerPosition.y, 30);//m_player.getInfluence());
        }
        //if enemy position changes, update influence map
        if (old_E_PlayerPosition != ePlayerPosition) {
            imap->setCellValue(ePlayerPosition.x, ePlayerPosition.y, -1);
        }
        //both player and enemys need to be updated as imap has been cleared at start
        for (int i = 0; i < 2; i++) {
            imap->propagateInfluence(ePlayerPosition.x, ePlayerPosition.y, 10, PropCurve::Linear, -1);
            imap->propagateInfluence(playerPosition.x, playerPosition.y, 10, PropCurve::Linear, 1);
        }


        if (updateCounterIMap % 1000 == 0)
            std::cout << "enemy imap val at position =" << imap->getCellValue(ePlayerPosition.x, ePlayerPosition.y)
                 << std::endl;

        oldPlayerPosition = playerPosition;
        old_E_PlayerPosition = ePlayerPosition;
//
    }
}

sf::Text InfluenceComponent::utilityFn(float val, sf::Vector2i pos) {
    std::stringstream stream;
    stream << std::fixed << std::setprecision(1) << val;
    std::string s = stream.str();

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
    window.draw(m_map);
}
