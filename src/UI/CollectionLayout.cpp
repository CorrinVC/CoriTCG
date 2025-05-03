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

void collectionImageClicked(QuantityCard& card) {
    // Change to Card View State if in Collection View State
    if(gCurrentState == &CollectionView::gCollectionViewState) {
        SetViewer::setSelectedCard(card.cardNumber(), card.expansion());
        gSetState(SetViewer::gSetViewerState);
    } // Add Card to Current Deck if in Deck Builder State
    else if(gCurrentState == &DeckBuilder::gDeckBuilderState) {
        DeckBuilder::addToDeck(card);
    } else {
        return;
    }
}

void CollectionLayout::generateImage(QuantityCard& card) {
    UIImage* image = new UIImage(0.0f, 0.0f, card.card->mTexture);

    image->createClickFunction(
        [=]() mutable {
            collectionImageClicked(card);
        }
    );

    image->addCaption({ 50.0f, 25.0f, std::format("{}", card.quantity) });
    image->getCaption().setBackgroundColor(sf::Color::Black);

    addElement(image);
}

void CollectionLayout::changeImage(QuantityCard& card, int cardIndex) {
    UIImage* image { static_cast<UIImage*>(getElements()[cardIndex]) };

    image->changeTexture(card.card->mTexture);
    image->getCaption().setText(std::format("{}", card.quantity));

    // TODO - Give UIElements Scale Factor Member Var
    updateScale();

    image->createClickFunction(
        [=]() mutable {
            collectionImageClicked(card);
        }
    );
}

void CollectionLayout::updateEntry(QuantityCard& card, int cardIndex) {
    if(cardIndex >= imagesInLayout())
        generateImage(card);
    else
        changeImage(card, cardIndex);
}

void CollectionLayout::updateCollection() {
    int cardIndex { 0 };

    for(QuantityCard card : 
        gCurrentProfile.collection.getSorted(mSortMethod)) {
        updateEntry(card, cardIndex);
        ++cardIndex;
    }

    // Check if Elements Need Removed
    if(cardIndex < imagesInLayout())
        clearElements(imagesInLayout() - cardIndex - 1);
}

void CollectionLayout::changeSortMethod(SortMethod method) {
    mSortMethod = method;
    //updateCollection();
}

/*void CollectionLayout::setImageClickFunction(std::function<void(Collection::CollectionEntry)> function) {
    mImageClickFunc = function;
}*/

}