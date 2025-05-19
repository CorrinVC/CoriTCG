#include "Profile.h"
#include "../JSON.h"

namespace Cori {

Profile gCurrentProfile {};
std::vector<Profile> gProfileDB {};

std::size_t gFindProfileIndex(Profile profile) {
    std::size_t index {};
    for(Profile p : gProfileDB) {
        if(p.username == profile.username && p.password == profile.password) break;
        ++index;
    }
    return index;
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

void gUpdatePFP(std::string texturePath) {
    std::size_t index { gFindProfileIndex(gCurrentProfile) };
    gCurrentProfile.pfpFilePath = texturePath;
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
        gProfileDB.push_back(p);
    }
    for(Profile p : gProfileDB) p.print();
}

void gSaveProfiles() {
    nlohmann::ordered_json data;
    std::size_t userID {};
    for(Profile p : gProfileDB) {
        data[std::format("{}", userID++)] = {
            {"username", p.username},
            {"password", p.password},
            {"profilePicture", p.pfpFilePath}
        };
    }
    JSON::write(data, "profiles.json");
}

}