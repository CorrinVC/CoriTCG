#include "UIScrollBar.h"
#include "../Input/MouseManager.h"
#include <algorithm>

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

void UIScrollBar::onPress() {
    if(!pressed && gMouseManager.getMouseButtonPressed(sf::Mouse::Button::Left))
        pressed = true;
    UIElement::onPress();
}

void UIScrollBar::update() {
    UIElement::update();
    if(pressed) {
        setPosition(
            getX(), 
            std::max(0.0f, 
                std::min(gMouseManager.getMousePosition().y - (mHeight / 2),
                mScrollAreaHeight - mHeight))
        );
    }

    // FIX SCROLL OFFSET CALCULATIONS
    //mScrollOffset = int(getY()) - mScrollOffset;
}

void UIScrollBar::draw(sf::RenderWindow& window) {
    window.draw(mScrollBarBkgd);
    UIElement::draw(window);
}

void UIScrollBar::setScrollBarBkgdColor(sf::Color color) {
    mScrollBarBkgd.setFillColor(color);
}

void UIScrollBar::setBarHeight(float height) {
    setSize({ getWidth(), height });
}

}