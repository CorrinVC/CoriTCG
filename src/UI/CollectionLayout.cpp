#include "CollectionLayout.h"
#include "../Profile/Profile.h"
#include "../States/State.h"
#include "UIImage.h"

namespace Cori {

CollectionLayout::CollectionLayout(float width, float height)
: UIGridLayout(12.0f, 10.0f, width, height)
{}

int CollectionLayout::imagesInLayout() {
    return int(getElements().size());
}

void CollectionLayout::generateImage(Collection::CollectionEntry& entry) {
    UIImage* image = new UIImage(0.0f, 0.0f, entry.getCard()->mTexture);

    image->createClickFunction(
        [=,this]() {
            mImageClickFunc(entry);
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

void CollectionLayout::setImageClickFunction(std::function<void(Collection::CollectionEntry)> function) {
    mImageClickFunc = function;
}

}