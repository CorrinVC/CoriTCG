#include "Profile.h"

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

void gUpdatePFP(sf::Texture texture) {
    std::size_t index { gFindProfileIndex(gCurrentProfile) };
    gCurrentProfile.profilePicture = texture;
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

}