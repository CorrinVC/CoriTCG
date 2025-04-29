#include "Collection.h"
#include "../Cards/PokemonCard.h"
#include <algorithm>
#include <iostream>

namespace Cori {

const std::vector<QuantityCard>& Collection::entries() {
    return mCollection;
}

//const std::vector<QuantityCard

const std::vector<QuantityCard> Collection::getSorted(SortMethod method) {
    return sortCardList(mCollection, method);
    /*std::vector<QuantityCard> sorted { mCollection };
    switch(method) {

    case NumberSort:
        std::sort(sorted.begin(), sorted.end(),
        [](QuantityCard a, QuantityCard b) {
            return (a.expansion() < b.expansion()) || // Earlier Expansion 
                ((a.expansion() == b.expansion()) && (a.cardNumber() < b.cardNumber())); // Same Expansion, Lower Number
        });
        break;
    case NameSort:
        sorted = getSorted(NumberSort);
        // Sort by Collector No. Then By Name
        std::sort(sorted.begin(), sorted.end(),
        [](QuantityCard a, QuantityCard b) {
            return a.card->cardNameString() < b.card->cardNameString();
        });
        break;

    case TypeSort:
        sorted = getSorted(NumberSort);
        // Sort by Collector No. Then By Type
        std::sort(sorted.begin(), sorted.end(),
        [](QuantityCard a, QuantityCard b) {
            return (a.card->mCardType < b.card->mCardType) ||
                ((a.card->mCardType == Pokemon && b.card->mCardType == Pokemon) && 
                static_cast<PokemonCard*>(a.card)->mEnergyType < 
                static_cast<PokemonCard*>(b.card)->mEnergyType);
        });
        break;
    default:
        break;
    
    }
    return sorted;*/
}

// Add Entry to Collection
void Collection::addToCollection(const QuantityCard card) {
    const auto foundIndex { std::find(mCollection.begin(), mCollection.end(), card) };
    
    // Check if Card Not Already In Collection
    if(foundIndex == mCollection.end())
        mCollection.push_back(card);
    else {
        (*foundIndex).addToCard();
        std::rotate(foundIndex, foundIndex + 1, mCollection.end());
    }
}

// Output Collection as text to console - Temporary
void Collection::printCollection(SortMethod method) {
    for(QuantityCard card : getSorted(method)) {
        card.print();
    }
}

}