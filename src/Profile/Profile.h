#pragma once

#include "Collection.h"
#include "../Cards/Deck.h"
#include <SFML/Graphics.hpp>

namespace Cori {

struct Profile {
    sf::String username {};
    std::string password {};
    sf::Texture profilePicture {};

    Collection collection {};
    std::vector<Deck> decks {};

    // Wrapper Function;
    void addToCollection(Collection::CollectionEntry entry) {
        collection.addToCollection(entry);
    }
};

// Defined in Profile.cpp
extern Profile gCurrentProfile;
extern void loadProfile(Profile profile);

}