#include "UIScrollBar.h"

namespace Cori {

UIScrollBar::UIScrollBar(float width, float height, float scrollAreaHeight)
: UIScrollBar(0.0f, 0.0f, width, height, scrollAreaHeight)
{ }

UIScrollBar::UIScrollBar(float x, float y, float width, float height, float scrollAreaHeight)
: UIElement(x, y, width, height)
, mScrollAreaHeight { scrollAreaHeight }
, mScrollBarBkgd {{ width, scrollAreaHeight }}
{
    if(x == 0.0f && y == 0.0f) {
        setPositionRelativeTo(ScreenTopRight);
    }

    setBackgroundColor(sf::Color(120, 120, 120));
    setPressedColor(sf::Color(30, 30, 255));

    mScrollBarBkgd.setPosition({ getX(), getY() });
    mScrollBarBkgd.setFillColor(sf::Color(200, 200, 200));
}

void UIScrollBar::draw(sf::RenderWindow& window) {
    window.draw(mScrollBarBkgd);
    UIElement::draw(window);
}

void UIScrollBar::setScrollBarBkgdColor(sf::Color color) {
    mScrollBarBkgd.setFillColor(color);
}

}