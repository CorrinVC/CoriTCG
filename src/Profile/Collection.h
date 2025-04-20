#pragma once

#include "../Cards/Card.h"
#include "../Cards/ExpansionID.h"
#include "../Cards/Expansions/Expansions.h"
#include <vector>

namespace Cori {

class Collection {
public:
    struct CollectionEntry {
        ExpansionID expansion {};
        int cardNumber {};

        int quantity { 1 };

        DataCard* getCard() {
            return Expansions::gExpansionList[expansion]->cards[cardNumber - 1];
        }

        void addToEntry() {
            ++quantity;
        }
    };

    enum SortMethod {
        NoSort,
        CollectorNumber,
        CardName,
        CardType,
        Evolutions,
    };

private:
    std::vector<CollectionEntry> mCollection {};
public:
    const std::vector<CollectionEntry>& entries();
    const std::vector<CollectionEntry> getSorted(SortMethod method); // TODO

    void addToCollection(CollectionEntry entry);
    void printCollection(SortMethod method = NoSort); // Temporary?
};

extern bool operator==(Collection::CollectionEntry left, Collection::CollectionEntry right);

}