
#include "DeletionProtection.h"
#include "Window.h"
#include "Profile/Profile.h"
#include "States/State.h"
#include "UI/CollectionLayout.h"

int main() {
    /*// Placeholder Profile
    Cori::gLoadProfile({
        "CoriVC", "", sf::Texture("res/cards/BS/bs3.png")
    });*/
    Cori::gLoadSavedProfiles();

    // Initialize States
    Cori::gInitStates();
    Cori::gCurrentState = &Cori::MainMenu::gMenuState;
    
    // Initialize Window
    Cori::Window window("CoriTCG", Cori::gWindowWidth, Cori::gWindowHeight);

    // "Game Loop"
    while(window.isOpen()) {

        window.update();
        window.draw();

    }

    Cori::cleanupMultiParentElements();

} 