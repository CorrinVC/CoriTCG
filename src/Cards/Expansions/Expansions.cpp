#include "Expansions.h"
#include "BaseSet.h"
#include "Jungle.h"

namespace Cori { namespace Expansions {

    Expansion fossil { "Fossil", ExpansionID::Fossil,
        {
    
        }
    };

    using namespace Expansions;
    std::vector<Expansion*> gExpansionList {
        &base, &jungle, &fossil
    };

    std::vector<std::string> gExpansionNames() {
        std::vector<std::string> names;
        for(Expansion* expansion : gExpansionList)
            names.push_back(expansion->expansionName);
        return names;
    }

}}