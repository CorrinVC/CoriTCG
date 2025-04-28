#include "Card.h"

namespace Cori {

class Deck {
public:
    struct DeckEntry {
        DataCard* card {};
        int quantity { 1 }; 

        void addCard() { ++quantity; }
    };

private:

    std::vector<DeckEntry> mCards {};
    int cardCount {};

    bool mEnoughCards { false };
    bool mHasBasic { false };

    bool checkCardCount(DataCard* card);
    void updateValidity(DataCard* card);

public:

    bool addCard(DataCard* card);

    std::vector<DeckEntry> getCards();
    bool isValid();

    int findCardIndex(DataCard* card);
    int getCountOfCard(DataCard* card);

};


}