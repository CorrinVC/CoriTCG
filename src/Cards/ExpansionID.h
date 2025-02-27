#pragma once

#include <string>

namespace Cori {

enum ExpansionID {
    BaseSet,
    Jungle,
    Fossil
};

namespace Expansions {
    // Defined in ExpansionID.cpp

    std::string getExpansionAbbreviation(ExpansionID expansion);

    std::string getExpansionLowerAbbreviation(ExpansionID expansion);
}

}