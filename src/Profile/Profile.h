#pragma once

#include "Collection.h"
#include "DeckList.h"
#include "QuantityCard.h"
#include <SFML/Graphics.hpp>

namespace Cori {

struct Profile {
    sf::String username {};
    sf::String password {};

    std::string pfpFilePath {};
    sf::Texture profilePicture() {
        return pfpFilePath != ""
            ? sf::Texture(pfpFilePath)
            : sf::Texture();
    };

    Collection collection {};
    std::vector<DeckList> decks {};

    // Wrapper Functions;
    void addToCollection(QuantityCard card) {
        collection.addToCollection(card);
    }

    void saveCollection(nlohmann::ordered_json& data) {
        collection.saveCollection(data);
    }

    void loadDecksFromFileData(nlohmann::ordered_json& data);

    void print() {
        std::cout << "Username: " << username.toAnsiString() << "\nPassowrd: " << password.toAnsiString() << "\nPFP File Path: " << pfpFilePath << std::endl;
        collection.printCollection();
    }
};

// Defined in Profile.cpp
extern Profile gCurrentProfile;
extern std::vector<Profile> gProfileDB;
extern std::size_t gFindProfileIndex(Profile profile);

extern void gUpdateProfileDB();
extern void gUpdateUsername(sf::String username);
extern void gUpdatePassword(sf::String password);

extern void gLoadProfile(Profile profile);
extern void gLogout();
extern bool gLoggedIn;

extern void gLoadSavedProfiles();
extern void gSaveProfiles();

}