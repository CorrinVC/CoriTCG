#pragma once

#include "Card.h"

namespace Cori {

class EnergyCard: public DataCard {
public:
    const bool mIsBasicEnergy;
    
    constexpr EnergyCard(const sf::String name, const bool isBasicEnergy, 
        const std::string_view illustrator, const ExpansionID expansion, 
        const int cardNumber, const Rarity rarity)
    : DataCard(name, CardType::Energy, illustrator, expansion, cardNumber, rarity)
    , mIsBasicEnergy { isBasicEnergy }
    {}
};

}