#include "State.h"
#include "../Window.h"
#include "../Cards/Expansions/Expansions.h"
#include "../UI/UIButton.h"
#include "../UI/UIDropdown.h"
#include "../UI/UIImage.h"

namespace Cori { namespace SetViewer {

State gSetViewerState {};

// UI Elements

UIImage* mainCardDisplay;
UITextbox* currentCardTextbox;
UIDropdown* expansionDropdown;

UIButton* backButton;
UIButton* incrementButton;
UIButton* decrementButton;

// Reference Variables

int currentCardID { 0 };
Expansion* currentExpansion { Expansions::gExpansionList[ExpansionID::BaseSet] };

sf::Texture getCurrentCardTexture() {
    return sf::Texture(
        currentCardID > 0
        ? currentExpansion->cards[currentCardID - 1]->mTexture
        : gCardBackTexture  
    );
}

void changeCardInfo() {
    mainCardDisplay->changeTexture(getCurrentCardTexture());
    
    if(currentCardID > 0)
        currentCardTextbox->setText(currentExpansion->cards[currentCardID - 1]->mCardName);
    else
        currentCardTextbox->setText(gDefaultString);
    currentCardTextbox->centerText();
}

void setSelectedCard(int cardID, Expansion* expansion) {
    currentCardID = cardID;
    currentExpansion = expansion;
    changeCardInfo();
    expansionDropdown->setSelectedIndex(expansion->expansionID);
}

void setSelectedCard(int cardID, int expansionID) {
    setSelectedCard(cardID, Expansions::gExpansionList[expansionID]);
}

void initCurrentCardTextbox() {
    currentCardTextbox = new UITextbox(300.0f, 60.0f, "", true);
    currentCardTextbox->setPositionRelativeTo(UIElement::ScreenTop, 55.0f);
    currentCardTextbox->centerText();
}

void updateExpansion(int expIndex) {
    if(expIndex < 0) currentCardID = 0;
    else if(currentExpansion->expansionID != expIndex) {
        currentCardID = 1;
        currentExpansion = Expansions::gExpansionList[expIndex];
    }

    changeCardInfo();
}

void initExpansionDropdown() {
    expansionDropdown = new UIDropdown(gWindowWidth / 2.0f - 150.0f, 10.0f, 300.0f, 40.0f, "Select Expansion",
        Expansions::gExpansionNames());
    expansionDropdown->setPositionRelativeTo(UIElement::ScreenTop, 10.0f);
    
    expansionDropdown->createClickFunction([=]() {
        updateExpansion(expansionDropdown->getSelectedIndex());
    });
}

void initIncrementButton() {
    incrementButton = new UIButton(gWindowWidth - 100.0f, mainCardDisplay->getY(), 50.0f, 50.0f);
    incrementButton->setText(">");
    incrementButton->centerButtonText();
    
    incrementButton->createClickFunction([=]() {
        if(currentCardID > 0 &&
            currentCardID < currentExpansion->cardCount()) {
            ++currentCardID;
            changeCardInfo();
        }
    });
}

void initDecrementButton() {
    decrementButton = new UIButton(100.f, mainCardDisplay->getY(), 50.0f, 50.0f);
    decrementButton->setText("<");
    decrementButton->centerButtonText();

    decrementButton->createClickFunction([=]() {
        if(currentCardID > 1) {
            --currentCardID;
            changeCardInfo();
        }
    });
}

void addElements() {
    gSetViewerState.addUIElement(mainCardDisplay);
    gSetViewerState.addUIElement(currentCardTextbox);
    gSetViewerState.addUIElement(expansionDropdown);

    gSetViewerState.addUIElement(backButton);
    gSetViewerState.addUIElement(incrementButton);
    gSetViewerState.addUIElement(decrementButton);
}

void initSetViewerState() {
    mainCardDisplay = new UIImage(centeredCardPosition().x, centeredCardPosition().y, getCurrentCardTexture());
    initCurrentCardTextbox();
    initExpansionDropdown();

    backButton = new BackButton(20.0f, 20.0f, 75.0f, 40.0f);
    initIncrementButton();
    initDecrementButton();

    addElements();
}

}}