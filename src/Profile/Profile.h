#pragma once

#include "Collection.h"
#include "DeckList.h"
#include "QuantityCard.h"
#include <SFML/Graphics.hpp>

namespace Cori {

struct Profile {
    sf::String username {};
    sf::String password {};
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
extern std::vector<Profile> gProfileDB;

extern void gLoadProfile(Profile profile);
extern bool gLoggedIn;

}