#include "Collection.h"
#include <algorithm>
#include <iostream>

namespace Cori {

const std::vector<Collection::CollectionEntry>& Collection::entries() {
    return mCollection;
}

const std::vector<Collection::CollectionEntry> sortByNumber(std::vector<Collection::CollectionEntry>& entries) {
    std::vector<Collection::CollectionEntry> sorted { entries };

    std::sort(sorted.begin(), sorted.end(), 
        [](Collection::CollectionEntry& a, Collection::CollectionEntry& b) {
            return (a.expansion < b.expansion) || 
                ((a.expansion == b.expansion) && (a.cardNumber < b.cardNumber));
    });

    return sorted;
}

const std::vector<Collection::CollectionEntry> Collection::getSorted(Collection::SortMethod method) {
    switch(method) {

    case CollectorNumber:
        return sortByNumber(mCollection);
    default:
        return entries();
    
    }

}

// Add Entry to Collection
void Collection::addToCollection(const CollectionEntry entry) {
    const auto foundIndex { std::find(mCollection.begin(), mCollection.end(), entry) };
    
    // Check if Card Not Already In Collection
    if(foundIndex == mCollection.end())
        mCollection.push_back(entry);
    else {
        (*foundIndex).addToEntry();
        std::rotate(foundIndex, foundIndex + 1, mCollection.end());
    }
}

// Output Collection as text to console - Temporary
void Collection::printCollection(SortMethod method) {
    for(CollectionEntry entry : getSorted(method)) {
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