#include "Profile.h"

namespace Cori {

Profile gCurrentProfile {};
std::vector<Profile> gProfileDB {};

void gLoadProfile(Profile profile) {
    gCurrentProfile = profile;
    gLoggedIn = true;
}

bool gLoggedIn { false };

}