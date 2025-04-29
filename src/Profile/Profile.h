#pragma once

#include "Collection.h"
#include "QuantityCard.h"
#include "../Cards/DeckList.h"
#include <SFML/Graphics.hpp>

namespace Cori {

struct Profile {
    sf::String username {};
    std::string password {};
    sf::Texture profilePicture {};

    Collection collection {};
    std::vector<DeckList> decks {};

    // Wrapper Function;
    void addToCollection(QuantityCard card) {
        collection.addToCollection(card);
    }
};

// Defined in Profile.cpp
extern Profile gCurrentProfile;
extern void loadProfile(Profile profile);

}