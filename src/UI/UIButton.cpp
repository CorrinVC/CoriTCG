#include "UIButton.h"

namespace Cori {


UIButton::UIButton(float width, float height)
: UIButton(0.0f, 0.0f, width, height) {}

UIButton::UIButton(float x, float y, float width, float height)
: UIElement(x, y, width, height)
, mTextbox { x, y, width, height, "",  true}
{}

void UIButton::draw(sf::RenderWindow& window) {
    UIElement::draw(window);
    
    // Render text if text is set
    if(mTextbox.getText() != "")
        mTextbox.draw(window);
}

UITextbox& UIButton::getTextbox() {
    return mTextbox;
}

}