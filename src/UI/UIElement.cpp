#include "UIElement.h"

#include <iostream>

namespace Cori {

UIElement::UIElement(float x, float y, float width, float height)
: mX { x }, mY { y }, mWidth { width }, mHeight { height }
, mRect { { width, height } }
{}

void UIElement::onClick() {
    std::cout << "Clicked!";
}

void UIElement::update() {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)
     && inBounds(MouseManager::getMousePosition()))
        onClick();
}

void UIElement::draw(sf::RenderWindow& window) {
    window.draw(mRect);
}

}