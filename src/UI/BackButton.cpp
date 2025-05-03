#include "UIButton.h"
#include "../States/State.h"

namespace Cori {

std::function<void()> gOnBackClick {
    []() {
        if(gPreviousStates.empty()) return;
        gSetState(*(gPreviousStates.top()), false);
        gPreviousStates.pop();
    }    
};

BackButton::BackButton(float width, float height, bool saysBack)
: BackButton(0.0f, 0.0f, width, height, saysBack)
{}

BackButton::BackButton(float x, float y, float width, float height, bool saysBack)
: UIButton(x, y, width, height)
, mSaysBack { saysBack }
{
    init();
}

void BackButton::init() {
    if(mSaysBack)
        setText("Back");
    else
        setText("<");
    centerButtonText();
    
    createClickFunction(gOnBackClick);
}

} 