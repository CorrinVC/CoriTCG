#include "State.h"
#include "../Profile/DeckList.h"
#include "../Profile/Profile.h"
#include "../UI/DecklistLayout.h"
#include "../UI/UIButton.h"
#include "../UI/UIDropdown.h"
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
UIDropdown* sortDropdown;

// Reference Variables

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

void initDeckPanel() {
    deckPanel = new UIScrollPanel(gWindowWidth - 20.0f, gWindowHeight - 60.0f);
    deckPanel->setViewport(10.0f, 50.0f, deckPanel->getWidth(), deckPanel->getHeight());
    deckPanel->addElement(gDecklistLayout);
}

void initEditButton() {
    editButton = new UIButton(100.0f, buttonPanelHeight);
    editButton->setBackgroundColor(menuButtonColor);
    editButton->setPositionRelativeTo(UIElement::ScreenTop);
    editButton->setText("Edit");
    editButton->centerButtonText();

    editButton->createClickFunction([=]() {
        DeckBuilder::editDeck(currentDeckIndex);
        gSetState(DeckBuilder::gDeckBuilderState);
    });
}

void initDeckPanelButtons() {
    backButton = new BackButton(60.0f, buttonPanelHeight);
    backButton->setBackgroundColor(menuButtonColor);

    initEditButton();

    deckButtonPanel->addElement(backButton);
    deckButtonPanel->addElement(editButton);
}

void initDeckButtonPanel() {
    deckButtonPanel = new UIPanel(gWindowWidth - 20.0f, buttonPanelHeight);
    deckButtonPanel->setBackgroundColor(sf::Color::White);
    deckButtonPanel->setViewport(10.0f, 10.0f, deckButtonPanel->getWidth(), buttonPanelHeight);

    initDeckPanelButtons();
}

void addElements() {
    gDeckViewerState.addUIElement(deckPanel);
    gDeckViewerState.addUIElement(deckButtonPanel);
}

void initDeckViewerState() {
    gDeckViewerState.setOnSwitch([=]() {
        adjustDecklistView();
    });
    gDeckViewerState.setOffSwitch([=]() {
        deckPanel->resetScrollbar();
    });

    initDeckPanel();
    initDeckButtonPanel();

    addElements();
}

}}