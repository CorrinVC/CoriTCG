#include "State.h"
#include "../Cards/Expansions/Expansions.h"
#include "../Profile/Collection.h"
#include "../Profile/Profile.h"
#include "../UI/UIGridLayout.h"
#include "../UI/UIImage.h"
#include "../UI/UIScrollPanel.h"

namespace Cori { namespace CollectionView {

State gCollectionViewState {};

UIGridLayout* layout;
UIScrollPanel* panel;

void initCollectionViewState() {
    layout = new UIGridLayout(12.0f, 10.0f);
    layout->setScale(2.0f);
    layout->setBackgroundColor(sf::Color::Blue);

    for(int i = 0; i < 102; ++i) {
        UIImage* image = new UIImage(0.0f, 0.0f, Expansions::gExpansionList[0]->cards[i]->mTexture);
        //std::cout << image->getWidth() << ',' << image->getHeight() << std::endl;
        layout->addElement(image);
    }
    std::cout << layout->getHeight() << "\n ==================Penis" << std::endl;
    //std::cout << layout->getElements().back()->getX() << ',' << layout->getElements().back()->getX() << std::endl;

    panel = new UIScrollPanel(gWindowWidth, gWindowHeight, 20.0f, 50.0f);

    panel->addElement(layout);
    
    gCollectionViewState.addUIElement(panel);
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