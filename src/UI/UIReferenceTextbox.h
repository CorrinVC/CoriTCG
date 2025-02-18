#pragma once

#include "UITextbox.h"
#include <SFML/Graphics.hpp>

namespace Cori {

class UIReferenceTextbox: public UITextbox {
private:
    std::string** mTextString;

public:
    UIReferenceTextbox(float width, float height, std::string** text, bool transparent = false);
    UIReferenceTextbox(float x, float y, float width, float height,
            std::string** text, bool transparent = false);

    void update();

};

}