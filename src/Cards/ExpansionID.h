#pragma once

#include <string>

namespace Cori {

enum ExpansionID {
    BaseSet,
    Jungle,
    Fossil
};

namespace Expansions {
    std::string getExpansionAbbreviation(ExpansionID expansion);

    std::string getExpansionLowerAbbreviation(ExpansionID expansion);
}

}