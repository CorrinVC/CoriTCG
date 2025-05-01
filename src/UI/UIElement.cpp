#include "UIElement.h"
#include "../Window.h"
#include "../Input/MouseManager.h"

namespace Cori {

// Default Global Font
sf::Font gUIFont { "res/fonts/C059-Roman.pfb" };

// Return Scaled Font Size Relative to Element Height
unsigned int UIElement::generateUICharSize(float height) {
    return static_cast<unsigned int>(height * 0.6f);
}

// TODO - Give UIElements Scale Factor Member Var

//Generic Func to check if vector x,y is within bounds
//Used primarily for mouse position
bool UIElement::inBounds(const sf::Vector2f& position) {
    return (position.x >= getX() && position.x <= getX() + mRect.getSize().x
        && (position.y >= getY() && position.y <= getY() + mRect.getSize().y));
}

// Constructor used for elements intended to be given relative position
UIElement::UIElement(float width, float height)
: UIElement(0.0f, 0.0f, width, height) {}

// 'Default' constructor
UIElement::UIElement(float x, float y, float width, float height)
: mOriginX { x }, mOriginY { y }
, mWidth { width }, mHeight { height }
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

void UIElement::updateOrigin(float x, float y) {
    mOriginX = x;
    mOriginY = y;
}

void UIElement::setPosition(float x, float y) {
    mRect.setPosition({ x, y });
    updateOrigin(x, y);
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
    updateOrigin(mRect.getPosition().x, mRect.getPosition().y);
}

// Sets UIElement position relative to screen position with comprehensive offsetting
void UIElement::setPositionRelativeTo(ScreenPosition position, float xOffset, float yOffset) {
    mRect.setPosition(getStartPosition(position));
    mRect.move({ xOffset, yOffset });
    updateOrigin(mRect.getPosition().x, mRect.getPosition().y);
}

// Sets UIElement position relative to other UIElement position
void UIElement::setPositionRelativeTo(const UIElement& element, float xOffset, float yOffset) {
    mRect.setPosition({ element.getX(), element.getY() });
    mRect.move({ xOffset, yOffset });
    updateOrigin(element.getX() + xOffset, element.getY() + yOffset);
}

void UIElement::move(float x, float y) {
    mRect.move({ x, y });
}

void UIElement::resetToOrigin() {
    mRect.setPosition({ mOriginX, mOriginY });
}

void UIElement::offsetFromOrigin(float xOffset, float yOffset) {
    mRect.setPosition({ mOriginX + xOffset, mOriginY + yOffset });
}

void UIElement::setScale(float scaleFactor) {
    setScale(scaleFactor, scaleFactor);
}

void UIElement::setScale(float scaleX, float scaleY) {
    mRect.setSize({ mWidth * scaleX, mHeight * scaleY });
}

void UIElement::setSize(const sf::Vector2f& size) {
    mWidth = size.x;
    mHeight = size.y;
    mRect.setSize(size);
}

void UIElement::setTransparent() {
    mBackgroundColor = sf::Color::Transparent;
    mHoverColor = mBackgroundColor;
    mPressColor = mHoverColor;
    mRect.setFillColor(mBackgroundColor);
}

// Ideally Called After setHoverColor
void UIElement::setBackgroundColor(const sf::Color color) {
    if(mHoverColor == mBackgroundColor)
        setHoverColor(color);
    mBackgroundColor = color;
    mRect.setFillColor(color);
}

// Ideally Called Before setBackgroundColor, After setPressedColor
void UIElement::setHoverColor(const sf::Color color) {
    if(mPressColor == mHoverColor)
        setPressedColor(color);
    mHoverColor = color;
}

// Ideally Called Before setHoverColor
void UIElement::setPressedColor(const sf::Color color) {
    mPressColor = color;
}

void UIElement::createClickFunction(std::function<void(void)> func) {
    mClickFunc = func;
    mClickFuncCreated = true;
}

void UIElement::destroyClickFunction() {
    mClickFunc = nullptr;
    mClickFuncCreated = false;
    gMouseManager.setMouseButtonReleased(sf::Mouse::Button::Left, false);
}

void UIElement::printDimensions() {
    std::cout << '(' << getX() << ", " << getY() << ") "
    << mWidth << 'x' << mHeight << std::endl;
}

void UIElement::onClick()  {
    //std::cout << this << ':' << gMouseManager.checkPressedSlot(this) << std::endl;
    if(!gMouseManager.checkPressedSlot(this)) return;
    if(mClickFunc) mClickFunc();
    //std::cout << "onClick Clearing" << std::endl;
    //gMouseManager.clearPressedSlot();
    //printDimensions();
    if(!mClickFuncCreated) return;
    gMouseManager.setMouseButtonReleased(sf::Mouse::Button::Left, false);
}

// Change Background Color When Hovering
void UIElement::onHover() {
    if(hovering)
        mRect.setFillColor(mHoverColor);
    else
        mRect.setFillColor(mBackgroundColor);
}

// Change Background Color if Pressed
void UIElement::onPress() {
    if(pressed) 
        mRect.setFillColor(mPressColor);
    else {
        onHover();
    }
}

void UIElement::update() {
    if(inBounds(gMouseManager.getMousePosition())) {
        if(!hovering) { // Sets Hover State if not already hovering
            hovering = true;
            onHover();
        }
        // Element Pressed State
        if(gMouseManager.getMouseButtonPressed(sf::Mouse::Button::Left)) {
            pressed = true;
            onPress();
        } else if(gMouseManager.getMouseButtonReleased(sf::Mouse::Button::Left)) {
            onClick();
            // Update Pressed Behaviour
            pressed = false;
            onPress();
            //std::cout << "Update Clearing" << std::endl;
            gMouseManager.clearPressedSlot();
        }
    } else {
        if(hovering) { // Clear Hovering
            hovering = false;
            onHover();
        }
        if(pressed) { // Clear Pressed
            pressed = false;
            onPress();
        }
        if(gMouseManager.checkPressedSlot(this) && !gMouseManager.getMouseButtonPressed(sf::Mouse::Button::Left))
            gMouseManager.clearPressedSlot();
    }
}

void UIElement::draw(sf::RenderWindow& window) {
    window.draw(mRect);
}

}