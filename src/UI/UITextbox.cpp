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
    mText.setFillColor(mTextColor);

    mText.setCharacterSize(generateUICharSize(height));
    centerMove(true);

    if(transparent) 
        setTransparent();
}

void UITextbox::onHover() {
    UIElement::onHover();
    if(hovering)
        mText.setFillColor(mTextHoverColor);
    else
        mText.setFillColor(mTextColor);
}

void UITextbox::onPress() {
    if(pressed)
        mText.setFillColor(mTextPressedColor);
    else if(hovering)
        mText.setFillColor(mTextHoverColor);
    else
        mText.setFillColor(mTextColor);
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

void UITextbox::setText(const sf::String& text) {
    mText.setString(text);
}

// Ideally Called After setTextHoverColor
void UITextbox::setTextColor(const sf::Color color) {
    if(mTextHoverColor == mTextColor)
        setTextHoverColor(color);
    mTextColor = color;
    mText.setFillColor(color);
}

// Ideally Called Before setTextColor
void UITextbox::setTextHoverColor(const sf::Color color) {
    if(mTextPressedColor == mTextHoverColor)
        setTextPressedColor(color);
    mTextHoverColor = color;
}

void UITextbox::setTextPressedColor(const sf::Color color) {
    mTextPressedColor = color;
}

void UITextbox::centerMove(bool initial) {
    // Scale text proportional to button size
    /*mText.move({
        // Center text relative to string length and font size
        (mWidth / 2.0f) - (mText.getString().getSize() * charSize) / 4.0f, //scale adjuster of 4
        (mHeight / 2.0f) - (charSize / 1.5f) //scale adjuster of 1.5
    });*/
    sf::Vector2f center { mText.getGlobalBounds().size / 2.0f };
    sf::Vector2f localBounds { center + mText.getLocalBounds().position };
    if(initial)
        mText.setOrigin(localBounds);
    else
        mText.setOrigin({localBounds.x, mText.getOrigin().y});
}

void UITextbox::centerText() {
    centerMove();
    mText.setPosition({ getX() + getWidth() / 2.0f, getY() + getHeight() / 2.0f });
    centered = true;
}

void UITextbox::centerTextRelativeTo(UIElement& element) {
    centerMove(true);
    mText.setPosition({ element.getX() + element.getWidth() / 2.0f, 
        element.getY() + element.getHeight() / 2.0f });
    mRect.setPosition({ element.getX(), element.getY() });
}

}