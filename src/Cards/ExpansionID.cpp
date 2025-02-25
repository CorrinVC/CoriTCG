#include "ExpansionID.h"

namespace Cori { namespace Expansions {

std::string getExpansionAbbreviation(ExpansionID expansion) {
    switch(expansion) {
    case BaseSet: return "BS";
    case Jungle:  return "JU";
    case Fossil:  return "FO";
    }
    return "";
}

std::string getExpansionLowerAbbreviation(ExpansionID expansion)  {
    std::string lower { getExpansionAbbreviation(expansion) };
    for(auto& ch : lower)
        ch = std::tolower(static_cast<unsigned char>(ch));
    return lower;
}

}}