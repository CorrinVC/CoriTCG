#pragma once

#include "QuantityCard.h"

namespace Cori {

enum SortMethod {
    NoSort,
    NumberSort,
    NameSort,
    TypeSort,
    EvolutionSort,
};

extern std::vector<std::string> gSortMethods;
extern std::vector<QuantityCard> sortCardList(std::vector<QuantityCard> list, SortMethod method);

}