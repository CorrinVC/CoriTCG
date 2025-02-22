#pragma once

#include <string>

namespace Cori {

struct Expansion {
    const std::string expansionName;
    const std::string expansionAbbreviation;
    const int cardCount;
    
    constexpr Expansion(const std::string_view name, 
        const std::string_view abbreviation,  int count) 
    : expansionName { name }
    , expansionAbbreviation { abbreviation }
    , cardCount { cardCount } 
    {}
};

}