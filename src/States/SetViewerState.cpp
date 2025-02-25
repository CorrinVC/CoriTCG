#include "State.h"
#include "../Window.h"
#include "../Cards/Card.h"
#include "../Cards/Expansions/Expansions.h"
#include "../UI/UIButton.h"
#include "../UI/UIDropdown.h"
#include "../UI/UIImage.h"
#include <format>
#include <iostream>

namespace Cori {

namespace SetViewer {

State gSetViewerState {};

constexpr sf::Vector2f centeredCardPosition() {
    return { 
        gWindowWidth / 2.0f - gCardWidth / 2.0f,
        gWindowHeight / 2.0f - gCardHeight / 2.0f
    };
}

int currentCardID { 0 }; //default to Card Back
int currentExpansionIndex { 0 };

std::string getCurrentCardTexturePath() {
    return currentCardID > 0 
        ? std::format("cards/{}/{}{}.png", 
            Expansions::gExpansionList[currentExpansionIndex]->expansionAbbreviation, 
            Expansions::gExpansionList[currentExpansionIndex]->expansionLowerAbbreviation(),
            currentCardID) 
        : "card-back.png";
}

void changeCardInfo(UIImage* image, UITextbox* textbox) {
    image->changeTexture(getCurrentCardTexturePath());
    textbox->setText(Expansions::gExpansionList[currentExpansionIndex]->cards[currentCardID - 1]->getCardName());
    textbox->centerText();
}

void initSetViewerState() {

    UIImage* mainCardDisplay = new UIImage(centeredCardPosition().x, centeredCardPosition().y + 50.0f, getCurrentCardTexturePath());
    //mainCardDisplay->setSize({ gCardWidth, gCardHeight });
    gSetViewerState.addUIElement(mainCardDisplay);

    UITextbox* currentCardTextbox = new UITextbox(300.0f, 60.0f, "Big Schmenis");
    currentCardTextbox->setPositionRelativeTo(UIElement::ScreenTop, 65.0f);
    currentCardTextbox->centerText();
    //expansionTextbox->centerText();
    gSetViewerState.addUIElement(currentCardTextbox);

    UIDropdown* expansionDropdown = new UIDropdown(gWindowWidth / 2.0f - 150.0f, 10.0f, 300.0f, 40.0f, "Select Expansion", 
        { "Base Set", "Jungle", "Fossil" });
    expansionDropdown->setPositionRelativeTo(UIElement::ScreenTop, 10.0f);
    expansionDropdown->createClickFunction(
        [=]() {
            if(expansionDropdown->getSelectedText() == gDefaultString)
                currentCardID = 0;
            else {
                currentCardID = 1;
                currentExpansionIndex = expansionDropdown->getSelectedIndex();
            }
            changeCardInfo(mainCardDisplay, currentCardTextbox);
        }
    );
    gSetViewerState.addUIElement(expansionDropdown);

    UIButton* incrementButton = new UIButton(gWindowWidth - 100.0f, mainCardDisplay->getY(), 50.0f, 50.0f);
    incrementButton->createClickFunction(
        [=]() {
            if(currentCardID > 0 && 
                currentCardID < Expansions::gExpansionList[currentExpansionIndex]->cardCount()) {
                ++currentCardID;
                changeCardInfo(mainCardDisplay, currentCardTextbox);
            }
        }
    );
    incrementButton->getTextbox().setText(">");
    incrementButton->getTextbox().centerTextRelativeTo(*incrementButton);
    gSetViewerState.addUIElement(incrementButton);

    UIButton* decrementButton = new UIButton(100.0f, mainCardDisplay->getY(), 50.0f, 50.0f);
    decrementButton->createClickFunction(
        [=]() {
            if(currentCardID > 1) {
                --currentCardID;
                changeCardInfo(mainCardDisplay, currentCardTextbox);
            }
        }
    );
    decrementButton->getTextbox().setText("<");
    decrementButton->getTextbox().centerTextRelativeTo(*decrementButton);
    gSetViewerState.addUIElement(decrementButton);
}

}

}