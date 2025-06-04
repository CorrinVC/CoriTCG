#include "State.h"
#include "../Cards/Expansions/Expansions.h"
#include "../Profile/Collection.h"
#include "../Profile/Profile.h"
#include "../UI/CollectionLayout.h"
#include "../UI/UIButton.h"
#include "../UI/UICheckbox.h"
#include "../UI/UIDropdown.h"
#include "../UI/UIImage.h"
#include "../UI/UIPopup.h"
#include "../UI/UIScrollPanel.h"
#include <algorithm>

namespace Cori { namespace CollectionView {

State gCollectionViewState {};

// UI Elements

UIScrollPanel* collectionPanel;

UIButton* backButton;
UIButton* decksButton;

UIButton* filterButton;
UIPopup* filterPopup;

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

void initFilterCheckboxes() {
    UICheckbox* box1 = new UICheckbox(10.0f, 60.0f, 150.0f, 50.0f, "Penis");
    UICheckbox* box2 = new UICheckbox(10.0f, 120.0f, 150.0f, 50.0f, "Vajayjay");
    UICheckbox* box3 = new UICheckbox(10.0f, 180.0f, 150.0f, 50.0f, "A Secret Third Thing");

    filterPopup->addElement(box1);
    filterPopup->addElement(box2);
    filterPopup->addElement(box3);
}

void initFilterPopup() {
    filterPopup = new UIPopup(500.0f, 300.0f, "Filter Options");
    //filterPopup->setPositionRelativeTo(UIElement::ScreenCenter);
    filterPopup->setBackgroundColor(sf::Color::Magenta);
    filterPopup->alignConfirmButton(
        filterPopup->getWidth() / 2.0f - filterPopup->getConfirmButton().getWidth() / 2.0f, 
        filterPopup->getHeight() - filterPopup->getConfirmButton().getHeight() - 10.0f);

    filterPopup->centerTitle();
    filterPopup->alignTitle(filterPopup->getWidth() / 2.0f - filterPopup->getTitleBox().getWidth() / 2.0f, 10.0f);
    
    initFilterCheckboxes();
    filterPopup->hide();
}

void initFilterButton() {
    filterButton = new UIButton(80.0f, 50.0f);
    filterButton->setPositionRelativeTo(*sortDropdown, -90.0f, 0.0f);
    filterButton->setText("Filter");
    filterButton->centerButtonText();

    filterButton->createClickFunction([]() {
        filterPopup->show();
    });
}

void addElements() {
    gCollectionViewState.addUIElement(collectionPanel);
    gCollectionViewState.addUIElement(backButton);
    gCollectionViewState.addUIElement(decksButton);
    gCollectionViewState.addUIElement(filterButton);
    gCollectionViewState.addUIElement(sortDropdown);
    gCollectionViewState.addUIElement(filterPopup);
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

    initFilterPopup();
    initFilterButton();

    addElements();
}

}}