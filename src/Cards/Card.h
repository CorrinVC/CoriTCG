#pragma once

#include "ExpansionID.h"
#include <SFML/Graphics.hpp>
#include <iostream>
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
    None,
    HoloRare,
    Rare,
    Uncommon,
    Common
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

namespace Expansions {
    extern std::vector<std::string> gExpansionNames();
}

class DataCard {
public:
    // sf::String to display non-ASCII chars
    const sf::String mCardName {};
    const CardType mCardType {};

    // Possible Change - Refactor to sf::String
    const std::string mCardIllustrator {};

    const ExpansionID mExpansion;
    const int mCardNumber {};
    const Rarity mRarity {};

    const std::string mTexturePath {};
    const sf::Texture mTexture {};

    DataCard(const sf::String name, const CardType type, const std::string_view illustrator,
        const ExpansionID expansion, const int cardNumber, const Rarity rarity)
    : mCardName { name }
    , mCardType { type }
    , mCardIllustrator { illustrator }
    , mExpansion { expansion }
    , mCardNumber { cardNumber }
    , mRarity { rarity }
    , mTexturePath {
        std::format("res/cards/{}/{}{}.png",
            Expansions::getExpansionAbbreviation(expansion),
            Expansions::getExpansionLowerAbbreviation(expansion),
            cardNumber) 
    }
    , mTexture { mTexturePath }
    { }

    // For Logging?
    std::string cardNameString() {
        return mCardName.toAnsiString();
    }

    void print() {
        std::cout << Expansions::gExpansionNames()[mExpansion] << ' ' << cardNameString() 
            << " #" << mCardNumber << " (" << this << ')' << std::endl;
    }
};

//constexpr DataCard card {"Penis", CardType::Energy, "Bob", Expansions::base, 0, Rarity::None};

}