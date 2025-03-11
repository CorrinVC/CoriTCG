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

// Temporary
std::vector<Rarity> rarities {
    Rarity::Rare, Rarity::Uncommon, Rarity::Uncommon, Rarity::Uncommon,
    Rarity::Common, Rarity::Common, Rarity::Common, Rarity::Common, Rarity::Common,
    Rarity::None, Rarity::None
};

void generatePulls() {
    std::cout << "=== You Pulled ==="; 
    for(int i { 0 }; i < currentExpansion->packQuantity; ++i) {
        std::cout << '\n' << currentExpansion->getCardsByRarity(rarities[i])
            [Random::get(currentExpansion->cardCountOfRarity(rarities[i]))]->cardNameString();
    }
    std::cout << std::endl;
}

void initPackSimState() {
    cardPack = new UIImage(centeredCardPosition().x, centeredCardPosition().y + 40.0f,
        gCardBackTexture);
    cardPack->createClickFunction(
        [=]() {
            if(currentExpansion == nullptr) return;
            generatePulls();
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