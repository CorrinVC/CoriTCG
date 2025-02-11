#include "UIElement.h"

namespace Cori {

UIElement::UIElement(float x, float y, float width, float height)
: mX { x }, mY { y }, mWidth { width }, mHeight { height }
, mRect { { width, height } }
{}

void UIElement::update() {}

void UIElement::draw(sf::RenderWindow& window) {
    window.draw(mRect);
}

}