#include "UITextbox.h"

namespace Cori {

UITextbox::UITextbox()
: UITextbox(0.0f, 0.0f, "")
{}

UITextbox::UITextbox(float width, float height, const std::string text, bool transparent)
: UITextbox(0.0f, 0.0f, width, height, text, transparent)
{}

UITextbox::UITextbox(float x, float y, float width, float height,
            const std::string text, bool transparent)
: UIElement(x, y, width, height)
{
    // Initialize mText
    mText.setString(text);
    mText.setPosition({ getX(), getY() });
    mText.setFillColor(mTextColor);

    mText.setCharacterSize(generateUICharSize(height));
    // Initialize Center Text Position
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
    else
        onHover();
}

void UITextbox::draw(sf::RenderWindow& window) {
    UIElement::draw(window);

    window.draw(mText);
}

const std::string UITextbox::getText() {
    return mText.getString().toAnsiString();
}

// Currently unused
sf::Text& UITextbox::getRenderText() {
    return mText;
}

void UITextbox::setText(const sf::String text) {
    mText.setString(text);
}

// Ideally Called After setTextHoverColor
void UITextbox::setTextColor(const sf::Color color) {
    if(mTextHoverColor == mTextColor)
        setTextHoverColor(color);
    mTextColor = color;
    mText.setFillColor(color);
}

// Ideally Called Before setTextColor, After setTextPressedColor
void UITextbox::setTextHoverColor(const sf::Color color) {
    if(mTextPressedColor == mTextHoverColor)
        setTextPressedColor(color);
    mTextHoverColor = color;
}

// Ideally Called First
void UITextbox::setTextPressedColor(const sf::Color color) {
    mTextPressedColor = color;
}

void UITextbox::setPosition(float x, float y) {
    UIElement::setPosition(x, y);
    mText.setPosition({ x, y });
    if(centered) centerText();
}

void UITextbox::offsetFromOrigin(float xOffset, float yOffset) {
    UIElement::offsetFromOrigin(xOffset, yOffset);
    mText.setPosition({ getX(), getY() });
    if(centered) centerText();
}

void UITextbox::setScale(float scaleX, float scaleY) {
    UIElement::setScale(scaleX, scaleY);
    mText.setScale({scaleX, scaleY});
    if(centered) centerText();
}   

void UITextbox::centerMove(bool initial) {
    // Gets Center Position of Text Bounds
    sf::Vector2f center { mText.getGlobalBounds().size / 2.0f };

    // Sets Text Origin to Center
    sf::Vector2f localBounds { center + mText.getLocalBounds().position };
    if(initial)
        mText.setOrigin(localBounds);
    else
        mText.setOrigin({localBounds.x, mText.getOrigin().y}); // If Not Initial, do not center vertically
}

void UITextbox::centerText() {
    centerMove();
    //std::cout << "Centering" << std::endl;
    mText.setPosition({ getX() + getWidth() / 2.0f * mText.getScale().x, getY() + getHeight() / 2.0f * mText.getScale().y });
    centered = true;
}

void UITextbox::centerTextRelativeTo(UIElement& element) {
    centerMove(true);
    mText.setPosition({ element.getX() + element.getWidth() / 2.0f, 
        element.getY() + element.getHeight() / 2.0f });
    mRect.setPosition({ element.getX(), element.getY() });
}

bool UITextbox::isCentered() {
    return centered;
}

}