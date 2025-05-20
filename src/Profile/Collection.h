#pragma once

#include "QuantityCard.h"
#include "SortMethod.h"
#include "../JSON.h"
#include "../Cards/Card.h"
#include "../Cards/ExpansionID.h"
#include "../Cards/Expansions/Expansions.h"
#include <iostream>
#include <vector>

namespace Cori {

class Collection {
public:
    /*struct CollectionEntry {
        ExpansionID expansion {};
        int cardNumber {};

        int quantity { 1 };

        DataCard* getCard() {
            return Expansions::gExpansionList[expansion]->cards[cardNumber - 1];
        }

        void addToEntry() {
            ++quantity;
        }

        void print() {
            std::cout << "Entry (" << this << "): "
                << Expansions::gExpansionNames()[expansion] << ' '
                << getCard()->cardNameString() << " #" << cardNumber 
                << " x" << quantity << std::endl;
        }
    };*/

private:
    std::vector<QuantityCard> mCollection {};
public:
    const std::vector<QuantityCard>& entries();
    const std::vector<QuantityCard> getSorted(SortMethod method); // TODO
    

    void addToCollection(QuantityCard entry);
    void printCollection(SortMethod method = NoSort); // Temporary?

    void loadFromFileData(nlohmann::ordered_json& data);
    void saveCollection(nlohmann::ordered_json& data);
};

}