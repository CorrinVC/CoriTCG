#pragma once

#include "UIElement.h"

namespace Cori {

class UIButton : public UIElement {

public:
    UIButton(float x, float y, float width, float height)
    : UIElement(x, y, width, height) {}
};

}