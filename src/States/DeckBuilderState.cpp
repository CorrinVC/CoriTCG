#include "State.h"
#include "../Window.h"
#include "../Cards/DeckList.h"
#include "../Profile/Profile.h"
#include "../UI/CollectionLayout.h"
#include "../UI/DecklistLayout.h"
#include "../UI/UIButton.h"
#include "../UI/UIDropdown.h"
#include "../UI/UIImage.h"
#include "../UI/UIScrollPanel.h"
#include "../UI/UITextField.h"
#include "../UI/UIPanel.h"

namespace Cori {

namespace DeckBuilder {

State gDeckBuilderState {};

// UI Elements
UIScrollPanel* deckPanel;
UIScrollPanel* collectionPanel;

UIPanel* deckButtonPanel;
UIPanel* collectionButtonPanel;
//UIGridLayout* collectionGrid;

UITextField* deckNameField;

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

//DeckList currentDeck {};

// Reference Variables
float buttonPanelHeight { 20.0f };
sf::Color menuButtonColor { sf::Color(220, 220, 220) };

//float deckScaleFactor { 3.0f };
// SortMethod currentDeckSort { SortMethod::NoSort };

bool editingExistingDeck { false };
int editingDeckIndex {};
DeckList editingDeck {};

SortMethod currentDeckSort { SortMethod::TypeSort };
SortMethod currentCollectionSort { SortMethod::NoSort };

/*void addImage(sf::Texture cardImage) {
    UIImage* card = new UIImage(0.0f, 0.0f, cardImage);

    card->addCaption({ 100.0f, 50.0f, "1" });
    card->getCaption().setBackgroundColor(sf::Color::Black);

    gDeckl->addElement(card);
}

void incrementImage(int imgPosition) {
    UIImage* card { static_cast<UIImage*>(deckGrid->getElements()[imgPosition]) };

    card->getCaption().setText(std::format("{}", currentDeck.getCards()[imgPosition].quantity));
}

void changeImage(QuantityCard card, int imgPosition) {
    UIImage* img { static_cast<UIImage*>(deckGrid->getElements()[imgPosition]) };

    img->changeTexture(card.card->mTexture);
    img->setScale(1.0f / deckScaleFactor);
    img->getCaption().setText(std::format("{}", card.quantity));
}

void printDeck() {
    for(QuantityCard card : currentDeck.getCards()) {
        std::cout << card.quantity << "x ";
        card.print();
    }  
}

void sortDeckList() {
    int cardIndex { 0 };
    for(QuantityCard card : currentDeck.getSortedList(currentDeckSort)) {
        changeImage(card, cardIndex);
        ++cardIndex;
    }
}*/

float padding(UIElement* element) {
    return { (element->getOriginY() == gDecklistLayout->getBorderPadding(Direction::Top))
        ? gDecklistLayout->getBorderPadding(Direction::Top)
        : gDecklistLayout->getInnerPadding(true) };
}

void offsetScroll(QuantityCard& card) {
    UIElement* element { gDecklistLayout->getElements()[
        gDecklistLayout->findCardIndex(card)
    ] };
    std::cout << element->getOriginY() << " - " << padding(element) << "= offset " 
                << element->getOriginY() - padding(element) << std::endl;
    deckPanel->setScrollOffset(element->getOriginY() - padding(element));
}

void addToDeck(QuantityCard& card) {
    gDecklistLayout->addToDeck(card);
    deckPanel->calculateContentHeight();

    offsetScroll(card);    
}

void editDeck(int deckIndex) {
    editingExistingDeck = true;
    editingDeckIndex = deckIndex;
    editingDeck = gCurrentProfile.decks[deckIndex];
    gDecklistLayout->setDeck(editingDeck);
}

void resetDeckBuilder() {
    deckPanel->resetScrollbar();
    collectionPanel->resetScrollbar();
    gDecklistLayout->reset();
}

void adjustDecklistView() {
    gDecklistLayout->setScale(3.0f);
    gDecklistLayout->changeSortMethod(currentDeckSort);
    gDecklistLayout->setSize({ deckPanel->getWidthMinusScrollbar(), deckPanel->getHeight() });
    deckPanel->calculateContentHeight();
}

void adjustCollectionView() {
    gCollectionLayout->changeSortMethod(currentCollectionSort);
    gCollectionLayout->setSize({ collectionPanel->getWidthMinusScrollbar(), collectionPanel->getHeight() });
    collectionPanel->calculateContentHeight();
}

void updateCollection() {
    gCollectionLayout->updateCollection();
    collectionPanel->calculateContentHeight();
}

void resizeGrid(UIGridLayout* layout, UIScrollPanel* panel, float scaleFactor) {
    layout->setScale(scaleFactor);
    panel->calculateContentHeight();
}

void initDeckBuilderState() {
    initDecklistLayout();

    collectionPanel = new UIScrollPanel(gWindowWidth - 20.0f, gWindowHeight - 320.0f, 20.0f, 50.0f);
    //collectionPanel->setBackgroundColor(sf::Color::Blue);
    collectionPanel->getView().setViewport({ { 0.01f, 0.34f }, { 0.98f, 0.65f } });
    
    collectionPanel->addElement(gCollectionLayout);

    gDeckBuilderState.setOnSwitch(
        [=]() {
            if(!editingExistingDeck) resetDeckBuilder();
            adjustDecklistView();
            adjustCollectionView();
            updateCollection();
        }
    );
    // Current Deck Elements

    deckPanel = new UIScrollPanel(gWindowWidth - 20.0f, gCardHeight / 3.0f + 20.0f);
    deckPanel->setBackgroundColor(sf::Color::Red);
    deckPanel->getView().setViewport({ { 0.01f, 0.03f }, { 0.98f, 0.29f } });

    /*deckGrid = new DecklistLayout(deckPanel->getWidthMinusScrollbar(), deckPanel->getHeight());
    deckGrid->setBackgroundColor(sf::Color::Green);
    deckGrid->setScale(deckScaleFactor);
    deckGrid->setInnerPadding(13.0f);*/
    
    deckPanel->addElement(gDecklistLayout);

    deckNameField = new UITextField(gWindowWidth / 2 - 100.0f, 0.0f, 200.0f, 10.0f);

    // Init Deck Button Panel
    deckButtonPanel = new UIPanel(gWindowWidth - 20.0f, buttonPanelHeight);
    deckButtonPanel->setBackgroundColor(sf::Color::White);
    deckButtonPanel->getView().setViewport({ {0.01f, 0.01f}, {0.98f, buttonPanelHeight / gWindowHeight} });

    // Init Back Button
    backButton = new BackButton(40.0f, buttonPanelHeight);
    backButton->setBackgroundColor(menuButtonColor);
    backButton->createClickFunction(
        [=]() {
            if(editingExistingDeck)
                gDecklistLayout->setDeck(editingDeck);
            gOnBackClick();
        }
    );

    finishButton = new UIButton(80.0f, buttonPanelHeight);
    finishButton->setBackgroundColor(menuButtonColor);
    finishButton->setPositionRelativeTo(UIElement::ScreenTop);
    finishButton->setText("Save");
    finishButton->centerButtonText();
    finishButton->createClickFunction(
        [=]() {
            gDecklistLayout->getCurrentDeck().setName(deckNameField->flushTextInput());
            if(editingExistingDeck)
                gCurrentProfile.decks[editingDeckIndex] = gDecklistLayout->getCurrentDeck();
            else
                gCurrentProfile.decks.push_back(gDecklistLayout->getCurrentDeck());
            SavedDecks::updateDeckList();
            gSetState(
                editingExistingDeck ? DeckViewer::gDeckViewerState
                : SavedDecks::gSavedDecksState, false
            );
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
                currentDeckSort = SortMethod(deckSortDropdown->getSelectedIndex());
                gDecklistLayout->changeSortMethod(currentDeckSort);
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
            resizeGrid(gDecklistLayout, deckPanel,
                gDecklistLayout->getScaleFactor() + 1);
            
            if(gDecklistLayout->getInnerPadding(true) == 12.0f)
                gDecklistLayout->setInnerPadding(8.0f);
        }
    );

    deckZoomIn = new UIButton(20.0f, buttonPanelHeight);
    deckZoomIn->setPositionRelativeTo(*deckZoomOut, -20.0f, 0.0f);
    deckZoomIn->setText("+");
    deckZoomIn->centerButtonText();
    deckZoomIn->setBackgroundColor(menuButtonColor);
    deckZoomIn->createClickFunction(
        [=]() {
            if(gDecklistLayout->getScaleFactor() > 3.0f) {
                resizeGrid(gDecklistLayout, deckPanel,
                    gDecklistLayout->getScaleFactor() - 1);

                if(gDecklistLayout->getScaleFactor() == 3.0f && 
                   gDecklistLayout->getInnerPadding(true) != 12.0f)
                    gDecklistLayout->setInnerPadding(12.0f);
            }
        }
    );

    deckButtonPanel->addElement(backButton);
    deckButtonPanel->addElement(finishButton);
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

    gDeckBuilderState.addUIElement(deckNameField);

    gDeckBuilderState.addUIElement(deckPanel);
    gDeckBuilderState.addUIElement(deckButtonPanel);
    gDeckBuilderState.addUIElement(deckSortDropdown);

    gDeckBuilderState.addUIElement(collectionPanel);
    gDeckBuilderState.addUIElement(collectionButtonPanel);
    gDeckBuilderState.addUIElement(collectionSortDropdown);
}

}
}