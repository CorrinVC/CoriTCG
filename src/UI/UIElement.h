#pragma once

#include "../Window.h"

namespace Cori {

class UIElement {
private:
    float mX {}, mY {};
    float mWidth {}, mHeight {};

    sf::RectangleShape mRect {};

    bool inBounds(const sf::Vector2i& position) {
        return (position.x >= mX && position.x <= mX + mWidth)
            && (position.y >= mY && position.y <= mY + mHeight);
    }

public:
    UIElement(float x, float y, float width, float height);

    void onClick();

    void update();
    void draw(sf::RenderWindow& window);
};

}