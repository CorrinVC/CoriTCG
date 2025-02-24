#pragma once

#include "ExpansionID.h"
#include <string>
#include <string_view>

namespace Cori {

constexpr float gCardWidth { 600.0f };
constexpr float gCardHeight { 825.0f };

enum CardType {
    Pokemon,
    Trainer,
    Energy
};
enum Rarity {
    HoloRare,
    Rare,
    Uncommon,
    Common,
    None
};
enum EnergyType {
    NoType,
    Grass,
    Fire,
    Water,
    Lightning,
    Psychic,
    Fighting,
    Colorless
};

class DataCard {
protected:
    const std::string mCardName {};
    const CardType mCardType {};

    const std::string mCardIllustrator {};

    const ExpansionID mExpansion;
    const int mCardNumber {};
    const Rarity mRarity {};
public:
    constexpr DataCard(const std::string_view name, const CardType type, const std::string_view illustrator,
        const ExpansionID expansion, const int cardNumber, const Rarity rarity)
    : mCardName { name }
    , mCardType { type }
    , mCardIllustrator { illustrator }
    , mExpansion { expansion }
    , mCardNumber { cardNumber }
    , mRarity { rarity }
    {}
    
    constexpr const std::string& getCardName() const {
        return mCardName;
    }
};

//constexpr DataCard card {"Penis", CardType::Energy, "Bob", Expansions::base, 0, Rarity::None};

}