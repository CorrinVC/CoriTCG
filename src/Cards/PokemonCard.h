#pragma once

#include "Card.h"

namespace Cori {

enum Stage {
    Basic,
    Stage1,
    Stage2
};

// Name, HP, Type, Stage, Retreat, Illus., Exp., Card#, Rarity
class PokemonCard : public DataCard {
protected:
    const int mHP {};
    const EnergyType mEnergyType {};

    const Stage mStage {};
    std::string mEvolvesFrom {};

    EnergyType mWeakness {};
    EnergyType mResistance {};
    const int mRetreatCost {};
public:
    constexpr PokemonCard(const std::string_view name, const int hp, 
        const EnergyType energyType, const Stage stage, const int retreatCost, 
        const std::string_view illustrator, const ExpansionID expansion, 
        const int cardNumber, const Rarity rarity)
    : DataCard(name, CardType::Pokemon, illustrator, expansion, cardNumber, rarity)
    , mHP { hp }
    , mEnergyType { energyType }
    , mStage { stage }
    , mRetreatCost { retreatCost }
    {}

    constexpr PokemonCard& evolvesFrom(const std::string_view evolvesFrom) {
        mEvolvesFrom = evolvesFrom;
        return *this;
    }
    constexpr PokemonCard& weakTo(const EnergyType type) {
        mWeakness = type;
        return *this;
    }
    constexpr PokemonCard& resists(const EnergyType type) {
        mResistance = type;
        return *this;
    }
};


}