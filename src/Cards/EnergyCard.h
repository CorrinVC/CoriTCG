#pragma once

#include "Card.h"

namespace Cori {

class EnergyCard: public DataCard {
protected:
    const bool mIsBasicEnergy;
public:
    constexpr EnergyCard(const std::string_view name, const bool isBasicEnergy, 
        const std::string_view illustrator, const ExpansionID expansion, 
        const int cardNumber, const Rarity rarity)
    : DataCard(name, CardType::Energy, illustrator, expansion, cardNumber, rarity)
    , mIsBasicEnergy { isBasicEnergy }
    {}
};

}