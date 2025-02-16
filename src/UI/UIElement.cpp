#include "UIElement.h"
#include "../Input/MouseManager.h"

namespace Cori {

sf::Font gUIFont { "res/fonts/C059-Roman.pfb" };

//Generic Func to check if vector x,y is within bounds
//Used primarily for mouse position
bool UIElement::inBounds(const sf::Vector2i& position) {
    return (position.x >= mX && position.x <= mX + mWidth)
        && (position.y >= mY && position.y <= mY + mHeight);
}

UIElement::UIElement(float x, float y, float width, float height)
: mX { x }, mY { y }, mWidth { width }, mHeight { height }
, mRect { { width, height } }
{
    mRect.setPosition( {x, y} );
}

void UIElement::createClickFunction(std::function<void(void)> func) {
    mClickFunc = func;
}

void UIElement::onClick()  {
    if(mClickFunc) mClickFunc();
}

void UIElement::update() {
    //Check if element clicked
    if (gMouseManager.getMouseButtonReleased(sf::Mouse::Button::Left)
     && inBounds(gMouseManager.getMousePosition()))
        onClick();
}

void UIElement::draw(sf::RenderWindow& window) {
    window.draw(mRect);
}

}