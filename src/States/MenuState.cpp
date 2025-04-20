#include "State.h"
#include "../UI/UIButton.h"

namespace Cori {

namespace MainMenu {

State gMenuState {};

// UI Elements
UIButton* cardViewButton;
UIButton* setViewButton;
UIButton* packSimButton;
UIButton* collectionButton;

void initMenuState() {

    // "Play" Button
    cardViewButton = new UIButton(100.0f, 60.0f);
    cardViewButton->setPositionRelativeTo(UIElement::ScreenCenter);
    cardViewButton->setPressedColor(sf::Color::Red);
    cardViewButton->setHoverColor(sf::Color::Green);
    cardViewButton->setBackgroundColor(sf::Color::Cyan);

    cardViewButton->createClickFunction(
        []() {
            gSetState(SetViewer::gSetViewerState);    
        }
    );

    cardViewButton->setText("Card View");
    cardViewButton->centerButtonText();
    cardViewButton->getTextbox().setTextPressedColor(sf::Color::Black);
    cardViewButton->getTextbox().setTextHoverColor(sf::Color::Magenta);
    cardViewButton->getTextbox().setTextColor(sf::Color::Red);

    // Init Set Viewer Button
    setViewButton = new UIButton(100.0f, 60.0f);
    setViewButton->setText("Set View");
    setViewButton->centerButtonText();
    setViewButton->createClickFunction(
        []() {
            gSetState(SetFullView::gSetFullViewState);
        }
    );

    // Init Pack Simulator Button
    packSimButton = new UIButton(100.0f, 60.0f);
    packSimButton->setText("Pack Sim");
    packSimButton->setPositionRelativeTo(*setViewButton, 110.0f, 0.0f);
    packSimButton->centerButtonText();
    packSimButton->createClickFunction(
        []() {
            gSetState(PackSimulator::gPackSimulatorState);
        }
    );

    // Init Collection Showcase Button
    collectionButton = new UIButton(100.0f, 60.0f);
    collectionButton->setText("Collection");
    collectionButton->setPositionRelativeTo(*packSimButton, 110.0f, 0.0f);
    collectionButton->centerButtonText();
    collectionButton->createClickFunction(
        []() {
            gSetState(CollectionView::gCollectionViewState);
        }
    );

    gMenuState.addUIElement(cardViewButton);
    gMenuState.addUIElement(setViewButton);
    gMenuState.addUIElement(packSimButton);
    gMenuState.addUIElement(collectionButton);
}

}

}