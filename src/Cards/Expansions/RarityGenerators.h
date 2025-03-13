#pragma once

#include "../../Random.h"
#include "../Expansion.h"

namespace Cori { namespace Expansions {

    using Cori::Rarity;    
    auto baseEraPackRarities {
        []() -> std::vector<Rarity> {
            Rarity rare { Random::get(3) == 0 ? HoloRare : Rare };
            return {
                Uncommon, Uncommon, Uncommon,
                Common, Common, Common, Common, Common,
                None, None, rare
            };
        }
    }; 

    auto baseEraRaritiesNoEnergy {
        []() -> std::vector<Rarity> {
            auto rarities { baseEraPackRarities() };
            rarities[8] = Common;
            rarities[9] = Common;
            return rarities;
        }
    };

}}