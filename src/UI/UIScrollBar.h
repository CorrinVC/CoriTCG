#pragma once

#include "UIElement.h"

namespace Cori {

class UIScrollBar: public UIElement {
public:
    UIScrollBar(float width, float height);
    UIScrollBar(float x, float y, float width, float height);
};

}