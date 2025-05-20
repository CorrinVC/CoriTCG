#include "Profile.h"
#include "../JSON.h"
#include "../States/State.h"

namespace Cori {

Profile gCurrentProfile {};
std::vector<Profile> gProfileDB {};

void Profile::loadDecksFromFileData(nlohmann::ordered_json& data) {
    for(auto& deck : data.items()) {
        DeckList deckList {};
        deckList.setName(deck.key());
        for(auto entry : deck.value()) {
            ExpansionID expID { ExpansionID(entry[0]) };
            std::size_t cardNum { entry[1] };

            DataCard* card { Expansions::gExpansionList[expID]->cards[cardNum - 1] };
            for(std::size_t i { 0 }; i < entry[2]; ++i)
                deckList.addCard(card);
        }
        decks.push_back(deckList);
    }
}

std::size_t gFindProfileIndex(Profile profile) {
    std::size_t index {};
    for(Profile p : gProfileDB) {
        if(p.username == profile.username && p.password == profile.password) break;
        ++index;
    }
    return index;
}

void gUpdateProfileDB() {
    std::size_t index { gFindProfileIndex(gCurrentProfile) };
    gProfileDB[index] = gCurrentProfile;
    gSaveProfiles();
}

void gUpdateUsername(sf::String username) {
    std::size_t index { gFindProfileIndex(gCurrentProfile) };
    gCurrentProfile.username = username;
    gProfileDB[index] = gCurrentProfile;
}

void gUpdatePassword(sf::String password) {
    std::size_t index { gFindProfileIndex(gCurrentProfile) };
    gCurrentProfile.password = password;
    gProfileDB[index] = gCurrentProfile;
}

void gLoadProfile(Profile profile) {
    gCurrentProfile = profile;
    gLoggedIn = true;
}

void gLogout() {
    gCurrentProfile = Profile();
    gLoggedIn = false;
}

bool gLoggedIn { false };

void gLoadSavedProfiles() {
    for(auto d : JSON::read("profiles.json")) {
        Profile p {
            d["username"].template get<std::string>(), 
            d["password"].template get<std::string>(), 
            d["profilePicture"].template get<std::string>()
        };
        std::cout << "Loaded " << p.username.toAnsiString() << " Profile" << std::endl;
        p.collection.loadFromFileData(d["collection"]);
        std::cout << "Loaded " << p.username.toAnsiString() << " Collection" << std::endl;
        p.loadDecksFromFileData(d["decks"]);
        std::cout << "Loaded " << p.username.toAnsiString() << " Decks" << std::endl;

        gProfileDB.push_back(p);
    }
    for(Profile p : gProfileDB) p.print();
}

void gSaveProfiles() {
    std::cout << "Saving Profiles" << std::endl;
    nlohmann::ordered_json data;
    std::size_t userID {};
    for(Profile p : gProfileDB) {
        std::string idString { std::format("{}", userID++) };
        data[idString] = {
            {"username", p.username},
            {"password", p.password},
            {"profilePicture", p.pfpFilePath}
        };
        p.saveCollection(data[idString]);
        for(DeckList d : p.decks)
            d.saveDecklist(data[idString]["decks"]);
    }
    JSON::write(data, "profiles.json");
}

}