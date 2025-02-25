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

}}