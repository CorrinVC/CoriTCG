#include "CollectionLayout.h"
#include "../Profile/Profile.h"
#include "../States/State.h"
#include "UIImage.h"

namespace Cori {

CollectionLayout* gCollectionLayout = new CollectionLayout();

void initCollectionLayout() {
    gCollectionLayout->setScale(2.0f);
    gCollectionLayout->setBackgroundColor(sf::Color(200, 180, 200));
}

CollectionLayout::CollectionLayout(float width, float height)
: UIGridLayout(10.0f, 8.0f, width, height)
{}

int CollectionLayout::imagesInLayout() {
    return int(getElements().size());
}

void collectionImageClicked(Collection::CollectionEntry entry) {
    // Change to Card View State if in Collection View State
    if(gCurrentState == &CollectionView::gCollectionViewState) {
        SetViewer::setSelectedCard(entry.cardNumber, entry.expansion);
        gSetState(SetViewer::gSetViewerState);
    } // Add Card to Current Deck if in Deck Builder State
    else if(gCurrentState == &DeckBuilder::gDeckBuilderState) {
        DeckBuilder::addToDeck(entry.getCard(), entry.quantity);
    } else {
        return;
    }
}

void CollectionLayout::generateImage(Collection::CollectionEntry& entry) {
    UIImage* image = new UIImage(0.0f, 0.0f, entry.getCard()->mTexture);

    image->createClickFunction(
        [=]() {
            collectionImageClicked(entry);
        }
    );

    image->addCaption({ 100.0f, 50.0f, std::format("{}", entry.quantity) });
    image->getCaption().setBackgroundColor(sf::Color::Black);

    addElement(image);
}

void CollectionLayout::changeImage(Collection::CollectionEntry& entry, int entryIndex) {
    UIImage* image { static_cast<UIImage*>(getElements()[entryIndex]) };

    image->changeTexture(entry.getCard()->mTexture);
    image->getCaption().setText(std::format("{}", entry.quantity));

    // TODO - Give UIElements Scale Factor Member Var
    updateScale();

    image->createClickFunction(
        [=]() {
            collectionImageClicked(entry);
        }
    );
}

void CollectionLayout::updateEntry(Collection::CollectionEntry& entry, int entryIndex) {
    if(entryIndex >= imagesInLayout())
        generateImage(entry);
    else
        changeImage(entry, entryIndex);
}

void CollectionLayout::updateCollection() {
    int entryIndex { 0 };

    for(Collection::CollectionEntry entry : 
        gCurrentProfile.collection.getSorted(mSortMethod)) {
        updateEntry(entry, entryIndex);
        ++entryIndex;
    }

    // Check if Elements Need Removed
    if(entryIndex < imagesInLayout())
        clearElements(imagesInLayout() - entryIndex - 1);
}

void CollectionLayout::changeSortMethod(SortMethod method) {
    mSortMethod = method;
    //updateCollection();
}

/*void CollectionLayout::setImageClickFunction(std::function<void(Collection::CollectionEntry)> function) {
    mImageClickFunc = function;
}*/

}