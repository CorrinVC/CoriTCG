#pragma once

#include "../Cards/Card.h"
#include "QuantityCard.h"
#include "SortMethod.h"

namespace Cori {
    

class DeckList {
public:
    /*struct DeckEntry {
        DataCard* card {};
        int quantity { 1 }; 

        void addCard() { ++quantity; }
    };*/

private:
    sf::String mDeckName {};

    std::vector<QuantityCard> mCards {};
    int mCardCount {};

    bool mEnoughCards { false };
    bool mHasBasic { false };

    bool checkCardCount(DataCard* card);
    void updateValidity(DataCard* card);

    SortMethod mSortMethod { SortMethod::NumberSort };

public:

    bool addCard(DataCard* card);

    void setName(sf::String name);

    std::vector<QuantityCard> getCards();
    std::vector<QuantityCard> getSortedList(SortMethod method);

    bool isValid();
    sf::String& getName();

    int findCardIndex(DataCard* card);
    int findSortedIndex(DataCard* card, SortMethod method);
    int getCountOfCard(DataCard* card);

};


}