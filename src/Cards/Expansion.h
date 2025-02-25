#pragma once

#include "Card.h"
#include "ExpansionID.h"
#include <algorithm>
#include <memory>
#include <string>
#include <vector>

namespace Cori {

struct Expansion {
    const std::string expansionName;
    const std::string expansionAbbreviation;
    const ExpansionID expansionID;
    const std::vector<DataCard> cards;

    std::string expansionLowerAbbreviation() const {
        std::string abbreviation { expansionAbbreviation };
        for(auto& ch : abbreviation)
            ch = std::tolower(static_cast<unsigned char>(ch));
        return abbreviation;
    }

    int cardCount() const {
        return cards.size();
    }
};

}