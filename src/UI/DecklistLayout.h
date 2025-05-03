#pragma once

#include "UIGridLayout.h"
#include "../Cards/DeckList.h"
#include "../Profile/SortMethod.h"

namespace Cori {


class DecklistLayout : public UIGridLayout {
private:
    DeckList mCurrentDeck {};
    SortMethod mSortMethod { SortMethod::TypeSort };

    void generateImage(QuantityCard& card);
    void incrementImage(QuantityCard& card);
    void changeImage(QuantityCard& card, int imgIndex);

    void sortDecklist();
    void updateDecklist();
public:
    DecklistLayout();
    DecklistLayout(float width, float height);

    void addToDeck(QuantityCard& card);
    void changeSortMethod(SortMethod method);
    void printDeck();
    void reset();

    void setDeck(DeckList deck);

    DeckList getCurrentDeck();
    int findCardIndex(QuantityCard& card);
};

extern DecklistLayout* gDecklistLayout;

void initDecklistLayout();


}