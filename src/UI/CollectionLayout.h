#include "UIGridLayout.h"
#include "../Profile/Collection.h"
#include <functional>

namespace Cori {

class CollectionLayout : public UIGridLayout {
private:
    SortMethod mSortMethod;
    //float mScaleFactor { 2.0f };

    std::function<void(Collection::CollectionEntry)> mImageClickFunc {};

    int imagesInLayout();

    void generateImage(Collection::CollectionEntry& entry);
    void changeImage(Collection::CollectionEntry& entry, int entryIndex);
    void updateEntry(Collection::CollectionEntry& entry, int entryIndex);
public:
    CollectionLayout(float width = gWindowWidth, float height = gWindowHeight);

    void updateCollection();
    void changeSortMethod(SortMethod method);
    void setImageClickFunction(std::function<void(const Collection::CollectionEntry)> function);

};

}