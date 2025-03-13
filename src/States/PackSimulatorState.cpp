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
int displayIndex { 0 };
bool packGenerated { false };

// Temporary
std::vector<Rarity> rarities {
    Rarity::Rare, Rarity::Uncommon, Rarity::Uncommon, Rarity::Uncommon,
    Rarity::Common, Rarity::Common, Rarity::Common, Rarity::Common, Rarity::Common,
    Rarity::None, Rarity::None
};

DataCard* generateCard(Rarity rarity) {
    return { currentExpansion->getCardsByRarity(rarity)
        [Random::get(currentExpansion->cardCountOfRarity(rarity))] };
}

void generateCardImages(std::vector<DataCard*>& cards) {
    for(int i = int(cards.size()) - 1; i >= 0; --i) {
        UIImage* image = new UIImage(cardPack->getX() + (i * 100), cardPack->getY(), cards[i]->mTexture);
        image->createClickFunction(
            [=]() {
                for(UIElement* element : packPanel->getElements())
                    element->move(-100.0f, 0.0f);
                    
                packPanel->getElements().pop_back();
                //packPanel->getElements().insert(0, image);
            }
        );
        
        packPanel->addElement(image);
    }
}

void clearCardImages(int quantity) {
    for(int i = 0; i < quantity; i++)
        gPackSimulatorState.popUIElement();
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

void setDefaults() {
    displayIndex = 0;
    //cardPack->changeTexture(gCardBackTexture);
    instructText->setText("Click to Open");
}

void updateDisplay() {
    // Set Display to First Pulled Card
    //cardPack->changeTexture(currentPack[displayIndex]->mTexture);
    instructText->setText(currentPack[displayIndex]->cardNameString());

    // Cycle Through Pulled Cards
    if(displayIndex < int(currentPack.size()))
        ++displayIndex;
    else { // Restore to Default T
        packGenerated = false;
        setDefaults();
    }
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
                std::cout << "Pack Generated" << std::endl;
                packGenerated = true;
            }
            updateDisplay();
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

    gPackSimulatorState.addUIElement(cardPack);
    gPackSimulatorState.addUIElement(packPanel);
    gPackSimulatorState.addUIElement(instructText);
    gPackSimulatorState.addUIElement(expansionDropdown);
}

}

}