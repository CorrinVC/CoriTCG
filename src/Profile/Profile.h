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
extern std::size_t gFindProfileIndex(Profile profile);
extern void gUpdateUsername(sf::String username);
extern void gUpdatePassword(sf::String password);
extern void gUpdatePFP(sf::Texture texture);

extern void gLoadProfile(Profile profile);
extern void gLogout();
extern bool gLoggedIn;

}