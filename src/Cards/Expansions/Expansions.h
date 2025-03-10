#pragma once

#include "../Expansion.h"
#include <vector>

namespace Cori { namespace Expansions {

    // Defined in Respective Header Files
    extern Expansion base;
    extern Expansion jungle;
    extern Expansion fossil;
    
    // Defined in Expansions.cpp
    extern std::vector<Expansion*> gExpansionList;
    extern std::vector<std::string> gExpansionNames();

}}