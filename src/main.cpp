
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
    Cori::MainMenu::initMenuState();
    Cori::ProfileView::initProfileViewState();
    Cori::Login::initLoginState();
    Cori::PFPSelection::initPFPSelectionState();
    Cori::SetViewer::initSetViewerState();
    Cori::SetFullView::initFullViewState();
    Cori::PackSimulator::initPackSimState();
    Cori::CollectionView::initCollectionViewState();
    Cori::SavedDecks::initSavedDecksState();
    Cori::DeckBuilder::initDeckBuilderState();
    Cori::DeckViewer::initDeckViewerState();

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