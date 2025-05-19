#include "State.h"
#include "../Window.h"
#include "../Profile/DeckList.h"
#include "../Profile/Profile.h"
#include "../UI/CollectionLayout.h"
#include "../UI/DecklistLayout.h"
#include "../UI/UIButton.h"
#include "../UI/UIDropdown.h"
#include "../UI/UIImage.h"
#include "../UI/UIScrollPanel.h"
#include "../UI/UITextField.h"
#include "../UI/UIPanel.h"

namespace Cori { namespace DeckBuilder {

State gDeckBuilderState {};

// UI Elements

UIScrollPanel* deckPanel;
UIScrollPanel* collectionPanel;

UIPanel* deckButtonPanel;
UIPanel* collectionButtonPanel;

UITextField* deckNameField;

// Deck Panel Buttons

UIButton* backButton;
UIButton* finishButton;
UIButton* deckZoomIn;
UIButton* deckZoomOut;
UIDropdown* deckSortDropdown;

// Collection Panel Buttons

UIButton* collectionZoomIn;
UIButton* collectionZoomOut;
UIDropdown* collectionSortDropdown;

// Reference Variables

float buttonPanelHeight { 20.0f };
sf::Color menuButtonColor { sf::Color(220, 220, 220) };

bool editingExistingDeck { false };
int editingDeckIndex {};
DeckList editingDeck {};

SortMethod currentDeckSort { SortMethod::TypeSort };
SortMethod currentCollectionSort { SortMethod::NoSort };

float padding(UIElement* element) {
    return { (element->getOriginY() == gDecklistLayout->getBorderPadding(Direction::Top))
        ? gDecklistLayout->getBorderPadding(Direction::Top)
        : gDecklistLayout->getInnerPadding(true) };
}

void offsetScroll(QuantityCard& card) {
    UIElement* element { gDecklistLayout->getElements()[
        gDecklistLayout->findCardIndex(card)
    ]};
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
    if(!editingExistingDeck)
        gDecklistLayout->reset();
}

void adjustDecklistView() {
    gDecklistLayout->setScale(3.0f);
    gDecklistLayout->changeSortMethod(currentDeckSort);
    gDecklistLayout->setSize({ deckPanel->getWidthMinusScrollbar(), deckPanel->getHeight() });
}

void updateCollection() {
    gCollectionLayout->updateCollection();
    collectionPanel->calculateContentHeight();
}

void adjustCollectionView() {
    gCollectionLayout->changeSortMethod(currentCollectionSort);
    gCollectionLayout->setSize({ collectionPanel->getWidthMinusScrollbar(), collectionPanel->getHeight() });
    collectionPanel->calculateContentHeight();
}

void initCollectionPanel() {
    collectionPanel = new UIScrollPanel(gWindowWidth * 0.98f, gWindowHeight * 0.65);
    collectionPanel->setViewport(0.01f, 0.34f, 0.98f, 0.65f);

    collectionPanel->addElement(gCollectionLayout);
}

void initDeckPanel() {
    deckPanel = new UIScrollPanel(gWindowWidth - 20.0f, gWindowHeight * 0.29f);
    deckPanel->setViewport(0.01f, 0.03f, 0.98f, 0.29f);

    deckPanel->addElement(gDecklistLayout);
}

void initBackButton() {
    backButton = new BackButton(40.0f, buttonPanelHeight);
    backButton->setBackgroundColor(menuButtonColor);
    backButton->createClickFunction([=]() {
        if(editingExistingDeck) {
            gDecklistLayout->setDeck(editingDeck);
            editingExistingDeck = false;
        }
        gOnBackClick();
    });
}

void createFinishButtonClick() {
    finishButton->createClickFunction([=]() {
        gDecklistLayout->getCurrentDeck().setName(deckNameField->flushTextInput());
        if(editingExistingDeck) {
            gCurrentProfile.decks[editingDeckIndex] = gDecklistLayout->getCurrentDeck();
            editingExistingDeck = false;
        } else
            gCurrentProfile.decks.push_back(gDecklistLayout->getCurrentDeck());
        SavedDecks::updateDeckList();
        gSetState(
            editingExistingDeck ? DeckViewer::gDeckViewerState
            : SavedDecks::gSavedDecksState, false
        );
    });
}

void initFinishButton() {
    finishButton = new UIButton(80.0f, buttonPanelHeight);
    finishButton->setBackgroundColor(menuButtonColor);
    finishButton->setPositionRelativeTo(UIElement::ScreenTop);
    
    finishButton->setText("Save");
    finishButton->centerButtonText();
    createFinishButtonClick();
}

void initDeckSortDropdown() {
    deckSortDropdown = new UIDropdown(
        gWindowWidth * 0.99f - deckPanel->getScrollbar().getWidth() - 50.0f,
        gWindowHeight * 0.01f, 50.0f, buttonPanelHeight, "Sort", gSortMethods);
    deckSortDropdown->setBackgroundColor(menuButtonColor);

    deckSortDropdown->createClickFunction([=]() {
        if(deckSortDropdown->getSelectedIndex() >= 0) {
            currentDeckSort = SortMethod(deckSortDropdown->getSelectedIndex());
            gDecklistLayout->changeSortMethod(currentDeckSort);
        }
    });
}

void resizeGrid(UIGridLayout* layout, UIScrollPanel* panel, float scaleFactor) {
    layout->setScale(scaleFactor);
    panel->calculateContentHeight();
}

void initDeckZoomOut() {
    deckZoomOut = new UIButton(20.0f, buttonPanelHeight);
    deckZoomOut->setPosition(deckSortDropdown->getX() - 27.0f, 0.0f);
    deckZoomOut->setText("-");
    deckZoomOut->centerButtonText();
    deckZoomOut->setBackgroundColor(menuButtonColor);

    deckZoomOut->createClickFunction([=]() {
        resizeGrid(gDecklistLayout, deckPanel,
            gDecklistLayout->getScaleFactor() + 1);
        if(gDecklistLayout->getInnerPadding(true) == 12.0f)
            gDecklistLayout->setInnerPadding(8.0f);
    });
}

void initDeckZoomIn() {
    deckZoomIn = new UIButton(20.0f, buttonPanelHeight);
    deckZoomIn->setPositionRelativeTo(*deckZoomOut, -20.0f, 0.0f);
    deckZoomIn->setText("+");
    deckZoomIn->centerButtonText();
    deckZoomIn->setBackgroundColor(menuButtonColor);
    
    deckZoomIn->createClickFunction([=]() {
        if(gDecklistLayout->getScaleFactor() > 3.0f) {
            resizeGrid(gDecklistLayout, deckPanel,
                gDecklistLayout->getScaleFactor() - 1);
            if(gDecklistLayout->getScaleFactor() == 3.0f &&
               gDecklistLayout->getInnerPadding(true) != 12.0f)
                gDecklistLayout->setInnerPadding(12.0f);
        }
    });
}

void initDeckButtons() {
    initBackButton();
    initFinishButton();
    initDeckSortDropdown();
    initDeckZoomOut();
    initDeckZoomIn();

    deckButtonPanel->addElement(backButton);
    deckButtonPanel->addElement(finishButton);
    deckButtonPanel->addElement(deckZoomIn);
    deckButtonPanel->addElement(deckZoomOut);
}

void initDeckButtonPanel() {
    deckButtonPanel = new UIPanel(gWindowWidth * 0.98f, buttonPanelHeight);
    deckButtonPanel->setBackgroundColor(sf::Color::White);
    deckButtonPanel->setViewport(0.01, 0.01, 0.98, buttonPanelHeight);

    initDeckButtons();
}

void initCollectionSortDropdown() {
    collectionSortDropdown = new UIDropdown(
        gWindowWidth * 0.99f - collectionPanel->getScrollbar().getWidth() - 50.0f,
        gWindowHeight * 0.32f, 50.0f, buttonPanelHeight, "Sort", gSortMethods);
    collectionSortDropdown->setBackgroundColor(menuButtonColor);
    
    collectionSortDropdown->createClickFunction([=]() {
        if(collectionSortDropdown->getSelectedIndex() >= 0) {
            currentCollectionSort = SortMethod(collectionSortDropdown->getSelectedIndex());
            gCollectionLayout->changeSortMethod(currentCollectionSort);
            updateCollection();
        }
    });    
}

void initCollectionZoomOut() {
    collectionZoomOut = new UIButton(20.0f, 20.0f);
    collectionZoomOut->setPosition(collectionSortDropdown->getX() - 27.0f, 0.0f);
    collectionZoomOut->setText("-");
    collectionZoomOut->centerButtonText();
    collectionZoomOut->setBackgroundColor(menuButtonColor);
    
    collectionZoomOut->createClickFunction([=]() {
        resizeGrid(gCollectionLayout, collectionPanel,
                   gCollectionLayout->getScaleFactor() + 1);
    });
}

void initCollectionZoomIn() {
    collectionZoomIn = new UIButton(20.0f, 20.0f);
    collectionZoomIn->setPositionRelativeTo(*collectionZoomOut, -20.0f, 0.0f);
    collectionZoomIn->setText("+");
    collectionZoomIn->centerButtonText();
    collectionZoomIn->setBackgroundColor(menuButtonColor);

    collectionZoomIn->createClickFunction([=]() {
        if(gCollectionLayout->getScaleFactor() > 2.0f) {
            resizeGrid(gCollectionLayout, collectionPanel,
                       gCollectionLayout->getScaleFactor() - 1);
        }
    });
}

void initCollectionButtons() {
    initCollectionSortDropdown();
    initCollectionZoomOut();
    initCollectionZoomIn();

    collectionButtonPanel->addElement(collectionZoomIn);
    collectionButtonPanel->addElement(collectionZoomOut);
}

void initCollectionButtonPanel() {
    collectionButtonPanel = new UIPanel(gWindowWidth * 0.98f, buttonPanelHeight);
    collectionButtonPanel->setBackgroundColor(sf::Color::White);
    collectionButtonPanel->setViewport(0.01f, 0.32f, 0.98f, buttonPanelHeight);

    initCollectionButtons();
}

void addElements() {
    gDeckBuilderState.addUIElement(deckNameField);
    
    gDeckBuilderState.addUIElement(deckPanel);
    gDeckBuilderState.addUIElement(deckButtonPanel);
    gDeckBuilderState.addUIElement(deckSortDropdown);
    
    gDeckBuilderState.addUIElement(collectionPanel);
    gDeckBuilderState.addUIElement(collectionButtonPanel);
    gDeckBuilderState.addUIElement(collectionSortDropdown);
}

void initDeckBuilderState() {
    gDeckBuilderState.setOnSwitch([]() {
        resetDeckBuilder();
        adjustDecklistView();

        updateCollection();
        adjustCollectionView();
    });
    gDeckBuilderState.setOffSwitch([=]() {
        deckPanel->resetScrollbar();
        collectionPanel->resetScrollbar();
    });

    initDecklistLayout();
    initCollectionPanel();

    initDeckPanel();
    deckNameField = new UITextField(gWindowWidth / 2 - 100.0f, 0.0f, 200.0f, 10.0f);

    initDeckButtonPanel();
    initCollectionButtonPanel();

    addElements();
}


}}