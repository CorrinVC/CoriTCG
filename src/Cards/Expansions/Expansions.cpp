#include "Expansions.h"
#include "RarityGenerators.h"

#include "BaseSet.h"
#include "Jungle.h"
#include "Fossil.h"

namespace Cori { namespace Expansions {

    using namespace Expansions;
    // Initializing Expansions & Their Pack Rarity Generation
    std::vector<Expansion*> gExpansionList {
        base.setPackRarityGen(baseEraPackRarities), 
        jungle.setPackRarityGen(baseEraRaritiesNoEnergy), 
        fossil.setPackRarityGen(baseEraRaritiesNoEnergy)
    };

    // Accessible list of Expansion Names, Indexed by ExpansionID
    std::vector<std::string> gExpansionNames() {
        std::vector<std::string> names;
        for(Expansion* expansion : gExpansionList)
            names.push_back(expansion->expansionName);
        return names;
    }

}}