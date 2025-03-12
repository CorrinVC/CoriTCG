#include "State.h"
#include "../Random.h"
#include "../Window.h"
#include "../Cards/Expansion.h"
#include "../Cards/Expansions/Expansions.h"

namespace Cori {

namespace PackSimulator {

State gPackSimulatorState;

// UI Elements
UIImage* cardPack;
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
    std::cout << std::endl;
    return cards;
}

void setDefaults() {
    displayIndex = 0;
    cardPack->changeTexture(gCardBackTexture);
    instructText->setText("Click to Open");
}

void updateDisplay() {
    // Set Display to First Pulled Card
    cardPack->changeTexture(currentPack[displayIndex]->mTexture);
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
                packGenerated = true;
            }
            updateDisplay();
        }
    );

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
    gPackSimulatorState.addUIElement(instructText);
    gPackSimulatorState.addUIElement(expansionDropdown);
}

}

}