#include "State.h"
#include "../Cards/ExpansionID.h"
#include "../Profile/Collection.h"
#include "../Profile/Profile.h"
#include "../UI/UIGridLayout.h"
#include "../UI/UIImage.h"

namespace Cori { namespace CollectionView {

State gCollectionViewState {};

UIGridLayout* layout;

void initCollectionViewState() {
    layout = new UIGridLayout(12.0f, 10.0f);
    layout->setScale(2.0f);

    for(int i = 0; i < 102; ++i) {
        std::cout << i << ' ' << std::flush;
        UIImage* image = new UIImage(0.0f, 0.0f, gCardBackTexture);
        layout->addElement(image);
    }

    std::cout << "Images Generated" << std::endl;

    gCollectionViewState.addUIElement(layout);

    std::cout << "Collection State Initialized" << std::endl;
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