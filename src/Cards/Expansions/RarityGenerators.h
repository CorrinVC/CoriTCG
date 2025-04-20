#pragma once

#include "../../Random.h"
#include "../Expansion.h"

namespace Cori { namespace Expansions {

    using Cori::Rarity;
    
    // Used For Base Set
    // 2 Energy | 5 Common | 3 Uncommon | 1 Rare (1/3 chance of Holo Rare)
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

    // Used For Jungle, Fossil
    // 7 Common | 3 Uncommon | 1 Rare (1/3 chance of Holo Rare)
    auto baseEraRaritiesNoEnergy {
        []() -> std::vector<Rarity> {
            auto rarities { baseEraPackRarities() };
            rarities[8] = Common;
            rarities[9] = Common;
            return rarities;
        }
    };

}}