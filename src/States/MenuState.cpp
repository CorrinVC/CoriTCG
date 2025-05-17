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

    cardViewButton->setTextPressedColor(sf::Color::Black);
    cardViewButton->setTextHoverColor(sf::Color::Magenta);
    cardViewButton->setTextColor(sf::Color::Red);
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
    if(gLoggedIn) profileButton->setText(gCurrentProfile.username);
    else profileButton->setText("Log In");
    profileButton->centerButtonText();

    profileButton->createClickFunction([=]() {
        if(gLoggedIn) gSetState(ProfileView::gProfileViewState);
        else gSetState(Login::gLoginState);
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
    gMenuState.setOnSwitch([=]() {
        if(gLoggedIn && profileButton->getButtonText() != gCurrentProfile.username) {
            profileButton->setText(gCurrentProfile.username);
            profileButton->centerButtonText();
        }
    });
    
    initCardViewButton();
    initSetViewButton();
    initPackSimButton();
    initCollectionButton();
    initDeckBuilderButton();
    initProfileButton();

    addElements();
}

}}