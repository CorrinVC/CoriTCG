#include "State.h"
#include "../Window.h"
#include "../Cards/Card.h"
#include "../Cards/Expansion.h"
#include "../UI/UIButton.h"
#include "../UI/UIDropdown.h"
#include "../UI/UIImage.h"
#include <format>

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
            Expansion::gExpansionList[currentExpansionIndex].expansionAbbreviation, 
            Expansion::gExpansionList[currentExpansionIndex].expansionLowerAbbreviation(),
            currentCardID) 
        : "card-back.png";
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
            mainCardDisplay->changeTexture(getCurrentCardTexturePath());
            //currentCardTextbox->setText(expansionDropdown->getSelectedText());
        }
    );
    gSetViewerState.addUIElement(expansionDropdown);

    UIButton* incrementButton = new UIButton(gWindowWidth - 100.0f, mainCardDisplay->getY(), 50.0f, 50.0f);
    incrementButton->createClickFunction(
        [=]() {
            if(currentCardID > 0 && 
                currentCardID <= Expansion::gExpansionList[currentExpansionIndex].cardCount) {
                ++currentCardID;
                mainCardDisplay->changeTexture(getCurrentCardTexturePath());
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
                mainCardDisplay->changeTexture(getCurrentCardTexturePath());
            }
        }
    );
    decrementButton->getTextbox().setText("<");
    decrementButton->getTextbox().centerTextRelativeTo(*decrementButton);
    gSetViewerState.addUIElement(decrementButton);
}

}

}