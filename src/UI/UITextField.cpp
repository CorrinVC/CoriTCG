#include "UITextField.h"
#include "../Input/KeyboardManager.h"

namespace Cori {

UITextField::UITextField(float width, float height, bool transparent)
: UITextField(0.0f, 0.0f, width, height, transparent)
{}

UITextField::UITextField(float x, float y, float width, float height, bool transparent)
: UITextbox(x, y, width, height, "", transparent)
{
    createClickFunction([this]() {
        if(gKeyboardManager.currentTextField() != this) {
            gKeyboardManager.acceptTextInputFrom(this);
            gKeyboardManager.clearTextInput();
            mHighlighted = true;
        }
    });
    mCursor.setFillColor(mText.getFillColor());
}

//void UITextField::onClick() {}
void UITextField::updateCursor() {
    if(!mHighlighted) {
        if(mCursor.getString() != "") mCursor.setString("");
    } else {
        if(mCursor.getString() != "|") mCursor.setString("|");
        mCursor.setPosition({ mText.findCharacterPos(gKeyboardManager.getInputPosition()).x - (float(mText.getCharacterSize()) / 5.0f) - 2.0f, mText.getPosition().y});
    }
}

void UITextField::update() {
    if(gKeyboardManager.currentTextField() != this && mHighlighted)
        mHighlighted = false;
    
    UIElement::update();

    if(mHighlighted)
        mText.setString(gKeyboardManager.getTextInput());
    updateCursor();
}

void UITextField::draw(sf::RenderWindow& window) {
    UITextbox::draw(window);
    window.draw(mCursor);
}

//void UITextField::draw(sf::RenderWindow& window) {}

sf::String UITextField::getTextInput() {
    return mText.getString();
}

sf::String UITextField::flushTextInput() {
    sf::String input { getTextInput() };
    
    mText.setString("");
    gKeyboardManager.clearTextInput();
    gKeyboardManager.acceptTextInputFrom(nullptr);
    return input;
}

}