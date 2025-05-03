#include "State.h"
#include "../Window.h"
#include "../Cards/DeckList.h"
#include "../Profile/Profile.h"
#include "../UI/DecklistLayout.h"
#include "../UI/UIButton.h"
#include "../UI/UIGridLayout.h"
#include "../UI/UIScrollPanel.h"
#include <exception>

namespace Cori { namespace SavedDecks {

State gSavedDecksState {};

// UI Elements
UIScrollPanel* deckListPanel;
UIGridLayout* deckListGrid;

UIButton* backButton;

void initDeckButton(int index) {
    UIButton* button = new UIButton(deckListGrid->getWidth(), 50.0f);
    double colorFactor { (double(index) + 1.0) / (double(gCurrentProfile.decks.size()) + 1.0) };
    button->setBackgroundColor(sf::Color((0xFFFFFF * colorFactor) * 0xFF));
    
    button->setText(gCurrentProfile.decks[index].getName());

    button->createClickFunction(
        [=]() {
            DeckViewer::setViewingDeck(index);
            gSetState(DeckViewer::gDeckViewerState);
        }
    );

    deckListGrid->addElement(button);
    button->printDimensions();
    button->centerButtonText();
}


void updateDeckList() {
    deckListGrid->clearElements();
    //std::cout << gCurrentProfile.decks.size() << std::endl;

    for(std::size_t i { 0 }; i < gCurrentProfile.decks.size(); ++i) {
        initDeckButton(i);
    }
}

void initSavedDecksState() {
    deckListPanel = new UIScrollPanel(gWindowWidth, gWindowHeight - 50.0f);
    deckListPanel->getView().setViewport(
        {{ 0.0f, 50.0f / gWindowHeight }, { 1.0f, 1.0f - (50.0f / gWindowHeight) }}
    );
    //deckListPanel->setBackgroundColor(sf::Color(200, 150, 150));

    deckListGrid = new UIGridLayout(0.0f, 0.0f, deckListPanel->getWidthMinusScrollbar(), deckListPanel->getHeight());
    //deckListGrid->setBorderPadding(Direction::Bottom, 10.0f);
    deckListGrid->setInnerPadding(10.0f);
    //deckListGrid->setBackgroundColor(sf::Color(150, 200, 150));
    deckListPanel->addElement(deckListGrid);

    updateDeckList();

    backButton = new BackButton(50.0f, 50.0f);

    gSavedDecksState.addUIElement(deckListPanel);
    gSavedDecksState.addUIElement(backButton);
}

}}