#include "UITextbox.h"

namespace Cori {

UITextbox::UITextbox(float width, float height, const std::string& text, bool transparent)
: UITextbox(0.0f, 0.0f, width, height, text, transparent)
{}

UITextbox::UITextbox(float x, float y, float width, float height,
            const std::string& text, bool transparent)
: UIElement(x, y, width, height)
{
    mText.setString(text);
    mText.setPosition({ getX(), getY() });
    mText.setFillColor(sf::Color::Red);

    if(transparent)
        mRect.setFillColor(sf::Color::Transparent);
}

void UITextbox::draw(sf::RenderWindow& window) {
    UIElement::draw(window);

    window.draw(mText);
}

const std::string UITextbox::getText() {
    return mText.getString().toAnsiString();
}

sf::Text& UITextbox::getRenderText() {
    return mText;
}

void UITextbox::setText(const std::string& text) {
    mText.setString(text);
}

void UITextbox::setTextColor(const sf::Color color) {
    mText.setFillColor(color);
}

void UITextbox::centerMove() {
    // Scale text proportional to button size
    unsigned int charSize = generateUICharSize(mHeight);
    mText.setCharacterSize(charSize);
    mText.move({
        // Center text relative to string length and font size
        (mWidth / 2.0f) - (mText.getString().getSize() * charSize) / 4.0f, //scale adjuster of 4
        (mHeight / 2.0f) - (charSize / 1.5f) //scale adjuster of 1.5
    });
}

void UITextbox::centerText() {
    mText.setPosition({ getX(), getY() });
    centerMove();
    centered = true;
}

void UITextbox::centerTextRelativeTo(UIElement& element) {
    mText.setPosition({ element.getX(), element.getY() });
    centeredRelativeTo = &element;
    centerMove();
}

}