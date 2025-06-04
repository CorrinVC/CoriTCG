#include "UICheckbox.h"

namespace Cori {

void UICheckbox::updateCheckSymbol() {
    mCheckSymbol.setFillColor(mChecked ? sf::Color::Black : sf::Color::White);
}

UICheckbox::UICheckbox(float x, float y, float width, float height, sf::String text)
: UIElement(x, y, width, height)
, mText { x + width * 0.2f, y, width * 0.8f, height, text }
, mCheckSymbol {{ width * 0.1f, width * 0.1f }}
{ 
    mCheckSymbol.setPosition({ x + width * 0.05f, y + (height / 2.0f) - (width * 0.05f) });
    mCheckSymbol.setOutlineColor(sf::Color::Black);
    mCheckSymbol.setFillColor(sf::Color::White);

    mText.centerText();
    mText.getRenderText().setPosition({ 
        x + mCheckSymbol.getPosition().x + mCheckSymbol.getSize().x + width * 0.05f, 
        mText.getRenderText().getPosition().y 
    });

    createClickFunction([this]() {
        mChecked = !mChecked;
        updateCheckSymbol();
    });
}

UICheckbox::UICheckbox(float width, float height, sf::String text)
: UICheckbox(0.0f, 0.0f, width, height, text)
{ }

void UICheckbox::update() {
    mText.update();
    UIElement::update();
}

void UICheckbox::draw(sf::RenderWindow& window) {
    UIElement::draw(window);
    mText.draw(window);
    window.draw(mCheckSymbol);
}

}