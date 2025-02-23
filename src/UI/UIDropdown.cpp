#include "UIDropdown.h"
#include "../Input/MouseManager.h"
#include <cstddef>

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

// Overridden in bounds method to check if position is inside dropped down bounds
bool UIDropdown::inBounds(const sf::Vector2i& position) {
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
    mBaseText.setPosition({ 
        getX() + mBaseText.getCharacterSize() * 0.2f, 
        getY() + mBaseText.getCharacterSize() * 0.2f 
    });
}

void UIDropdown::initDownArrow() {
    mDownArrowText.setString("^");
    mDownArrowText.setRotation({ sf::degrees(180) });
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
    if(mDroppedDown)
        UIElement::onClick();
    mDroppedDown = !mDroppedDown;
}

void UIDropdown::update() {
    if(gMouseManager.getMouseButtonReleased(sf::Mouse::Button::Left)
        && inBounds(gMouseManager.getMousePosition())) {
        if(mDroppedDown) {
            int dropdownIndex = (gMouseManager.getMousePosition().y - getY()) / mHeight;
            mSelectedIndex = dropdownIndex - 1;
            if(dropdownIndex > 0) {
                mSelectedText = mTextValues[dropdownIndex - 1];
                mBaseText.setString(mSelectedText);
            } else {
                mSelectedText = gDefaultString;
            }
            std::cout << "UIDropdown::update() " << mSelectedText << std::endl;
        } else {
            mBaseText.setString(mBaseString);
        }
        onClick();
    }
}

void UIDropdown::draw(sf::RenderWindow& window) {
    UIElement::draw(window);

    window.draw(mBaseText);
    if(!mDroppedDown)
        window.draw(mDownArrowText);
    else {
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

}