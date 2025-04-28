#include "State.h"
#include "../Window.h"
#include "../Cards/Deck.h"
#include "../UI/CollectionLayout.h"
#include "../UI/UIButton.h"
#include "../UI/UIGridLayout.h"
#include "../UI/UIImage.h"
#include "../UI/UIScrollPanel.h"
#include "../UI/UIPanel.h"

namespace Cori {

namespace DeckBuilder {

State gDeckBuilderState {};

// UI Elements
UIScrollPanel* deckPanel;
UIScrollPanel* collectionPanel;

UIGridLayout* deckGrid;
//UIGridLayout* collectionGrid;

UIButton* backButton;

Deck currentDeck {};

float currentScaleFactor { 3.0f };
SortMethod currentSortMethod { SortMethod::NoSort };

void addImage(sf::Texture cardImage) {
    std::cout << "Adding Image" << std::endl;
    UIImage* card = new UIImage(0.0f, 0.0f, cardImage);

    card->addCaption({ 100.0f, 50.0f, "1" });
    card->getCaption().setBackgroundColor(sf::Color::Black);

    deckGrid->addElement(card);
}

void incrementImage(int imgPosition) {
    std::cout << "Incrementing Image at Position " << imgPosition << std::endl;
    UIImage* card { static_cast<UIImage*>(deckGrid->getElements()[imgPosition]) };

    card->getCaption().setText(std::format("{}", currentDeck.getCards()[imgPosition].quantity));
}

void printDeck() {
    for(Deck::DeckEntry entry : currentDeck.getCards()) {
        std::cout << entry.quantity << "x ";
        entry.card->print();
    }  
}

void addToDeck(DataCard* card, int collectionQuantity) {
    if(currentDeck.getCountOfCard(card) >= collectionQuantity) return;

    if(currentDeck.addCard(card)) {
        if(currentDeck.getCountOfCard(card) > 1)
            incrementImage(currentDeck.findCardIndex(card));
        else
            addImage(card->mTexture);
    }

    printDeck();

    deckPanel->calculateContentHeight();
}

void adjustCollectionView() {
    gCollectionLayout->changeSortMethod(currentSortMethod);
    gCollectionLayout->setSize({ collectionPanel->getWidthMinusScrollbar(), collectionPanel->getHeight() });
}

void updateCollection() {
    gCollectionLayout->updateCollection();
    collectionPanel->calculateContentHeight();
}

void initDeckBuilderState() {
    collectionPanel = new UIScrollPanel(gWindowWidth - 20.0f, gWindowHeight - 320.0f, 20.0f, 50.0f);
    //collectionPanel->setBackgroundColor(sf::Color::Blue);
    collectionPanel->getView().setViewport({ { 0.01f, 0.31f }, { 0.98f, 0.68f } });
    
    collectionPanel->addElement(gCollectionLayout);

    gDeckBuilderState.setOnSwitch(
        [=]() {
            adjustCollectionView();
            updateCollection();
        }
    );
    // Current Deck Elements

    deckPanel = new UIScrollPanel(gWindowWidth - 20.0f, gCardHeight / 3.0f + 20.0f);
    deckPanel->setBackgroundColor(sf::Color::Red);
    deckPanel->getView().setViewport({ { 0.01f, 0.01f }, { 0.98f, 0.29f } });

    deckGrid = new UIGridLayout(0.0f, 0.0f, deckPanel->getWidth() - 10, deckPanel->getHeight() - 10);
    deckGrid->setBackgroundColor(sf::Color::Green);
    deckGrid->setScale(currentScaleFactor);

    deckPanel->addElement(deckGrid);

    // Init Back Button
    backButton = new UIButton(10.0f, 10.0f, 50.0f, 50.0f);
    backButton->setText("Back");
    backButton->createClickFunction(
        []() {
            gSetState(PackSimulator::gPackSimulatorState);
        }
    );

    gDeckBuilderState.addUIElement(deckPanel);
    gDeckBuilderState.addUIElement(collectionPanel);
}

}
}