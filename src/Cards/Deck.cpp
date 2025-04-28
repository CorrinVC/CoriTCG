#include "Deck.h"
#include "PokemonCard.h"
#include "EnergyCard.h"

namespace Cori {

// Check for "Rule of Four"
bool Deck::checkCardCount(DataCard* card) {
    if(card->mCardType == Energy &&
       static_cast<EnergyCard*>(card)->mIsBasicEnergy)
        return true;

    int sameNameCards { 0 };
    for(DeckEntry entry: mCards) {
        if(card->mCardName == entry.card->mCardName) 
            sameNameCards += entry.quantity;
    }

    return sameNameCards < 4;
}

void Deck::updateValidity(DataCard* card) {
    // Check Deck Card Count
    if(!mEnoughCards && cardCount >= 60)
        mEnoughCards = true;

    // Check for Basic
    if(!mHasBasic && card->mCardType == Pokemon) {
        if(static_cast<PokemonCard*>(card)->mStage == Basic)
            mHasBasic = true;
    }
}

int Deck::findCardIndex(DataCard* card) {
    int foundIndex { -1 };
    
    for(int i { 0 }; i < int(mCards.size()); ++i) {
        if(mCards[i].card == card) {
            foundIndex = i;
            break;
        }
    }

    return foundIndex;
}

bool Deck::addCard(DataCard* card) {
    if(checkCardCount(card)) {
        if(findCardIndex(card) >= 0)
            mCards[findCardIndex(card)].addCard();
        else
            mCards.push_back({ card });
        ++cardCount;
        updateValidity(card);
        return true;
    } else return false;
}

std::vector<Deck::DeckEntry> Deck::getCards() {
    return mCards;
}

bool Deck::isValid() {
    return mEnoughCards && mHasBasic;
}

int Deck::getCountOfCard(DataCard* card) {
    int count { 0 };
    if(findCardIndex(card) >= 0)
        count = mCards[findCardIndex(card)].quantity;
    return count;
}

}