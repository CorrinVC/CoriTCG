#include "State.h"
#include "../Random.h"
#include "../Window.h"
#include "../Cards/Expansion.h"
#include "../Cards/Expansions/Expansions.h"
#include "../UI/UIButton.h"
#include "../UI/UIDropdown.h"
#include "../UI/UIImage.h"
#include "../UI/UIPanel.h"
#include "../UI/UITextbox.h"

namespace Cori {

namespace PackSimulator {

State gPackSimulatorState;

// UI Elements
UIImage* cardPack;
UIPanel* packPanel;
UITextbox* instructText;
UIDropdown* expansionDropdown;

UIButton* backButton;
UIButton* collectionButton;

Expansion* currentExpansion;
std::vector<DataCard*> currentPack {};
int displayIndex { -1 };
bool packGenerated { false };

//std::vector<int> cardIndexes { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };

void setDefaults() {
    displayIndex = 0;
    //cardPack->changeTexture(gCardBackTexture);
    instructText->setText("Click to Open");
    packPanel->destroyClickFunction();
}

void updateDisplay() {
    ++displayIndex;

    // Cycle Through Pulled Cards
    if(displayIndex < int(currentPack.size())) {
        static_cast<UIImage*>(packPanel->getElements().back())->changeTexture(
            currentPack[displayIndex]->mTexture);
        instructText->setText(currentPack[displayIndex]->cardNameString());
    }
    else { // Restore to Default T
        packGenerated = false;
        setDefaults();
    }
}

// Pulls next card to front, pushes previous cards backward
void rotateCards(int cardIndex) {
    std::rotate(packPanel->getElements().end() - 2 - cardIndex,
        packPanel->getElements().end() - 1 - cardIndex,
        packPanel->getElements().end());
}

void clearCardImages(int quantity) {
    for(int i = 0; i < quantity; i++) {
        packPanel->getElements().pop_back();
    }
}

void generateCardImages(std::vector<DataCard*>& cards) {
    for(int i = int(cards.size()) - 1; i >= 0; --i) {
        UIImage* image = new UIImage(cardPack->getX() + (i * 100), cardPack->getY(), gCardBackTexture);
        /*if(i == int(cards.size()) - 1) { // Last Card Image
            image->createClickFunction(
                [=]() { 
                    updateDisplay();
                    clearCardImages(i + 1); 
                }
            );
        } else {
            image->createClickFunction(
                [=]() {
                    // Shift Card Imgs
                    for(UIElement* element : packPanel->getElements())
                        element->move(-100.0f, 0.0f);

                    rotateCards(i);
                    updateDisplay();
                }
            );
        }*/
        packPanel->addElement(image);
    }
    packPanel->createClickFunction(
        [=]() {
            if(displayIndex == int(cards.size()) - 1) 
                clearCardImages(int(cards.size()));
            else {
                for(UIElement* element : packPanel->getElements())
                    element->move(-100.0f, 0.0f);
                rotateCards(displayIndex);
            }
            updateDisplay();
        }
    );
}

DataCard* generateCard(Rarity rarity) {
    return { currentExpansion->getCardsByRarity(rarity)
        [Random::get(currentExpansion->cardCountOfRarity(rarity))] };
}

std::vector<DataCard*> generatePulls() {
    std::vector<DataCard*> cards {};

    std::cout << "=== You Pulled ==="; 
    for(Rarity rarity : currentExpansion->packRarities()) {
        DataCard* card;
        do card = generateCard(rarity);
        while(std::find(cards.begin(), cards.end(), card) != cards.end());

        cards.push_back(card);
        std::cout << '\n' << card->cardNameString();
    }

    generateCardImages(cards);
    std::cout << std::endl;
    return cards;
}

void initPackSimState() {
    cardPack = new UIImage(centeredCardPosition().x, centeredCardPosition().y + 40.0f,
        gCardBackTexture);
    cardPack->createClickFunction(
        [=]() {
            if(currentExpansion == nullptr) return;
            if(!packGenerated) { // Display on Default Texture
                instructText->setText("Click to Open!");
                currentPack = generatePulls();
                
                packGenerated = true;
                updateDisplay();
            }
        }
    );

    packPanel = new UIPanel(gWindowWidth, gWindowHeight);
    packPanel->setBackgroundColor(sf::Color::Transparent);

    instructText = new UITextbox(400.0f, 50.0f, "Select an Expansion", true);
    instructText->setPositionRelativeTo(UIElement::ScreenTop, 70.0f);
    instructText->centerText();

    expansionDropdown = new UIDropdown(300.0f, 40.0f, "Select Expansion",
        Expansions::gExpansionNames());
    expansionDropdown->setPositionRelativeTo(UIElement::ScreenTop, 20.0f);
    expansionDropdown->createClickFunction(
        [=]() {
            currentExpansion = Expansions::gExpansionList[expansionDropdown->getSelectedIndex()];
        }
    );
    expansionDropdown->alignText();

    UIElement* rect = new UIElement(centeredCardPosition().x, centeredCardPosition().y+30, 50, 50);

    gPackSimulatorState.addUIElement(cardPack);
    //gPackSimulatorState.addUIElement(rect);
    gPackSimulatorState.addUIElement(packPanel);
    gPackSimulatorState.addUIElement(instructText);
    gPackSimulatorState.addUIElement(expansionDropdown);
}

}

}