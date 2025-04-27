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
CollectionLayout* layout;
UIScrollPanel* panel;

UIButton* backButton;
UIDropdown* sortDropdown;

SortMethod currentSortMethod {};

/*void printImageDetails() {
    int i {0};
    for(UIElement* e : layout->getElements()) {
        UIImage* image {static_cast<UIImage*>(e)};
        std::cout << "Image #" << i << ":\nCaption Text: "
            << image->getCaption().getText() << "\n============" << std::endl;
        ++i;
    }
    std::cout << "ENDING PRINT" << std::endl;
}*/

/*void generateImage(Collection::CollectionEntry& entry) {
    UIImage* image = new UIImage(0.0f, 0.0f, entry.getCard()->mTexture);

    // Switch to Card Viewer on Img Click
    image->createClickFunction(
        [=]() {
            SetViewer::setSelectedCard(entry.cardNumber, entry.expansion);
            gSetState(SetViewer::gSetViewerState);
        }
    );

    // Set Image Caption to Quantity of Cards in Collection
    image->addCaption({ 100.0f, 50.0f, std::format("{}", entry.quantity) });
    image->getCaption().setBackgroundColor(sf::Color::Black);

    layout->addElement(image);
}

void changeImage(Collection::CollectionEntry& entry, int entryIndex) {
    UIImage* image { static_cast<UIImage*>( layout->getElements()[entryIndex] ) };

    image->changeTexture(entry.getCard()->mTexture);
    image->getCaption().setText(std::format("{}", entry.quantity));
}

void updateEntry(Collection::CollectionEntry& entry, int entryIndex, int imagesInLayout) {
    if(entryIndex >= imagesInLayout)
        generateImage(entry);
    else
        changeImage(entry, entryIndex);
}

void updateCollection() {
    int entryIndex { 0 };
    int imagesInLayout { int(layout->getElements().size()) };

    for(Collection::CollectionEntry entry : gCurrentProfile.collection.getSorted(currentSortMethod)) {
        updateEntry(entry, entryIndex, imagesInLayout);
        ++entryIndex;
    }

    // Check if Elements Need Removed
    if(entryIndex < imagesInLayout)
        layout->clearElements(imagesInLayout - entryIndex - 1);

    panel->calculateContentHeight();
}*/

void updateCollection() {
    layout->updateCollection();
    panel->calculateContentHeight();
}

void initCollectionViewState() {
    gCollectionViewState.setOnSwitch(
        [=]() {
            layout->setImageClickFunction(
                [=](Collection::CollectionEntry entry) {
                    SetViewer::setSelectedCard(entry.cardNumber, entry.expansion);
                    gSetState(SetViewer::gSetViewerState);
                }
            );
            updateCollection();
        }
    );

    // Init Grid Layout
    layout = new CollectionLayout();
    layout->setScale(2.0f);
    layout->setBackgroundColor(sf::Color::Blue);

    /*for(int i = 0; i < 102; ++i) {
        UIImage* image = new UIImage(0.0f, 0.0f, Expansions::gExpansionList[0]->cards[i]->mTexture);
        layout->addElement(image);
    }*/
    //std::cout << layout->getHeight() << "\n ==================Penis" << std::endl;

    panel = new UIScrollPanel(gWindowWidth, gWindowHeight, 20.0f, 50.0f);
    // Offset Panel to y=5%, Shrink Height to 95%
    panel->getView().setViewport({{ 0.0f, 0.05f }, { 1.0f, 0.95f }});

    updateCollection();  
    panel->addElement(layout);

    // Init Back Button
    backButton = new UIButton(10.0f, 10.0f, 50.0f, 50.0f);
    backButton->setText("Back");
    backButton->createClickFunction(
        []() {
            gSetState(PackSimulator::gPackSimulatorState);
        }
    );

    // Init Sort Dropdown
    sortDropdown = new UIDropdown(gWindowWidth - 110.0f, 10.0f, 100.0f, 50.0f, "Sort",
        { "Recent", "Card #", "Name", "Type" });
    sortDropdown->createClickFunction(
        [=]() {
            if(sortDropdown->getSelectedText() != gDefaultString) {
                layout->changeSortMethod(SortMethod(sortDropdown->getSelectedIndex()));
                updateCollection();
            }
        }
    );

    gCollectionViewState.addUIElement(panel);
    gCollectionViewState.addUIElement(backButton);
    gCollectionViewState.addUIElement(sortDropdown);
    /*Collection collection {};

    collection.addToCollection({ ExpansionID::BaseSet, 1 });
    collection.addToCollection({ ExpansionID::Jungle, 43 });
    collection.addToCollection({ ExpansionID::BaseSet, 4 });
    collection.addToCollection({ ExpansionID::BaseSet, 1 });

    for(Collection::CollectionEntry entry : collection.entries()) {
        std::cout << "Expansion " << entry.expansion << ' ' << entry.getCard()->cardNameString() << " x" << entry.quantity;
    }*/
}

}}