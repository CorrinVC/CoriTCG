#include "UITextField.h"
#include "../Input/KeyboardManager.h"

namespace Cori {

UITextField::UITextField(float width, float height, bool transparent)
: UITextField(0.0f, 0.0f, width, height, transparent)
{}

UITextField::UITextField(float x, float y, float width, float height, bool transparent)
: UITextbox(x, y, width, height, "", transparent)
{
    createClickFunction(
        []() {
            if(!gKeyboardManager.acceptingTextInput())
                gKeyboardManager.acceptTextInput(true);
        }
    );
}

//void UITextField::onClick() {}

void UITextField::update() {
    UIElement::update();
    if(gKeyboardManager.acceptingTextInput())
        mText.setString(gKeyboardManager.getTextInput() + '_');
}

//void UITextField::draw(sf::RenderWindow& window) {}

sf::String UITextField::getTextInput() {
    sf::String input { mText.getString() };
    input.erase(mText.getString().find("_"));
    return input;
}

sf::String UITextField::flushTextInput() {
    sf::String input { getTextInput() };
    
    mText.setString("");
    gKeyboardManager.clearTextInput();
    gKeyboardManager.acceptTextInput(false);
    return input;
}

}