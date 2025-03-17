#include "Collection.h"
#include <algorithm>
#include <iostream>

namespace Cori {

const std::vector<Collection::CollectionEntry>& Collection::entries() {
    return mCollection;
}

void Collection::addToCollection(const CollectionEntry entry) {
    const auto foundIndex { std::find(mCollection.begin(), mCollection.end(), entry) };
    
    if(foundIndex == mCollection.end())
        mCollection.push_back(entry);
    else {
        (*foundIndex).addToEntry();
        std::rotate(foundIndex, foundIndex + 1, mCollection.end());
    }
}

void Collection::printCollection() {
    for(CollectionEntry entry : mCollection) {
        Expansion* expansion { Expansions::gExpansionList[entry.expansion] };
        std::cout << expansion->expansionName << ' ' << expansion->cards[entry.cardNumber - 1]->cardNameString()
            << " x" << entry.quantity << '\n';
    }
    std::cout << std::flush;
}

bool operator==(Collection::CollectionEntry left, Collection::CollectionEntry right) {
    return {
        left.expansion == right.expansion
        && left.cardNumber == right.cardNumber
    };
}

}