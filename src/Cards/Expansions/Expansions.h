#pragma once

#include "BaseSet.h"
#include "Jungle.h"

namespace Cori { namespace Expansions {

    constexpr Expansion fossil { "Fossil", "FO", ExpansionID::Fossil,
        {
    
        }};
    

    const Expansion* gExpansionList[] {
        &base, &jungle, &fossil
    };

}}