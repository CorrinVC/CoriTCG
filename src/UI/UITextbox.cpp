#include "UITextbox.h"
#include <iostream>

namespace Cori {

UITextbox::UITextbox(float width, float height, std::string** text, bool transparent)
: UITextbox(0, 0, width, height, text, transparent)
{}

UITextbox::UITextbox(float x, float y, float width, float height,
            std::string** text, bool transparent)
: UIElement(x, y, width, height)
, mTextString { text }
{
    std::cout << *mTextString << '\n';
    mText.setString(**text);
    mText.setPosition({ getX(), getY() });
    mText.setFillColor(sf::Color::Red);

    if(transparent)
        mRect.setFillColor(sf::Color::Transparent);
}

int i = 0;

void UITextbox::update() {
    UIElement::update();
    if(mText.getString().toAnsiString() != **mTextString) {
        std::cout << "Changing Textbox Text" << std::endl;
        mText.setString(**mTextString);
    }
}

void UITextbox::draw(sf::RenderWindow& window) {
    UIElement::draw(window);

    window.draw(mText);
}

}