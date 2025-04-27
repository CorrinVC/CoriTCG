#include "State.h"
#include "../Window.h"
#include "../UI/UIGridLayout.h"
#include "../UI/UIScrollPanel.h"
#include "../UI/UIPanel.h"

namespace Cori {

namespace DeckBuilder {

State gDeckBuilderState {};

// UI Elements
UIPanel* deckPanel;
UIScrollPanel* collectionPanel;

UIGridLayout* deckGrid;
UIGridLayout* collectionGrid;

float currentScaleFactor { 3.0f };

void initDeckBuilderState() {
    gDeckBuilderState.setOnSwitch(
        [=]() {

        }
    );
    // Current Deck Elements

    deckPanel = new UIPanel(gWindowWidth - 20.0f, gCardHeight / 3.0f + 20.0f);
    deckPanel->setBackgroundColor(sf::Color::Red);
    deckPanel->getView().setViewport({ { 0.01f, 0.01f }, { 0.98f, 0.29f } });

    deckGrid = new UIGridLayout(0.0f, 0.0f, deckPanel->getWidth() - 10, deckPanel->getHeight() - 10);
    deckGrid->setBackgroundColor(sf::Color::Green);
    deckGrid->setScale(currentScaleFactor);

    deckPanel->addElement(deckGrid);

    // Collection Elements

    collectionPanel = new UIScrollPanel(gWindowWidth - 20.0f, gWindowHeight - 320.0f, 20.0f, 50.0f);
    collectionPanel->setBackgroundColor(sf::Color::Blue);
    collectionPanel->getView().setViewport({ { 0.01f, 0.31f }, { 0.98f, 0.68f } });

    collectionGrid = new UIGridLayout(0.0f, 0.0f, collectionPanel->getWidth() - 10, collectionPanel->getHeight() - 10);
    collectionGrid->setBackgroundColor(sf::Color::Yellow);
    collectionGrid->setScale(currentScaleFactor);

    collectionPanel->addElement(collectionGrid);


    gDeckBuilderState.addUIElement(deckPanel);
    gDeckBuilderState.addUIElement(collectionPanel);
}

}
}