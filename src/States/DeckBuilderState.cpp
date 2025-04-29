#include "State.h"
#include "../Window.h"
#include "../Cards/DeckList.h"
#include "../UI/CollectionLayout.h"
#include "../UI/UIButton.h"
#include "../UI/UIDropdown.h"
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

UIPanel* deckButtonPanel;
UIPanel* collectionButtonPanel;
//UIGridLayout* collectionGrid;

// Deck Panel Buttons
UIButton* backButton;
UIButton* finishButton;
UIButton* deckZoomIn;
UIButton* deckZoomOut;
UIDropdown* deckSortDropdown;

// Collection Panel Buttons;
UIButton* collectionZoomIn;
UIButton* collectionZoomOut;
UIDropdown* collectionSortDropdown;

DeckList currentDeck {};

// Reference Variables
float buttonPanelHeight { 20.0f };
sf::Color menuButtonColor { sf::Color(220, 220, 220) };

float deckScaleFactor { 3.0f };
// SortMethod currentDeckSort { SortMethod::NoSort };

SortMethod currentCollectionSort { SortMethod::NoSort };

void sortDeckList() {

}

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
    for(DeckList::DeckEntry entry : currentDeck.getCards()) {
        std::cout << entry.quantity << "x ";
        entry.card->print();
    }  
}

void addToDeck(QuantityCard& card) {
    if(currentDeck.getCountOfCard(card.card) >= card.quantity) return;

    if(currentDeck.addCard(card.card)) {
        if(currentDeck.getCountOfCard(card.card) > 1)
            incrementImage(currentDeck.findCardIndex(card.card));
        else
            addImage(card.card->mTexture);
    }
    sortDeckList();

    printDeck();
    deckPanel->calculateContentHeight();
}

void adjustCollectionView() {
    gCollectionLayout->changeSortMethod(currentCollectionSort);
    gCollectionLayout->setSize({ collectionPanel->getWidthMinusScrollbar(), collectionPanel->getHeight() });
}

void updateCollection() {
    gCollectionLayout->updateCollection();
    collectionPanel->calculateContentHeight();
}

void resizeGrid(UIGridLayout* layout, UIScrollPanel* panel, float scaleFactor = deckScaleFactor) {
    layout->setScale(scaleFactor);
    panel->calculateContentHeight();
}

void initDeckBuilderState() {
    collectionPanel = new UIScrollPanel(gWindowWidth - 20.0f, gWindowHeight - 320.0f, 20.0f, 50.0f);
    //collectionPanel->setBackgroundColor(sf::Color::Blue);
    collectionPanel->getView().setViewport({ { 0.01f, 0.34f }, { 0.98f, 0.65f } });
    
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
    deckPanel->getView().setViewport({ { 0.01f, 0.03f }, { 0.98f, 0.29f } });

    deckGrid = new UIGridLayout(10.0f, 8.0f, deckPanel->getWidthMinusScrollbar(), deckPanel->getHeight());
    deckGrid->setBackgroundColor(sf::Color::Green);
    deckGrid->setScale(deckScaleFactor);
    deckGrid->setInnerPadding(13.0f);
    
    deckPanel->addElement(deckGrid);

    // Init Deck Button Panel
    deckButtonPanel = new UIPanel(gWindowWidth - 20.0f, buttonPanelHeight);
    deckButtonPanel->setBackgroundColor(sf::Color::White);
    deckButtonPanel->getView().setViewport({ {0.01f, 0.01f}, {0.98f, buttonPanelHeight / gWindowHeight} });

    // Init Back Button
    backButton = new UIButton(40.0f, buttonPanelHeight);
    backButton->setText("Back");
    backButton->centerButtonText();
    backButton->setBackgroundColor(menuButtonColor);
    backButton->createClickFunction(
        []() {
            gSetState(MainMenu::gMenuState);
        }
    );

    // Init Deck Sort Dropdown
    deckSortDropdown = new UIDropdown(
        gWindowWidth * 0.99f - deckPanel->getScrollbar().getWidth() - 50.0f,
        gWindowHeight * 0.01f, 50.0f, buttonPanelHeight, "Sort",
        { "Recent", "Card #", "Name", "Type" });
    deckSortDropdown->setBackgroundColor(menuButtonColor);
    //deckSortDropdown->alignText();
    deckSortDropdown->createClickFunction(
        [=]() {
            if(deckSortDropdown->getSelectedIndex() >= 0) {
                sortDeckList();
            }
        }
    );

    deckZoomOut = new UIButton(20.0f, buttonPanelHeight);
    deckZoomOut->setPosition(deckSortDropdown->getX() - 27.0f, 0.0f);
    deckZoomOut->setText("-");
    deckZoomOut->centerButtonText();
    deckZoomOut->setBackgroundColor(menuButtonColor);
    deckZoomOut->createClickFunction(
        [=]() {
            deckScaleFactor += 1.0f;
            if(deckGrid->getInnerPadding(true) == 13.0f)
                deckGrid->setInnerPadding(8.0f);
            resizeGrid(deckGrid, deckPanel);
        }
    );

    deckZoomIn = new UIButton(20.0f, buttonPanelHeight);
    deckZoomIn->setPositionRelativeTo(*deckZoomOut, -20.0f, 0.0f);
    deckZoomIn->setText("+");
    deckZoomIn->centerButtonText();
    deckZoomIn->setBackgroundColor(menuButtonColor);
    deckZoomIn->createClickFunction(
        [=]() {
            if(deckScaleFactor > 3.0f) {
                deckScaleFactor -= 1.0f;
                if(deckScaleFactor == 3.0f && deckGrid->getInnerPadding(true) != 13.0f)
                    deckGrid->setInnerPadding(13.0f);
                    
                resizeGrid(deckGrid, deckPanel);
            }
        }
    );

    deckButtonPanel->addElement(backButton);
    deckButtonPanel->addElement(deckZoomIn);
    deckButtonPanel->addElement(deckZoomOut);
    //deckButtonPanel->addElement(deckSortDropdown);

    // Init Collection Button Panel;
    collectionButtonPanel = new UIPanel(gWindowWidth - 20.0f, buttonPanelHeight);
    collectionButtonPanel->setBackgroundColor(sf::Color::White);
    collectionButtonPanel->getView().setViewport({ 
        {0.01f, 0.32f}, {0.98f, buttonPanelHeight / gWindowHeight} 
    });

    // Init Collection Sort Dropdown
    collectionSortDropdown = new UIDropdown(
        gWindowWidth * 0.99f - collectionPanel->getScrollbar().getWidth() - 50.0f,
        gWindowHeight * 0.32f, 50.0f, buttonPanelHeight, "Sort",
        { "Recent", "Card #", "Name", "Type" }
    );
    collectionSortDropdown->setBackgroundColor(menuButtonColor);
    collectionSortDropdown->createClickFunction(
        [=]() {
            if(collectionSortDropdown->getSelectedIndex() >= 0) {
                currentCollectionSort = SortMethod(collectionSortDropdown->getSelectedIndex());
                gCollectionLayout->changeSortMethod(currentCollectionSort);
                updateCollection();
            }
        }
    );

    collectionZoomOut = new UIButton(20.0f, 20.0f);
    collectionZoomOut->setPosition(collectionSortDropdown->getX() - 27.0f, 0.0f);
    collectionZoomOut->setText("-");
    collectionZoomOut->centerButtonText();
    collectionZoomOut->setBackgroundColor(menuButtonColor);
    collectionZoomOut->createClickFunction(
        [=]() {
            resizeGrid(gCollectionLayout, collectionPanel,
                       gCollectionLayout->getScaleFactor() + 1);
        }
    );

    collectionZoomIn = new UIButton(20.0f, 20.0f);
    collectionZoomIn->setPositionRelativeTo(*collectionZoomOut, -20.0f, 0.0f);
    collectionZoomIn->setText("+");
    collectionZoomIn->centerButtonText();
    collectionZoomIn->setBackgroundColor(menuButtonColor);
    collectionZoomIn->createClickFunction(
        [=]() {
            if(gCollectionLayout->getScaleFactor() > 2.0f) {
                resizeGrid(gCollectionLayout, collectionPanel,
                           gCollectionLayout->getScaleFactor() - 1);
            }
        }
    );

    collectionButtonPanel->addElement(collectionZoomIn);
    collectionButtonPanel->addElement(collectionZoomOut);

    gDeckBuilderState.addUIElement(deckPanel);
    gDeckBuilderState.addUIElement(deckButtonPanel);
    gDeckBuilderState.addUIElement(deckSortDropdown);

    gDeckBuilderState.addUIElement(collectionPanel);
    gDeckBuilderState.addUIElement(collectionButtonPanel);
    gDeckBuilderState.addUIElement(collectionSortDropdown);
}

}
}