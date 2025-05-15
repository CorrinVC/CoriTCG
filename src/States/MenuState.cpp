#include "State.h"
#include "../Window.h"
#include "../Profile/Profile.h"
#include "../UI/UIButton.h"

namespace Cori { namespace MainMenu {

State gMenuState {};

// UI Elements

UIButton* cardViewButton;
UIButton* setViewButton;
UIButton* packSimButton;
UIButton* collectionButton;
UIButton* deckBuilderButton;

UIButton* profileButton;

void setCardViewColors() {
    cardViewButton->setPressedColor(sf::Color::Red);
    cardViewButton->setHoverColor(sf::Color::Green);
    cardViewButton->setBackgroundColor(sf::Color::Cyan);

    cardViewButton->getTextbox().setTextPressedColor(sf::Color::Black);
    cardViewButton->getTextbox().setTextHoverColor(sf::Color::Magenta);
    cardViewButton->getTextbox().setTextColor(sf::Color::Red);
}

void initCardViewButton() {
    cardViewButton = new UIButton(100.0f, 60.0f);
    cardViewButton->setPositionRelativeTo(UIElement::ScreenCenter);
    cardViewButton->setText("Card View");
    cardViewButton->centerButtonText();

    setCardViewColors();

    cardViewButton->createClickFunction([]() {
        gSetState(SetViewer::gSetViewerState);
    });
}

void initSetViewButton() {
    setViewButton = new UIButton(100.0f, 60.0f);
    setViewButton->setText("Set View");
    setViewButton->centerButtonText();

    setViewButton->createClickFunction([]() {
        gSetState(SetFullView::gSetFullViewState);
    });
}

void initPackSimButton() {
    packSimButton = new UIButton(100.0f, 60.0f);
    packSimButton->setText("Pack Sim");
    packSimButton->setPositionRelativeTo(*setViewButton, 110.0f, 0.0f);
    packSimButton->centerButtonText();

    packSimButton->createClickFunction([]() {
        gSetState(PackSimulator::gPackSimulatorState);
    });
}

void initCollectionButton() {
    collectionButton = new UIButton(100.0f, 60.0f);
    collectionButton->setText("Collection");
    collectionButton->setPositionRelativeTo(*packSimButton, 110.0f, 0.0f);
    collectionButton->centerButtonText();
    
    collectionButton->createClickFunction([]() {
        gSetState(CollectionView::gCollectionViewState);
    });
}

void initDeckBuilderButton() {
    deckBuilderButton = new UIButton(100.0f, 60.0f);
    deckBuilderButton->setText("Deck Builder");
    deckBuilderButton->setPositionRelativeTo(*collectionButton, 110.0f, 0.0f);
    deckBuilderButton->centerButtonText();
    
    deckBuilderButton->createClickFunction([]() {
        gSetState(DeckBuilder::gDeckBuilderState);
    });
}

void initProfileButton() {
    profileButton = new UIButton(gWindowWidth - 100.0f, 0.0f, 100.0f, 60.0f);
    profileButton->setText(gCurrentProfile.username);
    profileButton->centerButtonText();

    profileButton->createClickFunction([]() {
        gSetState(ProfileView::gProfileViewState);
    });
}

void addElements() {
    gMenuState.addUIElement(cardViewButton);
    gMenuState.addUIElement(setViewButton);
    gMenuState.addUIElement(packSimButton);
    gMenuState.addUIElement(collectionButton);
    gMenuState.addUIElement(deckBuilderButton);
    gMenuState.addUIElement(profileButton);
}

void initMenuState() {
    initCardViewButton();
    initSetViewButton();
    initPackSimButton();
    initCollectionButton();
    initDeckBuilderButton();
    initProfileButton();

    addElements();
}

}}