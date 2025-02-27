#pragma once

#include "Card.h"

namespace Cori {

// TODO - Implement Energy Type?
// Name, Is Basic?, Illustrator, ExpansionID, #, Rarity
class EnergyCard: public DataCard {
public:
    const bool mIsBasicEnergy;
    
    EnergyCard(const sf::String name, const bool isBasicEnergy, 
        const std::string_view illustrator, const ExpansionID expansion, 
        const int cardNumber, const Rarity rarity)
    : DataCard(name, CardType::Energy, illustrator, expansion, cardNumber, rarity)
    , mIsBasicEnergy { isBasicEnergy }
    {}
};

}