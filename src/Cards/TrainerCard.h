#pragma once

#include "Card.h"

namespace Cori {

enum TrainerType {
    Item,
    Tool,
    Supporter,
    Stadium
};

class TrainerCard : public DataCard {
protected:
    const TrainerType mTrainerType {};
public:
    constexpr TrainerCard(const std::string_view name, const TrainerType trainerType, 
        const std::string_view illustrator, const ExpansionID expansion, 
        const int cardNumber, const Rarity rarity)
    : DataCard(name, CardType::Trainer, illustrator, expansion, cardNumber, rarity)
    , mTrainerType { trainerType }
    {}
};

}