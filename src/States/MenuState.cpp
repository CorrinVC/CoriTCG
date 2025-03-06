#include "State.h"
#include "../UI/UIButton.h"

namespace Cori {

namespace MainMenu {

State gMenuState {};

// UI Elements
UIButton* testButton;

void initMenuState() {

    // "Play" Button
    testButton = new UIButton(100.0f, 60.0f);
    testButton->setPositionRelativeTo(UIElement::ScreenCenter);
    testButton->setPressedColor(sf::Color::Red);
    testButton->setHoverColor(sf::Color::Green);
    testButton->setBackgroundColor(sf::Color::Cyan);

    testButton->createClickFunction(
        []() {
            gSetState(SetFullView::gSetFullViewState);    
        }
    );

    testButton->getTextbox().setText("Play");
    testButton->getTextbox().setTextPressedColor(sf::Color::Black);
    testButton->getTextbox().setTextHoverColor(sf::Color::Magenta);
    testButton->getTextbox().setTextColor(sf::Color::Red);
    testButton->getTextbox().centerTextRelativeTo(*testButton);

    gMenuState.addUIElement(testButton);
}

}

}