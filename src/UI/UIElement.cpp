#include "UIElement.h"
#include "../Window.h"
#include "../Input/MouseManager.h"

namespace Cori {

// Default Global Font
sf::Font gUIFont { "res/fonts/C059-Roman.pfb" };

unsigned int generateUICharSize(float height) {
    return static_cast<unsigned int>(height * 0.6f);
}

//Generic Func to check if vector x,y is within bounds
//Used primarily for mouse position
bool UIElement::inBounds(const sf::Vector2i& position) {
    return (position.x >= getX() && position.x <= getX() + mWidth)
        && (position.y >= getY() && position.y <= getY() + mHeight);
}

// Constructor used for elements intended to be given relative position
UIElement::UIElement(float width, float height)
: UIElement(0.0f, 0.0f, width, height) {}

// 'Default' constructor
UIElement::UIElement(float x, float y, float width, float height)
: mWidth { width }, mHeight { height }
, mRect { { width, height } }
{
    mRect.setPosition( {x, y} );
}

// Local use for relative position functions
sf::Vector2f UIElement::getStartPosition(ScreenPosition position) {
    switch(position) {
    case UIElement::ScreenTop:
        return { // Center at top of window
            gWindowWidth / 2.0f - mWidth / 2.0f, 0.0f
        };
    case UIElement::ScreenTopRight: // Set at top right corner of window
        return {
            gWindowWidth - mWidth, 0.0f
        };
    case UIElement::ScreenLeft: // Center at left of window
        return {
            0.0f, gWindowHeight / 2.0f - mHeight / 2.0f
        };
    case UIElement::ScreenCenter: // Center in window
        return {
            gWindowWidth / 2.0f - mWidth / 2.0f,
            gWindowHeight / 2.0f - mHeight / 2.0f
        };
    case UIElement::ScreenRight: // Center at right of window
        return {
            gWindowWidth - mWidth, gWindowHeight / 2.0f - mHeight / 2.0f
        };
    case UIElement::ScreenBottomLeft: // Set at bottom left corner of window
        return {
            0.0f, gWindowHeight - mHeight
        };
    case UIElement::ScreenBottom: // Center at bottom of window
        return {
            gWindowWidth / 2.0f - mWidth / 2.0f, gWindowHeight - mHeight
        };
    case UIElement::ScreenBottomRight: // Set at bottom right corner of window
        return {
            gWindowWidth - mWidth, gWindowHeight - mHeight
        };
    }
    return {};
}

// Sets UIElement position relative to predetermined screen positions
void UIElement::setPositionRelativeTo(ScreenPosition position, float offset) {
    // Get screen position
    mRect.setPosition(getStartPosition(position));

    // Offset element position
    switch(position) {
    case UIElement::ScreenLeft: // Intentional fall-through
    case UIElement::ScreenRight:
        mRect.move({ offset, 0.0f });
        break;
    case UIElement::ScreenTop: // Intentional fall-through
    case UIElement::ScreenBottom:
        mRect.move({ 0.0f, offset });
        break;
    default: break;
    }
}

// Sets UIElement position relative to screen position with comprehensive offsetting
void UIElement::setPositionRelativeTo(ScreenPosition position, float xOffset, float yOffset) {
    mRect.setPosition(getStartPosition(position));
    mRect.move({ xOffset, yOffset });
}

// Sets UIElement position relative to other UIElement position
void UIElement::setPositionRelativeTo(const UIElement& element, float xOffset, float yOffset) {
    mRect.setPosition({ element.getX(), element.getY() });
    mRect.move({ xOffset, yOffset });
}

void UIElement::setSize(const sf::Vector2f& size) {
    mRect.setSize(size);
}

void UIElement::setBackgroundColor(const sf::Color color) {
    mRect.setFillColor(color);
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