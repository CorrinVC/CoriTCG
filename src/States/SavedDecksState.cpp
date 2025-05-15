#include "State.h"
#include "../Window.h"
#include "../Profile/DeckList.h"
#include "../Profile/Profile.h"
#include "../UI/DecklistLayout.h"
#include "../UI/UIButton.h"
#include "../UI/UIGridLayout.h"
#include "../UI/UIScrollPanel.h"

namespace Cori { namespace SavedDecks {

State gSavedDecksState {};

// UI Elements

UIScrollPanel* deckListPanel;
UIGridLayout* deckListGrid;

UIButton* backButton;
UIButton* addDeckButton; // temp

void initDeckListPanel() {
    deckListPanel = new UIScrollPanel(gWindowWidth, gWindowHeight - 50.0f);
    deckListPanel->setViewport(0.0f, 50.0f, 1.0f, gWindowHeight - 50.0f);
}

void initDeckListGrid() {
    deckListGrid = new UIGridLayout(0.0f, 0.0f, deckListPanel->getWidthMinusScrollbar());
    deckListGrid->setInnerPadding(10.0f);

    deckListPanel->addElement(deckListGrid);
}

void initDeckButton(int index) {
    UIButton* button = new UIButton(deckListGrid->getWidth(), 50.0f);
    //button->setBackgroundColor(sf::Color::);
    button->setText(gCurrentProfile.decks[index].getName());

    button->createClickFunction([=]() {
        DeckViewer::setViewingDeck(index);
        gSetState(DeckViewer::gDeckViewerState);
    });

    deckListGrid->addElement(button);
    button->centerButtonText();
}

void updateDeckList() {
    deckListGrid->clearElements();
    for(std::size_t i { 0 }; i < gCurrentProfile.decks.size(); ++i)
        initDeckButton(i);
    deckListPanel->calculateContentHeight();

    if(deckListGrid->getWidth() != deckListPanel->getWidthMinusScrollbar())
        deckListGrid->setSize({ deckListPanel->getWidthMinusScrollbar(), deckListGrid->getHeight() });
}

// temp
void initAddDeckButton() {
    addDeckButton = new UIButton(50.0f, 50.0f);
    addDeckButton->setPositionRelativeTo(*backButton, 60.0f, 0.0f);
    addDeckButton->setText("+");
    addDeckButton->centerButtonText();
    
    addDeckButton->createClickFunction([=]() {
        DeckList deck {};
        deck.setName(std::format("Deck {}", gCurrentProfile.decks.size() + 1));
        gCurrentProfile.decks.push_back(deck);
        updateDeckList();
    });
}

void addElements() {
    gSavedDecksState.addUIElement(deckListPanel);
    gSavedDecksState.addUIElement(backButton);
    gSavedDecksState.addUIElement(addDeckButton);
}

void initSavedDecksState() {
    gSavedDecksState.setOffSwitch([=]() {
        deckListPanel->resetScrollbar();
    });

    initDeckListPanel();
    initDeckListGrid();

    updateDeckList();

    backButton = new BackButton(50.0f, 50.0f);
    initAddDeckButton(); // temp

    addElements();
}

}}