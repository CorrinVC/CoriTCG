#pragma once

#include "../Window.h"

namespace Cori {

class UIElement {
private:
    float mX {}, mY {};
    float mWidth {}, mHeight {};

    sf::RectangleShape mRect {};

public:
    UIElement(float x, float y, float width, float height);

    void update();
    void draw(sf::RenderWindow& window);
};

}