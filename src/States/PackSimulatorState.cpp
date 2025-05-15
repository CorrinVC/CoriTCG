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

namespace Cori { namespace PackSimulator {

State gPackSimulatorState {};

// UI Elements

UIImage* cardPack;
UIPanel* packPanel;
UITextbox* instructText;
UIDropdown* expansionDropdown;

UIButton* backButton;
UIButton* collectionButton;

// Reference Variables

Expansion* currentExpansion { nullptr };

std::vector<DataCard*> currentPack {};
int displayIndex { -1 };
bool packGenerated { false };

void setDefaults() {
    displayIndex = -1;
    instructText->setText("Click to Open");
    packPanel->destroyClickFunction();
    packGenerated = false;
}

void updateDisplay() {
    ++displayIndex;

    if(displayIndex < int(currentPack.size())) {
        static_cast<UIImage*>(packPanel->getElements().back())->changeTexture(
            currentPack[displayIndex]->mTexture);
        instructText->setText(currentPack[displayIndex]->cardNameString());
    } else
        setDefaults();
}

DataCard* generateNewCard(Rarity rarity, const std::vector<DataCard*>& cards) {
    DataCard* card;

    do {
        card = currentExpansion->getCardsByRarity(rarity)
            [Random::get(currentExpansion->cardCountOfRarity(rarity))];
    } while (std::find(cards.begin(), cards.end(), card) != cards.end());
    std::cout << '\n' << card->cardNameString();

    return card;
}

void clearCardImages(int quantity) {
    for(int i = quantity - 1; i >= 0; --i) {
        delete packPanel->getElements()[i];
        packPanel->getElements().pop_back();
    }
}

void rotateCards() {
    std::rotate(packPanel->getElements().end() - 2 - displayIndex,
        packPanel->getElements().end() - 1 - displayIndex,
        packPanel->getElements().end());
}

void moveCardImages() {
    for(UIElement* element : packPanel->getElements())
        element->move(-100.0f, 0.0f);
    
    rotateCards();
}

void cyclePulls(const std::vector<DataCard*>& pulls) {
    if(displayIndex == int(pulls.size()) - 1)
        clearCardImages(int(pulls.size()));
    else
        moveCardImages();

    updateDisplay();
}

void generateCardImages(const std::vector<DataCard*>& cards) {
    for(int i = int(cards.size()) - 1; i >= 0; --i) {
        UIImage* image = new UIImage(cardPack->getX() + (i * 100), cardPack->getY(), gCardBackTexture);
        packPanel->addElement(image);
    }

    packPanel->createClickFunction([=]() { cyclePulls(cards); });
}

std::vector<DataCard*> generatePulls() {
    std::vector<DataCard*> cards {};

    std::cout << "===You Pulled===";
    for(Rarity rarity : currentExpansion->packRarities()) {
        DataCard* card { generateNewCard(rarity, cards) };
        cards.push_back(card);
        gCurrentProfile.addToCollection({ card });
    }

    generateCardImages(cards);
    std::cout << std::endl;

    return cards;
}

void openPack() {
    if(!packGenerated) {
        instructText->setText("Click to Open!");
        currentPack = generatePulls();
        packGenerated = true;
        updateDisplay();
    }
}

void initCardPack() {
    cardPack = new UIImage(centeredCardPosition().x, centeredCardPosition().y + 40.0f,
        gCardBackTexture);
    
    cardPack->createClickFunction([=]() {
        if(currentExpansion == nullptr) return;
        openPack();
    });
}

void initPackPanel() {
    packPanel = new UIPanel(gWindowWidth, gWindowHeight);
    packPanel->setBackgroundColor(sf::Color::Transparent);
}

void initInstructText() {
    instructText = new UITextbox(400.0f, 50.0f, "Select an Expansion", true);
    instructText->setPositionRelativeTo(UIElement::ScreenTop, 70.0f);
    instructText->centerText();
}

void initExpansionDropdown() {
    expansionDropdown = new UIDropdown(300.0f, 40.0f, "Select Expansion",
        Expansions::gExpansionNames());
    expansionDropdown->setPositionRelativeTo(UIElement::ScreenTop, 20.0f);
    expansionDropdown->alignText();

    expansionDropdown->createClickFunction([=]() {
        if(expansionDropdown->getSelectedIndex() < 0)
            currentExpansion = nullptr;
        else
            currentExpansion = Expansions::gExpansionList[expansionDropdown->getSelectedIndex()];
    });
}

void initCollectionButton() {
    collectionButton = new UIButton(100.0f, 50.0f);
    collectionButton->setPositionRelativeTo(UIElement::ScreenTopRight, -40.0f, 40.0f);
    collectionButton->setText("Collection");
    collectionButton->centerButtonText();

    collectionButton->createClickFunction([]() {
        gSetState(CollectionView::gCollectionViewState);
    });
}

void addElements() {
    gPackSimulatorState.addUIElement(cardPack);
    gPackSimulatorState.addUIElement(packPanel);
    gPackSimulatorState.addUIElement(instructText);
    gPackSimulatorState.addUIElement(expansionDropdown);

    gPackSimulatorState.addUIElement(backButton);
    gPackSimulatorState.addUIElement(collectionButton);
}

void initPackSimState() {
    initCardPack();
    initPackPanel();
    initInstructText();
    initExpansionDropdown();

    backButton = new BackButton(10.0f, 10.0f, 50.0f, 50.0f);
    initCollectionButton();

    addElements();
}

}} 