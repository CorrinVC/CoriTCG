#include "DeckList.h"
#include "PokemonCard.h"
#include "EnergyCard.h"

namespace Cori {

// Check for "Rule of Four"
bool DeckList::checkCardCount(DataCard* card) {
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

void DeckList::updateValidity(DataCard* card) {
    // Check Deck Card Count
    if(!mEnoughCards && mCardCount >= 60)
        mEnoughCards = true;

    // Check for Basic
    if(!mHasBasic && card->mCardType == Pokemon) {
        if(static_cast<PokemonCard*>(card)->mStage == Basic)
            mHasBasic = true;
    }
}

int DeckList::findCardIndex(DataCard* card) {
    int foundIndex { -1 };
    
    for(int i { 0 }; i < int(mCards.size()); ++i) {
        if(mCards[i].card == card) {
            foundIndex = i;
            break;
        }
    }

    return foundIndex;
}

void DeckList::insertBySort(DataCard* card) {

}

bool DeckList::addCard(DataCard* card) {
    if(checkCardCount(card)) {
        if(findCardIndex(card) >= 0)
            mCards[findCardIndex(card)].addCard();
        else
            insertBySort(card);
        ++mCardCount;
        updateValidity(card);
        return true;
    } else return false;
}

void DeckList::sortList(SortMethod method) {

}

std::vector<DeckList::DeckEntry> DeckList::getCards() {
    return mCards;
}

bool DeckList::isValid() {
    return mEnoughCards && mHasBasic;
}

int DeckList::getCountOfCard(DataCard* card) {
    int count { 0 };
    if(findCardIndex(card) >= 0)
        count = mCards[findCardIndex(card)].quantity;
    return count;
}

}