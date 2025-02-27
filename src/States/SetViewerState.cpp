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

// Top Left Co-ordinate of a Centered Card Image
constexpr sf::Vector2f centeredCardPosition() {
    return { 
        gWindowWidth / 2.0f - gCardWidth / 2.0f,
        gWindowHeight / 2.0f - gCardHeight / 2.0f
    };
}

int currentCardID { 0 }; // default to Card Back (0), otherwise card collector #
int currentExpansionIndex { 0 }; // CHANGE - reference global expansion vars

// Returns Local Texture Path of Current Card, or Card Back Texture Path
// Currently Only Used to Initialize Current Card UIImage
std::string getCurrentCardTexturePath() {
    return currentCardID > 0 
        ? std::format("cards/{}/{}{}.png", 
            Expansions::gExpansionList[currentExpansionIndex]->expansionAbbreviation(), 
            Expansions::gExpansionList[currentExpansionIndex]->expansionLowerAbbreviation(),
            currentCardID) 
        : "card-back.png";
}

// Returns Current Card's Texture Object, or Card Back Texture
sf::Texture getCurrentCardTexture() {
    return sf::Texture( 
        currentCardID > 0
        ? Expansions::gExpansionList[currentExpansionIndex]->cards[currentCardID - 1]->mTexture
        : gCardBackTexture
    );
}

// Update Current Card UIImage Texture, 'Header' Textbox Text
void changeCardInfo(UIImage* image, UITextbox* textbox) {
    image->changeTexture(getCurrentCardTexture());

    // Update 'Header' Textbox to Card Name
    if(currentCardID > 0)
        textbox->setText(Expansions::gExpansionList[currentExpansionIndex]->cards[currentCardID - 1]->mCardName);
    else // Clear 'Header' Textbox if no dropdown selection
        textbox->setText(gDefaultString);
        
    textbox->centerText();
}

void initSetViewerState() {

    // Central UIImage to Display Current Card
    UIImage* mainCardDisplay = new UIImage(
        centeredCardPosition().x, centeredCardPosition().y + 50.0f, getCurrentCardTexturePath());

    gSetViewerState.addUIElement(mainCardDisplay);

    // 'Header'-Like Textbox Above Main Card Display
    // Used to Display Card Name & Other Info (in the future)
    UITextbox* currentCardTextbox = new UITextbox(300.0f, 60.0f, "", true); // Set Transparent
    currentCardTextbox->setPositionRelativeTo(UIElement::ScreenTop, 55.0f);
    currentCardTextbox->centerText();
    gSetViewerState.addUIElement(currentCardTextbox);

    // Dropdown to Switch Between Expansions
    UIDropdown* expansionDropdown = new UIDropdown(gWindowWidth / 2.0f - 150.0f, 10.0f, 300.0f, 40.0f, "Select Expansion", 
        { "Base Set", "Jungle", "Fossil" });
    expansionDropdown->setPositionRelativeTo(UIElement::ScreenTop, 10.0f);
    expansionDropdown->createClickFunction(
        [=]() {
            if(expansionDropdown->getSelectedText() == gDefaultString)
                currentCardID = 0; // Set to Default (Card Back Image)
            else {
                currentCardID = 1; // Reset Card # to Beginning of Expansion
                currentExpansionIndex = expansionDropdown->getSelectedIndex(); // CHANGE? To reference expansion vars?
            }
            changeCardInfo(mainCardDisplay, currentCardTextbox); // Update Related UIElements
        }
    );
    gSetViewerState.addUIElement(expansionDropdown);

    // Button to Cycle (Up/Right) Through Expansion
    UIButton* incrementButton = new UIButton(gWindowWidth - 100.0f, mainCardDisplay->getY(), 50.0f, 50.0f);
    incrementButton->createClickFunction(
        [=]() {
            // Ensure Card ID is Cyclable
            if(currentCardID > 0 && // Do Not Increment if Card Back is Shown 
                currentCardID < Expansions::gExpansionList[currentExpansionIndex]->cardCount()) {
                ++currentCardID;
                changeCardInfo(mainCardDisplay, currentCardTextbox);
            }
        }
    );
    incrementButton->getTextbox().setText(">");
    incrementButton->getTextbox().centerTextRelativeTo(*incrementButton);
    gSetViewerState.addUIElement(incrementButton);

    // Button to Cycle (Down/Left) Through Expansion
    UIButton* decrementButton = new UIButton(100.0f, mainCardDisplay->getY(), 50.0f, 50.0f);
    decrementButton->createClickFunction(
        [=]() {
            if(currentCardID > 1) { // Ensure Card ID is Left Cyclable
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