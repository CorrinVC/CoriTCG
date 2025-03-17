#pragma once

#include "Collection.h"
#include <SFML/Graphics.hpp>

namespace Cori {

struct Profile {
    sf::String username {};
    std::string password {};
    sf::Texture profilePicture {};

    Collection collection {};

    // Wrapper Function;
    void addToCollection(Collection::CollectionEntry entry) {
        collection.addToCollection(entry);
    }
};

extern Profile gCurrentProfile;
extern void loadProfile(Profile profile);

}