#include "Card.h"

namespace Cori {

class Deck {
private:

    std::vector<DataCard*> mCards;
    bool mEnoughCards { false };
    bool mHasBasic { false };

    bool checkCardCount(DataCard* card);
    void updateValidity(DataCard* card);

public:

    void addCard(DataCard* card);

    std::vector<DataCard*> getCards();
    bool isValid();

};


}