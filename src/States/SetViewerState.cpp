#include "State.h"
#include "../Window.h"
#include "../Cards/Expansions/Expansions.h"
#include "../UI/UIButton.h"
#include "../UI/UIDropdown.h"
#include "../UI/UIImage.h"
#include <format>

namespace Cori {

namespace SetViewer {

State gSetViewerState {};

int currentCardID { 0 }; // default to Card Back (0), otherwise card collector #
Expansion* currentExpansion { Expansions::gExpansionList[ExpansionID::BaseSet] }; // CHANGE - reference global expansion vars

// UI Elements
UIImage* mainCardDisplay;
UITextbox* currentCardTextbox;
UIDropdown* expansionDropdown;

UIButton* backButton;
UIButton* incrementButton;
UIButton* decrementButton;

/* Returns Local Texture Path of Current Card, or Card Back Texture Path
// Currently Only Used to Initialize Current Card UIImage
std::string getCurrentCardTexturePath() {
    return currentCardID > 0 
        ? std::format("cards/{}/{}{}.png", 
            currentExpansion->expansionAbbreviation(), 
            currentExpansion->expansionLowerAbbreviation(),
            currentCardID) 
        : "card-back.png";
}*/

// Returns Current Card's Texture Object, or Card Back Texture
sf::Texture getCurrentCardTexture() {
    return sf::Texture( 
        currentCardID > 0
        ? currentExpansion->cards[currentCardID - 1]->mTexture
        : gCardBackTexture
    );
}

// Update Current Card UIImage Texture, 'Header' Textbox Text
void changeCardInfo() {
    mainCardDisplay->changeTexture(getCurrentCardTexture());

    // Update 'Header' Textbox to Card Name
    if(currentCardID > 0)
        currentCardTextbox->setText(currentExpansion->cards[currentCardID - 1]->mCardName);
    else // Clear 'Header' Textbox if no dropdown selection
        currentCardTextbox->setText(gDefaultString);
        
    currentCardTextbox->centerText();
}

// External Function to Manipulate Current Card
void setSelectedCard(int cardID, Expansion* expansion) {
    currentCardID = cardID;
    currentExpansion = expansion;
    changeCardInfo();
    expansionDropdown->setSelectedIndex(expansion->expansionID);
}

void setSelectedCard(int cardID, int expansionID) {
    setSelectedCard(cardID, Expansions::gExpansionList[expansionID]);
}

void updateExpansion(UIDropdown* dropdown) {
    if(dropdown->getSelectedText() == gDefaultString)
        currentCardID = 0;
    // Do Not Reset if Same Expansion Selected
    else if(currentExpansion->expansionID != expansionDropdown->getSelectedIndex()) {
        currentCardID = 1;
        currentExpansion = Expansions::gExpansionList[expansionDropdown->getSelectedIndex()];
    }

    changeCardInfo();
}

void initSetViewerState() {

    // Central UIImage to Display Current Card
    mainCardDisplay = new UIImage(
        centeredCardPosition().x, centeredCardPosition().y + 50.0f, getCurrentCardTexture());

    // 'Header'-Like Textbox Above Main Card Display
    // Used to Display Card Name & Other Info (in the future)
    currentCardTextbox = new UITextbox(300.0f, 60.0f, "", true); // Set Transparent
    currentCardTextbox->setPositionRelativeTo(UIElement::ScreenTop, 55.0f);
    currentCardTextbox->centerText();

    // Dropdown to Switch Between Expansions
    expansionDropdown = new UIDropdown(gWindowWidth / 2.0f - 150.0f, 10.0f, 300.0f, 40.0f, "Select Expansion", 
        Expansions::gExpansionNames());
    expansionDropdown->setPositionRelativeTo(UIElement::ScreenTop, 10.0f);
    expansionDropdown->createClickFunction(
        [=]() {
            updateExpansion(expansionDropdown);
        }
    );

    // Back Button - TODO Set to Variable Previous State
    backButton = new BackButton(20.0f, 20.0f, 75.0f, 40.0f);

    // Button to Cycle (Up/Right) Through Expansion
    incrementButton = new UIButton(gWindowWidth - 100.0f, mainCardDisplay->getY(), 50.0f, 50.0f);
    incrementButton->createClickFunction(
        [=]() {
            // Ensure Card ID is Right Cyclable
            if(currentCardID > 0 && // Do Not Increment if Card Back is Shown 
                currentCardID < currentExpansion->cardCount()) {
                ++currentCardID;
                changeCardInfo();
            }
        }
    );
    incrementButton->setText(">");
    incrementButton->centerButtonText();

    // Button to Cycle (Down/Left) Through Expansion
    decrementButton = new UIButton(100.0f, mainCardDisplay->getY(), 50.0f, 50.0f);
    decrementButton->createClickFunction(
        [=]() {
            if(currentCardID > 1) { // Ensure Card ID is Left Cyclable
                --currentCardID;
                changeCardInfo();
            }
        }
    );
    decrementButton->setText("<");
    decrementButton->centerButtonText();

    gSetViewerState.addUIElement(mainCardDisplay);
    gSetViewerState.addUIElement(currentCardTextbox);
    gSetViewerState.addUIElement(expansionDropdown);

    gSetViewerState.addUIElement(backButton);
    gSetViewerState.addUIElement(incrementButton);
    gSetViewerState.addUIElement(decrementButton);
}

}

}