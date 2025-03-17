#include "State.h"
#include "../Random.h"
#include "../Window.h"
#include "../Cards/Expansion.h"
#include "../Cards/Expansions/Expansions.h"
#include "../Profile/Profile.h"
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
    displayIndex = -1;
    //cardPack->changeTexture(gCardBackTexture);
    instructText->setText("Click to Open");
    packPanel->destroyClickFunction();
    packGenerated = false;
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
    for(int i = quantity - 1; i >= 0; --i) {
        delete packPanel->getElements()[i];
        packPanel->getElements().pop_back();
    }
}

void generateCardImages(std::vector<DataCard*>& cards) {
    for(int i = int(cards.size()) - 1; i >= 0; --i) {
        UIImage* image = new UIImage(cardPack->getX() + (i * 100), cardPack->getY(), gCardBackTexture);
        packPanel->addElement(image);
    }
    packPanel->createClickFunction(
        [=]() {
            if(displayIndex == int(cards.size()) - 1) 
                clearCardImages(int(cards.size()));
            else {
                for(UIElement* element : packPanel->getElements()) {
                    element->move(-100.0f, 0.0f);
                }
                rotateCards(displayIndex);
            }
            updateDisplay();
        }
    );
}

DataCard* generateNewCard(Rarity rarity, std::vector<DataCard*>& cards) {
    DataCard* card;
    do {
        card = currentExpansion->getCardsByRarity(rarity)[
            Random::get(currentExpansion->cardCountOfRarity(rarity))
        ];
    } while (std::find(cards.begin(), cards.end(), card) != cards.end());

    std::cout << '\n' << card->cardNameString();

    return card;
}


std::vector<DataCard*> generatePulls() {
    std::vector<DataCard*> cards {};

    std::cout << "=== You Pulled ==="; 
    for(Rarity rarity : currentExpansion->packRarities()) {
        DataCard* card { generateNewCard(rarity, cards) };
        cards.push_back(card);
        gCurrentProfile.addToCollection({ card->mExpansion, card->mCardNumber });
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

    collectionButton = new UIButton(100.0f, 50.0f);
    collectionButton->setPositionRelativeTo(UIElement::ScreenTopRight, -40.0f, -40.0f);
    collectionButton->setText("Collection");
    collectionButton->centerButtonText();
    collectionButton->createClickFunction(
        [&]() {
            gCurrentProfile.collection.printCollection();
        }
    );

    //UIElement* rect = new UIElement(50, centeredCardPosition().y + 40, 50, 825);

    gPackSimulatorState.addUIElement(cardPack);
    //gPackSimulatorState.addUIElement(rect);

    //UIElement* rect2 = new UIElement(100, centeredCardPosition().y + 40, 50, 825);
    //rect2->setBackgroundColor(sf::Color::Red);
    //packPanel->addElement(rect2);

    gPackSimulatorState.addUIElement(packPanel);
    gPackSimulatorState.addUIElement(instructText);
    gPackSimulatorState.addUIElement(expansionDropdown);

    gPackSimulatorState.addUIElement(collectionButton);

}

}}