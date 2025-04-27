#include "Deck.h"
#include "PokemonCard.h"

namespace Cori {

// Check for "Rule of Four"
bool Deck::checkCardCount(DataCard* card) {
    int sameNameCards { 0 };
    for(DataCard* c : mCards) {
        if(card->mCardName == c->mCardName) 
            sameNameCards++;
    }

    return sameNameCards <= 4;
}

void Deck::updateValidity(DataCard* card) {
    // Check Deck Card Count
    if(!mEnoughCards && mCards.size() >= 60)
        mEnoughCards = true;

    // Check for Basic
    if(!mHasBasic && card->mCardType == Pokemon) {
        if(static_cast<PokemonCard*>(card)->mStage == Basic)
            mHasBasic = true;
    }
}

void Deck::addCard(DataCard* card) {
    if(checkCardCount(card)) {
        mCards.push_back(card);

        updateValidity(card);
    }
}

std::vector<DataCard*> Deck::getCards() {
    return mCards;
}

bool Deck::isValid() {
    return mEnoughCards && mHasBasic;
}

}