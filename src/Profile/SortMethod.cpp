#include "SortMethod.h"
#include "../Cards/PokemonCard.h"

namespace Cori {

std::vector<std::string> gSortMethods {
    "Recent", "Card #", "Name", "Type"
};

bool lowerExpansion(QuantityCard a, QuantityCard b) {
    return a.expansion() < b.expansion();
}

bool sameExpansion(QuantityCard a, QuantityCard b) {
    return a.expansion() == b.expansion();
}

bool lowerCardNum(QuantityCard a, QuantityCard b) {
    return a.cardNumber() < b.cardNumber();
}

bool lowerName(QuantityCard a, QuantityCard b) {
    return a.card->cardNameString() < b.card->cardNameString();
}

bool lowerCardType(QuantityCard a, QuantityCard b) {
    return a.card->mCardType < b.card->mCardType;
}

bool lowerEnergyType(QuantityCard a, QuantityCard b) {
    return ((a.card->mCardType == Pokemon) && (b.card->mCardType == Pokemon)) &&
           (static_cast<PokemonCard*>(a.card)->mEnergyType <
            static_cast<PokemonCard*>(b.card)->mEnergyType);
}

std::vector<QuantityCard> sortByNumber(std::vector<QuantityCard> cardList) {
    std::stable_sort(cardList.begin(), cardList.end(),
        [](QuantityCard a, QuantityCard b) {
            return(lowerExpansion(a, b) || // Earlier Expansion
                  (sameExpansion(a, b) && // Same Expansion, Lower Card #
                   lowerCardNum(a, b)));
        }
    );
    return cardList;
}

std::vector<QuantityCard> sortByName(std::vector<QuantityCard> cardList) {
    std::stable_sort(cardList.begin(), cardList.end(),
        [](QuantityCard a, QuantityCard b) {
            return lowerName(a, b);
        }
    );
    return cardList;
}

std::vector<QuantityCard> sortByType(std::vector<QuantityCard> cardList) {
    std::stable_sort(cardList.begin(), cardList.end(),
        [](QuantityCard a, QuantityCard b) {
            return lowerCardType(a, b) || lowerEnergyType(a, b);
        }
    );
    return cardList;
}

std::vector<QuantityCard> sortCardList(std::vector<QuantityCard> cardList, SortMethod method) {
    switch(method) {
    case NumberSort:
        cardList = sortByNumber(cardList);
        break;
    case NameSort:
        cardList = sortByName(sortByNumber(cardList));
        break;
    case TypeSort:
        cardList = sortByType(sortByNumber(cardList));
        break;
    default:
        break;
    }

    return cardList;
};

}