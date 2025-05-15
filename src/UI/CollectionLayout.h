#pragma once

#include "UIGridLayout.h"
#include "../Profile/Collection.h"
#include "../Profile/QuantityCard.h"
#include <functional>

namespace Cori {

class CollectionLayout : public UIGridLayout {
private:
    SortMethod mSortMethod;

    //std::function<void(Collection::CollectionEntry)> mImageClickFunc {};

    int imagesInLayout();

    void generateImage(QuantityCard& card);
    void changeImage(QuantityCard& card, int entryIndex);
    void updateEntry(QuantityCard& card, int entryIndex);
public:
    CollectionLayout(float width = gWindowWidth, float height = 10.0f);

    void updateCollection();
    void changeSortMethod(SortMethod method);
    //void setImageClickFunction(std::function<void(const Collection::CollectionEntry)> function);
};

extern CollectionLayout* gCollectionLayout;

void initCollectionLayout();

}