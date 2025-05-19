#include "State.h"
#include "../Cards/Expansions/Expansions.h"
#include "../Profile/Collection.h"
#include "../Profile/Profile.h"
#include "../UI/CollectionLayout.h"
#include "../UI/UIButton.h"
#include "../UI/UIDropdown.h"
#include "../UI/UIImage.h"
#include "../UI/UIScrollPanel.h"
#include <algorithm>

namespace Cori { namespace CollectionView {

State gCollectionViewState {};

// UI Elements

UIScrollPanel* collectionPanel;

UIButton* backButton;
UIButton* decksButton;
UIDropdown* sortDropdown;

SortMethod currentSortMethod { SortMethod::NoSort };

void adjustCollectionView() {
    gCollectionLayout->changeSortMethod(currentSortMethod);
    gCollectionLayout->setSize({ collectionPanel->getWidthMinusScrollbar(), collectionPanel->getHeight() });
    collectionPanel->calculateContentHeight();
}

void updateCollection() {
    gCollectionLayout->updateCollection();
    collectionPanel->calculateContentHeight();
}

void initCollectionPanel() {
    collectionPanel = new UIScrollPanel(gWindowWidth, gWindowHeight * 0.9);
    collectionPanel->setViewport(0.0f, 0.07f, 1.0f, 0.93f);
    
    collectionPanel->addElement(gCollectionLayout);
    updateCollection();
}

void initDecksButton() {
    decksButton = new UIButton(60.0f, 50.0f);
    decksButton->setPositionRelativeTo(*backButton, 70.0f, 0.0f);
    decksButton->setText("Decks");
    decksButton->centerButtonText();
    decksButton->createClickFunction([]() {
        gSetState(SavedDecks::gSavedDecksState);
    });
}

void initSortDropdown() {
    sortDropdown = new UIDropdown(gWindowWidth - 110.0f, 10.0f, 100.0f, 50.0f, "Sort", gSortMethods);

    sortDropdown->createClickFunction([=]() {
        if(sortDropdown->getSelectedText() != gDefaultString) {
            currentSortMethod = SortMethod(sortDropdown->getSelectedIndex());
            gCollectionLayout->changeSortMethod(currentSortMethod);
            updateCollection();
        }
    });
}

void addElements() {
    gCollectionViewState.addUIElement(collectionPanel);
    gCollectionViewState.addUIElement(backButton);
    gCollectionViewState.addUIElement(decksButton);
    gCollectionViewState.addUIElement(sortDropdown);
}

void initCollectionViewState() {
    gCollectionViewState.setOnSwitch([]() {
            updateCollection();
            adjustCollectionView();
    }); 
    gCollectionViewState.setOffSwitch([]() {
            collectionPanel->resetScrollbar();
    });

    initCollectionLayout();
    initCollectionPanel();

    backButton = new BackButton(10.0f, 10.0f, 60.0f, 50.0f);
    initDecksButton();
    initSortDropdown();

    addElements();
}

}}