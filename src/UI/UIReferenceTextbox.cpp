#include "UIReferenceTextbox.h"

namespace Cori {

UIReferenceTextbox::UIReferenceTextbox(float width, float height, std::string** text, bool transparent)
: UIReferenceTextbox(0, 0, width, height, text, transparent)
{}

UIReferenceTextbox::UIReferenceTextbox(float x, float y, float width, float height,
            std::string** text, bool transparent)
: UITextbox(x, y, width, height, **text, transparent)
, mTextString { text }
{}

void UIReferenceTextbox::update() {
    UIElement::update();
    if(mText.getString().toAnsiString() != **mTextString) {
        mText.setString(**mTextString);
        if(centeredRelativeTo)
            centerTextRelativeTo(*centeredRelativeTo);
        else if(centered)
            centerText();
    }

}

}