#include "State.h"
#include "../UI/UIButton.h"
#include <iostream>

namespace Cori {

namespace MainMenu {

State gMenuState {};

void initMenuState() {
    UIButton* testButton = new UIButton(100.0f, 60.0f);
    testButton->setPositionRelativeTo(UIElement::ScreenCenter);
    testButton->createClickFunction(
        []() {
            gSetState(SetViewer::gSetViewerState);    
        }
    );
    testButton->setHoverColor(sf::Color::Green);
    testButton->setBackgroundColor(sf::Color::Cyan);
    testButton->getTextbox().setText("Play");
    testButton->getTextbox().setTextHoverColor(sf::Color::Magenta);
    testButton->getTextbox().setTextColor(sf::Color::Red);
    testButton->getTextbox().centerTextRelativeTo(*testButton);

    gMenuState.addUIElement(testButton);
}

}

}