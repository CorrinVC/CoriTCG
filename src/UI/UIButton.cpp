#include "UIButton.h"

namespace Cori {

UIButton::UIButton(float width, float height)
: UIButton(0.0f, 0.0f, width, height) {}

UIButton::UIButton(float x, float y, float width, float height)
: UIElement(x, y, width, height)
, mTextbox { x, y, width, height, "",  true}
{}

void UIButton::update() {
    UIElement::update();

    // Update text if text is set
    if(mTextbox.getText() != "")
        mTextbox.update();
}

void UIButton::draw(sf::RenderWindow& window) {
    UIElement::draw(window);
    
    // Render text if text is set
    if(mTextbox.getText() != "")
        mTextbox.draw(window);
}

void UIButton::offsetFromOrigin(float xOffset, float yOffset) {
    UIElement::offsetFromOrigin(xOffset, yOffset);
    mTextbox.offsetFromOrigin(xOffset, yOffset);
}

void UIButton::setSize(const sf::Vector2f& size) {
    UIElement::setSize(size);
    centerButtonText();
}

// Change - Write Wrapper Functions
UITextbox& UIButton::getTextbox() {
    return mTextbox;
}

void UIButton::setText(const sf::String& text) {
    mTextbox.setText(text);
}

void UIButton::centerButtonText() {
    mTextbox.centerTextRelativeTo(*this);
}

void UIButton::setTextColor(sf::Color color) {
    mTextbox.setTextColor(color);
}

void UIButton::setTextHoverColor(sf::Color color) {
    mTextbox.setHoverColor(color);
}

void UIButton::setTextPressedColor(sf::Color color) {
    mTextbox.setTextPressedColor(color);
}

}