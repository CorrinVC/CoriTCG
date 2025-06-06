#pragma once

#include "Card.h"

namespace Cori {

enum TrainerType {
    Item,
    Tool,
    Supporter,
    Stadium
};

// Name, Trainer Type, Illustrator, ExpansionID, #, Rarity
class TrainerCard : public DataCard {
public:
    const TrainerType mTrainerType {};

    TrainerCard(const sf::String name, const TrainerType trainerType, 
        const std::string_view illustrator, const ExpansionID expansion, 
        const int cardNumber, const Rarity rarity)
    : DataCard(name, CardType::Trainer, illustrator, expansion, cardNumber, rarity)
    , mTrainerType { trainerType }
    {}
};

}