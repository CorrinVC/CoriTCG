#pragma once

#include "../Cards/Card.h"
#include <iostream>

namespace Cori {

struct QuantityCard {
    DataCard* card;
    int quantity { 1 };

    void addToCard() { ++quantity; }

    ExpansionID expansion() { return card->mExpansion; }
    int cardNumber() { return card->mCardNumber; }

    void print() {
        std::cout << "Entry (" << this << "): "
            << Expansions::gExpansionNames()[expansion()] << ' '
            << card->cardNameString() << " #" << cardNumber() 
            << " x" << quantity << std::endl;
    }
};

extern bool operator==(QuantityCard left, QuantityCard right);

}