#pragma once

#include "Card.h"
#include "ExpansionID.h"
#include <algorithm>
#include <string>
#include <vector>

namespace Cori {

struct Expansion {
    const std::string expansionName;
    const ExpansionID expansionID;
    const std::vector<DataCard*> cards;

    std::string expansionAbbreviation() const {
        return Expansions::getExpansionAbbreviation(expansionID);
    }

    std::string expansionLowerAbbreviation() const {
        return Expansions::getExpansionLowerAbbreviation(expansionID);
    }

    int cardCount() const {
        return std::size(cards);
    }
};

}