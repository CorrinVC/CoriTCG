#include "State.h"
#include "../UI/UIButton.h"
#include <iostream>

namespace Cori {


State gMenuState {};

void initMenuState() {
    UIButton* testButton = new UIButton(100.0f, 60.0f);
    testButton->setPositionRelativeTo(UIElement::ScreenCenter);
    testButton->createClickFunction(
        []() {
            gSetState(gSetViewerState);    
        }
    );
    testButton->setBackgroundColor(sf::Color::Cyan);
    testButton->setText("Play");
    testButton->setTextColor(sf::Color::Red);
    testButton->centerText();

    gMenuState.addUIElement(testButton);
}

}