#include "UIDropdown.h"
#include "../Input/MouseManager.h"
#include <cstddef> // for std::size_t

namespace Cori {

std::string gDefaultString {""};

UIDropdown::UIDropdown(float x, float y, float width, float height, 
    const std::string& baseText, const std::vector<std::string>& values, const sf::Color& color)
: UIElement(x, y, width, height)
, mTextColor { color }
, mBaseString { baseText }
, mTextValues { values }
{
    initBaseText();
    initDownArrow();

    initTextValues(values);
    initDropdownRectangles(values);
}

// Overridden inBounds method to check if position is inside dropped down bounds
// Invokes Base UIElement Functionality if not Dropped Down
bool UIDropdown::inBounds(const sf::Vector2f& position) {
    if(mDroppedDown)
        return (position.x >= getX() && position.x <= getX() + mWidth
            && position.y >= getY() && position.y <= getY() + mHeight * (1 + mTextValues.size()));
    else 
        return UIElement::inBounds(position);
}

void UIDropdown::initBaseText() {
    mBaseText.setString(mBaseString);
    mBaseText.setFillColor(mTextColor);

    mBaseText.setCharacterSize(generateUICharSize(mHeight));
    mBaseText.setPosition({ // 0.2f * charsize scale adjuster
        getX() + mBaseText.getCharacterSize() * 0.2f, 
        getY() + mBaseText.getCharacterSize() * 0.2f 
    });
}

void UIDropdown::initDownArrow() {
    mDownArrowText.setString("^");
    mDownArrowText.setRotation({ sf::degrees(180) }); // Rotate so it's upside down
    mDownArrowText.setFillColor(mTextColor);

    mDownArrowText.setCharacterSize(generateUICharSize(mHeight));
    mDownArrowText.setPosition({ 
        // Set position near right edge of mRect
        getX() + mWidth - (mDownArrowText.getCharacterSize() * 0.1f), // 0.1 * charsize scale adjuster
        getY() + mDownArrowText.getCharacterSize() * 1.4f // 1.4 * charsize scale adjuster
    });
}

void UIDropdown::initTextValues(const std::vector<std::string>& values) {
    for(std::size_t i = 0; i < values.size(); ++i) {
        mSFTexts.push_back(sf::Text(gUIFont));

        mSFTexts[i].setString(values[i]);
        mSFTexts[i].setFillColor(mTextColor);

        mSFTexts[i].setCharacterSize(generateUICharSize(mHeight));
        mSFTexts[i].setPosition({
            getX() + mBaseText.getCharacterSize() * 0.2f, 
            getY() + (mBaseText.getCharacterSize() * 0.2f) + (mHeight * (i + 1))
        });
    }
}

void UIDropdown::initDropdownRectangles(const std::vector<std::string>& values) {
    for(std::size_t i = 0; i < values.size(); i++) {
        mDropdownRectangles.push_back(sf::RectangleShape({ mWidth, mHeight }));

        mDropdownRectangles[i].setPosition({ getX(), getY() + (mHeight * (i + 1))});
    }
}

void UIDropdown::onClick() {
    if(!gMouseManager.checkPressedSlot(this))
        return;
    if(mDroppedDown)
        UIElement::onClick();
    
    mDroppedDown = !mDroppedDown;
}

void UIDropdown::update() {
    if(inBounds(gMouseManager.getMousePosition())) {
    if(!hovering) {
        hovering = true;
        onHover();
    }
    if(gMouseManager.getMouseButtonPressed(sf::Mouse::Button::Left)) {
        pressed = true;
        onPress();
    }
    else if(gMouseManager.getMouseButtonReleased(sf::Mouse::Button::Left)) {
        if(mDroppedDown) {
            // Set Dropdown Index to Respective Entry Rectangle
            int dropdownIndex = (gMouseManager.getMousePosition().y - getY()) / mHeight;
            // Adjust for Base Dropdown Rect
            mSelectedIndex = dropdownIndex - 1;
            if(dropdownIndex > 0) { // Base Rect not clicked
                mSelectedText = mTextValues[mSelectedIndex];
                mBaseText.setString(mSelectedText);
            } else { // Base Rect Clicked
                // Set to empty string for default comparison purposes
                mSelectedText = gDefaultString; 
            }
        } else { // To Change Base Text from Entry Text to Original
            mBaseText.setString(mBaseString);
        }
        onClick();
        gMouseManager.clearPressedSlot();
    }
    else {
        if(hovering) {
            hovering = false;
            onHover();
        }
        if(gMouseManager.getMouseButtonReleased(sf::Mouse::Button::Left) 
            && mDroppedDown) mDroppedDown = false;
        if(pressed) {
            pressed = false;
            onPress();
        }
    }
    }
}

void UIDropdown::draw(sf::RenderWindow& window) {
    UIElement::draw(window);

    window.draw(mBaseText);
    if(!mDroppedDown)
        window.draw(mDownArrowText);
    else { // Draw Dropped Down Menu
        for(sf::RectangleShape& rect : mDropdownRectangles)
            window.draw(rect);
        for(sf::Text& text : mSFTexts)
            window.draw(text);
    }
}

int UIDropdown::getSelectedIndex() {
    return mSelectedIndex;
}

std::string& UIDropdown::getSelectedText() {
    return mSelectedText;
}

void UIDropdown::setSelectedIndex(int index) {
    mSelectedIndex = index;
    mSelectedText = mTextValues[mSelectedIndex];
    mBaseText.setString(mSelectedText);
}

}