#pragma once

#include <algorithm>
#include <string>
#include <vector>

namespace Cori {

namespace Expansion {

struct Expansion {
    const std::string expansionName;
    const std::string expansionAbbreviation;
    const int cardCount;

    const std::string expansionLowerAbbreviation() const {
        std::string abbreviation { expansionAbbreviation };
        for(auto& ch : abbreviation)
            ch = std::tolower(static_cast<unsigned char>(ch));
        return abbreviation;
    }
};

constexpr Expansion base { "Base Set", "BS", 102 };
constexpr Expansion jungle { "Jungle", "JU", 64 };
constexpr Expansion fossil { "Fossil", "FO", 62 };

const std::vector<Expansion> gExpansionList { 
    base, jungle, fossil 
};

}

}