#pragma once

#include "Card.h"
#include "ExpansionID.h"
#include <functional>
#include <map>
#include <string>
#include <vector>

namespace Cori {

struct Expansion {

    const std::string expansionName;
    const ExpansionID expansionID;

    const int packQuantity;

    const std::vector<DataCard*> cards;
    std::function<std::vector<Rarity>(void)> packRarities;

    // Lists of Cards Split By Rarity
    std::map<Rarity, std::vector<DataCard*>> cardsByRarity;


    Expansion(std::string name, ExpansionID id, int quantity, std::vector<DataCard*> cardList) 
    : expansionName { name }, expansionID { id }
    , packQuantity { quantity }, cards { cardList }
    {
        for(DataCard* card : cardList)
            cardsByRarity[card->mRarity].push_back(card);
    }

    Expansion* setPackRarityGen(std::function<std::vector<Rarity>(void)> generator) {
        packRarities = generator;
        return this;
    }

    std::string expansionAbbreviation() const {
        return Expansions::getExpansionAbbreviation(expansionID);
    }

    std::string expansionLowerAbbreviation() const {
        return Expansions::getExpansionLowerAbbreviation(expansionID);
    }

    int cardCount() const {
        return std::size(cards);
    }

    std::vector<DataCard*> getCardsByRarity(Rarity rarity) {
        return cardsByRarity[rarity];
    }

    int cardCountOfRarity(Rarity rarity) {
        return int(cardsByRarity[rarity].size());
    }
};

}