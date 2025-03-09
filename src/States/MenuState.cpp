#include "State.h"
#include "../UI/UIButton.h"

namespace Cori {

namespace MainMenu {

State gMenuState {};

// UI Elements
UIButton* playButton;

void initMenuState() {

    // "Play" Button
    playButton = new UIButton(100.0f, 60.0f);
    playButton->setPositionRelativeTo(UIElement::ScreenCenter);
    playButton->setPressedColor(sf::Color::Red);
    playButton->setHoverColor(sf::Color::Green);
    playButton->setBackgroundColor(sf::Color::Cyan);

    playButton->createClickFunction(
        []() {
            gSetState(SetFullView::gSetFullViewState);    
        }
    );

    playButton->setText("Play");
    playButton->centerButtonText();
    playButton->getTextbox().setTextPressedColor(sf::Color::Black);
    playButton->getTextbox().setTextHoverColor(sf::Color::Magenta);
    playButton->getTextbox().setTextColor(sf::Color::Red);

    gMenuState.addUIElement(playButton);
}

}

}