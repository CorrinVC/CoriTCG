#pragma once

#include "UIElement.h"
#include <SFML/Graphics.hpp>

namespace Cori {

class UIScrollBar: public UIElement {
private:
    float mScrollAreaHeight {};
    sf::RectangleShape mScrollBarBkgd {}; // Bkgd Rectangle of Full Scroll Bar
public:
    UIScrollBar(float width, float height, float scrollAreaHeight);
    UIScrollBar(float x, float y, float width, float height, float scrollAreaHeight);

    void draw(sf::RenderWindow& window);

    void setScrollBarBkgdColor(sf::Color color);
};

}