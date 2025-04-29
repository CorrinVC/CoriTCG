#pragma once

#include "Card.h"
#include "../Profile/SortMethod.h"

namespace Cori {
    

class DeckList {
public:
    struct DeckEntry {
        DataCard* card {};
        int quantity { 1 }; 

        void addCard() { ++quantity; }
    };

private:

    std::vector<DeckEntry> mCards {};
    int mCardCount {};

    bool mEnoughCards { false };
    bool mHasBasic { false };

    bool checkCardCount(DataCard* card);
    void updateValidity(DataCard* card);

    SortMethod mSortMethod { SortMethod::NumberSort };
    void insertBySort(DataCard* card);

public:

    bool addCard(DataCard* card);
    void sortList(SortMethod method);

    std::vector<DeckEntry> getCards();
    bool isValid();

    int findCardIndex(DataCard* card);
    int getCountOfCard(DataCard* card);

};


}