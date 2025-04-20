#include "ExpansionID.h"

namespace Cori { namespace Expansions {

// Get Acronym/Abbreviation for File Access
std::string getExpansionAbbreviation(ExpansionID expansion) {
    switch(expansion) {
    case BaseSet: return "BS";
    case Jungle:  return "JU";
    case Fossil:  return "FO";
    }
    return "";
}

// Get Lower For Texture Access
std::string getExpansionLowerAbbreviation(ExpansionID expansion)  {
    std::string lower { getExpansionAbbreviation(expansion) };
    for(auto& ch : lower)
        ch = std::tolower(static_cast<unsigned char>(ch));
    return lower;
}

}}