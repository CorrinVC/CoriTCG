#include "Profile.h"

namespace Cori {

Profile gCurrentProfile {};

void loadProfile(Profile profile) {
    gCurrentProfile = profile;
}

}