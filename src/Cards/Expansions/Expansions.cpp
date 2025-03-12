#include "Expansions.h"
#include "RarityGenerators.h"

#include "BaseSet.h"
#include "Jungle.h"
#include "Fossil.h"

#include "../../Random.h"

namespace Cori { namespace Expansions {

    using namespace Expansions;
    std::vector<Expansion*> gExpansionList {
        base.setPackRarityGen(baseEraPackRarities), &jungle, &fossil
    };

    std::vector<std::string> gExpansionNames() {
        std::vector<std::string> names;
        for(Expansion* expansion : gExpansionList)
            names.push_back(expansion->expansionName);
        return names;
    }

}}