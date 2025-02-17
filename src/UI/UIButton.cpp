#include "UIButton.h"

namespace Cori {

void UIButton::setText(const std::string_view text) {
    mText.setString(std::string(text));
    mText.setPosition({ getX(), getY() });
}

void UIButton::setTextColor(const sf::Color color) {
    mText.setFillColor(color);
}

void UIButton::centerText() {
    // Scale text proportional to button size
    unsigned int charSize = generateUICharSize(mHeight);
    mText.setCharacterSize(charSize);
    mText.move({
        // Center text relative to string length and font size
        (mWidth / 2.0f) - (mText.getString().getSize() * charSize) / 4.0f, //scale adjuster of 4
        (mHeight / 2.0f) - (charSize / 1.5f) //scale adjuster of 1.5
    });
}

void UIButton::draw(sf::RenderWindow& window) {
    UIElement::draw(window);
    window.draw(mText);
}

}