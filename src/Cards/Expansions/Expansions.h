#pragma once

#include "BaseSet.h"

namespace Cori { namespace Expansions {

    constexpr Expansion jungle { "Jungle", "JU", ExpansionID::Jungle,
        {
    
        }};
    
    constexpr Expansion fossil { "Fossil", "FO", ExpansionID::Fossil,
        {
    
        }};
    
    const std::vector<Expansion> gExpansionList {
        base, jungle, fossil
    };

}}