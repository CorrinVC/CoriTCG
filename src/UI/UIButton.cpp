#include "UIButton.h"

namespace Cori {

void UIButton::setText(std::string_view text) {
    mText.setString(std::string(text));
    mText.setPosition({ mX, mY });
}

void UIButton::setTextColor(sf::Color color) {
    mText.setFillColor(color);
}

void UIButton::centerText() {
    // Scale text proportional to button size
    unsigned int charSize = static_cast<unsigned int>(mHeight * 0.6f);
    mText.setCharacterSize(charSize);
    mText.move({
        // Center text relative to string length and font size
        (mWidth / 2.0f) - (mText.getString().getSize() * charSize) / 4.0f, 
        (mHeight / 2.0f) - (charSize / 1.5f)
    });
}

void UIButton::setBackgroundColor(sf::Color color) {
    mRect.setFillColor(color);
}

void UIButton::draw(sf::RenderWindow& window) {
    UIElement::draw(window);
    window.draw(mText);
}

}