#pragma once

#include "../../Random.h"
#include "../Expansion.h"

namespace Cori { namespace Expansions {

    using Cori::Rarity;    
    auto baseEraPackRarities {
        []() -> std::vector<Rarity> {
            Rarity rare { Random::get(3) == 0 ? HoloRare : Rare };
            return {
                rare, Uncommon, Uncommon, Uncommon,
                Common, Common, Common, Common, Common,
                None, None
            };
        }
    }; 

}}