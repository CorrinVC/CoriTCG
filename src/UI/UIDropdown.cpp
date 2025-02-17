#include "UIDropdown.h"
#include <cstddef>

namespace Cori {

UIDropdown::UIDropdown(float width, float height, const std::string& baseText, 
    const std::vector<std::string>& values, const sf::Color& color)
: UIDropdown(0.0f, 0.0f, width, height, baseText, values, color)
{}

UIDropdown::UIDropdown(float x, float y, float width, float height, 
    const std::string& baseText, const std::vector<std::string>& values, const sf::Color& color)
: UIElement(x, y, width, height),
mTextColor { color }
{
    initBaseText(baseText);
    initDownArrow();

    initTextValues(values);
}

void UIDropdown::initBaseText(const std::string& text) {
    mBaseText.setString(text);
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
        mTextValues.push_back(sf::Text(gUIFont));

        mTextValues[i].setString(values[i]);
        mTextValues[i].setFillColor(mTextColor);

        mTextValues[i].setCharacterSize(generateUICharSize(mHeight));
        mTextValues[i].setPosition({
            getX() + mBaseText.getCharacterSize() * 0.2f, 
            getY() + (mBaseText.getCharacterSize() * 0.2f) + (mHeight * (i + 1))
        });
    }
}

void UIDropdown::onClick() {
    mDroppedDown = !mDroppedDown;
    if(mDroppedDown)
        mRect.setSize({ mWidth, mHeight * (1 + mTextValues.size()) });
    else   
        mRect.setSize({ mWidth, mHeight });
}

void UIDropdown::update() {
    UIElement::update();
}

void UIDropdown::draw(sf::RenderWindow& window) {
    UIElement::draw(window);

    window.draw(mBaseText);
    if(!mDroppedDown)
        window.draw(mDownArrowText);
    else {
        for(sf::Text text : mTextValues)
            window.draw(text);
    }
}

}