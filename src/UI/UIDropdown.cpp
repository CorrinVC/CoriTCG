#include "UIDropdown.h"

namespace Cori {

UIDropdown::UIDropdown(float width, float height, std::vector<std::string> values)
: UIDropdown(0.0f, 0.0f, width, height, values)
{}

UIDropdown::UIDropdown(float x, float y, float width, float height, std::vector<std::string> values)
: UIElement(x, y, width, height)
, mTextValues { values }
{
    initDownArrow();
}

void UIDropdown::initDownArrow() {
    mDownArrowText.setString("^");
    mDownArrowText.setRotation({ sf::degrees(180) });
    mDownArrowText.setFillColor(sf::Color::Red);

    mDownArrowText.setCharacterSize(generateUICharSize(mHeight));
    mDownArrowText.setPosition({ 
        // Set position near right edge of mRect
        getX() + mWidth - (mDownArrowText.getCharacterSize() * 0.1f), // 0.1 * charsize scale adjuster
        getY() + mDownArrowText.getCharacterSize() * 1.4f // 1.4 * charsize scale adjuster
    });
}

void UIDropdown::onClick() {

}

void UIDropdown::update() {
    UIElement::update();
}

void UIDropdown::draw(sf::RenderWindow& window) {
    UIElement::draw(window);

    window.draw(mDownArrowText);
}

}