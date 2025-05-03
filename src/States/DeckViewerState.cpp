#include "State.h"
#include "../Cards/DeckList.h"
#include "../Profile/Profile.h"
#include "../UI/DecklistLayout.h"
#include "../UI/UIButton.h"
#include "../UI/UIPanel.h"
#include "../UI/UIScrollPanel.h"

namespace Cori { namespace DeckViewer {

State gDeckViewerState {};

// UI Elements
UIScrollPanel* deckPanel;
UIPanel* deckButtonPanel;

// Deck Panel Buttons
UIButton* backButton;
UIButton* editButton;
UIButton* zoomIn;
UIButton* zoomOut;
UIButton* sortDropdown;

float buttonPanelHeight { 40.0f };
sf::Color menuButtonColor { sf::Color(220, 180, 180) };

int currentDeckIndex {};
SortMethod currentSort { SortMethod::TypeSort };

void setViewingDeck(int deckIndex) {
    currentDeckIndex = deckIndex;
    gDecklistLayout->setDeck(gCurrentProfile.decks[deckIndex]);
}

void adjustDecklistView() {
    gDecklistLayout->setScale(2.0f);
    gDecklistLayout->setSize({ deckPanel->getWidthMinusScrollbar(), deckPanel->getHeight() });
    deckPanel->calculateContentHeight();
    gDecklistLayout->changeSortMethod(currentSort);
}

void initDeckViewerState() {
    deckPanel = new UIScrollPanel(gWindowWidth - 20.0f, gWindowHeight - 60.0f);
    deckPanel->getView().setViewport({
        { 10.0f / gWindowWidth, 50.0f / gWindowHeight },
        { deckPanel->getWidth() / gWindowWidth, deckPanel->getHeight() / gWindowHeight }
    });
    deckPanel->addElement(gDecklistLayout);

    gDeckViewerState.setOnSwitch(
        [=]() {
            adjustDecklistView();
        }
    );

    deckButtonPanel = new UIPanel(gWindowWidth - 20.0f, buttonPanelHeight);
    deckButtonPanel->setBackgroundColor(sf::Color::White);
    deckButtonPanel->getView().setViewport({
        { 10.0f / gWindowWidth, 10.0f / gWindowHeight },
        { (gWindowWidth - 20.0f) / gWindowWidth, buttonPanelHeight / gWindowHeight }
    });

    backButton = new BackButton(60.0f, buttonPanelHeight);
    backButton->setBackgroundColor(menuButtonColor);

    editButton = new UIButton(100.0f, buttonPanelHeight);
    editButton->setBackgroundColor(menuButtonColor);
    editButton->setPositionRelativeTo(UIElement::ScreenTop);
    editButton->setText("Edit");
    editButton->centerButtonText();
    editButton->createClickFunction(
        [=]() {
            DeckBuilder::editDeck(currentDeckIndex);
            gSetState(DeckBuilder::gDeckBuilderState);
        }
    );

    deckButtonPanel->addElement(backButton);
    deckButtonPanel->addElement(editButton);

    gDeckViewerState.addUIElement(deckPanel);
    gDeckViewerState.addUIElement(deckButtonPanel);
}

void destroyDeckViewState() {
    delete gDecklistLayout;
}

}}