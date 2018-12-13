/*
    Copyright (C) 2011 Allen Jordan ()
    Copyright (C) 2011 Xabier Larrakoetxea (slok)
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef THE_LAND_OF_HEADACHES_B2GLDRAW_HPP
#define THE_LAND_OF_HEADACHES_B2GLDRAW_HPP

#include <Box2D/Common/b2Draw.h>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include <cmath>
#include <SFML/Graphics/CircleShape.hpp>

namespace sfdd
{
    const float SCALE = 32.f;
}

class SFMLDebugDraw : public b2Draw
{
private:
    sf::RenderWindow* m_window;
public:
    SFMLDebugDraw(sf::RenderWindow &window);

    /// Convert Box2D's OpenGL style color definition[0-1] to SFML's color definition[0-255], with optional alpha byte[Default - opaque]
    static sf::Color GLColorToSFML(const b2Color &color, sf::Uint8 alpha = 255)
    {
        return sf::Color(static_cast<sf::Uint8>(color.r * 255), static_cast<sf::Uint8>(color.g * 255), static_cast<sf::Uint8>(color.b * 255), alpha);
    }

    /// Convert Box2D's vector to SFML vector [Default - scales the vector up by SCALE constants amount]
    static sf::Vector2f B2VecToSFVec(const b2Vec2 &vector, bool scaleToPixels = true)
    {
        return sf::Vector2f(vector.x * (scaleToPixels ? sfdd::SCALE : 1.f), vector.y * (scaleToPixels ? sfdd::SCALE : 1.f));
    }

    /// Draw a closed polygon provided in CCW order.
    void DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);

    /// Draw a solid closed polygon provided in CCW order.
    void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);

    /// Draw a circle.
    void DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color);

    /// Draw a solid circle.
    void DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color);

    /// Draw a line segment.
    void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color);

    /// Draw a transform. Choose your own length scale.
    void DrawTransform(const b2Transform& xf);

    void DrawPoint(const b2Vec2& p, float32 size, const b2Color& color) {
        DrawSolidCircle(p, 1, b2Vec2(0,0), color);
    }
};

#endif //THE_LAND_OF_HEADACHES_B2GLDRAW_HPP
