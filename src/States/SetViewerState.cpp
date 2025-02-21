#include "State.h"
#include "../Window.h"
#include "../Cards/Card.h"
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
std::string getCurrentCardTexturePath() {
    return currentCardID > 0 
        ? std::format("cards/BS/bs{}.png", currentCardID) 
        : "card-back.png";
}

void initSetViewerState() {
    UIImage* mainCardDisplay = new UIImage(centeredCardPosition().x, centeredCardPosition().y, getCurrentCardTexturePath());
    //mainCardDisplay->setSize({ gCardWidth, gCardHeight });
    gSetViewerState.addUIElement(mainCardDisplay);

    UITextbox* expansionTextbox = new UITextbox(200.0f, 40.0f, "", true);
    //expansionTextbox->centerText();
    gSetViewerState.addUIElement(expansionTextbox);

    UIDropdown* expansionDropdown = new UIDropdown(centeredCardPosition().x, centeredCardPosition().y - 50.0f, 250.0f, 40.0f, "Select Expansion", 
        { "Base Set", "Jungle", "Fossil" });
    expansionDropdown->createClickFunction(
        [=]() {
            currentCardID = 0;
            mainCardDisplay->changeTexture(getCurrentCardTexturePath());
            expansionTextbox->setText(expansionDropdown->getSelectedText());
        }
    );
    gSetViewerState.addUIElement(expansionDropdown);

    UIButton* incrementButton = new UIButton(gWindowWidth - 100.0f, expansionDropdown->getY(), 50.0f, 50.0f);
    incrementButton->createClickFunction(
        [=]() {
            ++currentCardID;
            mainCardDisplay->changeTexture(getCurrentCardTexturePath());
        }
    );
    gSetViewerState.addUIElement(incrementButton);

    /*UIReferenceTextbox* expansionRTextbox = new UIReferenceTextbox(200.0f, 40.0f, 
            &(expansionDropdown->getSelectedText()));
    expansionRTextbox->centerText();
    gSetViewerState.addUIElement(expansionRTextbox);*/
}

}

}