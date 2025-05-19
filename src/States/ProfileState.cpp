#include "State.h"
#include "../Window.h"
#include "../Profile/Profile.h"
#include "../UI/UIButton.h"
#include "../UI/UIProfilePicture.h"
#include "../UI/UITextbox.h"

namespace Cori { namespace ProfileView {

State gProfileViewState {};

// UI Elements

UITextbox* usernameBox;
UIProfilePicture* profilePicture;

UIButton* backButton;
UIButton* collectionButton;
UIButton* decksButton;
UIButton* logoutButton;

void initUsernameBox() {
    usernameBox = new UITextbox(
        gWindowWidth / 2.0f - 150.0f, 100.0f, 300.0f, 75.0f,
        gCurrentProfile.username, true);
    usernameBox->centerText();
}

void initProfilePicture() {
    profilePicture = new UIProfilePicture(&gCurrentProfile.profilePicture, gWindowWidth / 2.0f - 150.0f, 200.0f);
    
    profilePicture->createClickFunction([]() {
        gSetState(PFPSelection::gPFPSelectionState);
    });
}

void initCollectionButton() {
    collectionButton = new UIButton(gWindowWidth / 2.0f - 125.0f, gWindowHeight / 2.0f + 25.0f, 100.0f, 50.0f);
    collectionButton->setText("Collection");
    collectionButton->centerButtonText();

    collectionButton->createClickFunction([]() {
        gSetState(CollectionView::gCollectionViewState);
    });
}

void initDecksButton() {
    decksButton = new UIButton(gWindowWidth / 2.0f + 25.0f, gWindowHeight / 2.0f + 25.0f, 100.0f, 50.0f);
    decksButton->setText("Decks");
    decksButton->centerButtonText();

    decksButton->createClickFunction([]() {
        gSetState(SavedDecks::gSavedDecksState);
    });
}

void initLogoutButton() {
    logoutButton = new UIButton(75.0f, 50.0f);
    logoutButton->setPositionRelativeTo(UIElement::ScreenTopRight, -50.0f, 50.0f);
    logoutButton->setText("Log Out");
    logoutButton->centerButtonText();

    logoutButton->createClickFunction([=]() {
        gLogout();
        gSetState(MainMenu::gMenuState);
    });
}

void addElements() {
    gProfileViewState.addUIElement(usernameBox);
    gProfileViewState.addUIElement(profilePicture);
    gProfileViewState.addUIElement(backButton);
    gProfileViewState.addUIElement(collectionButton);
    gProfileViewState.addUIElement(decksButton);
    gProfileViewState.addUIElement(logoutButton);
}

void initProfileViewState() {
    gProfileViewState.setOnSwitch([=](){
        usernameBox->setText(gCurrentProfile.username);
        profilePicture->changeTexture(&gCurrentProfile.profilePicture);
    });
    
    initUsernameBox();
    initProfilePicture();

    backButton = new BackButton(50.0f, 50.0f, 50.0f, 50.0f);
    initCollectionButton();
    initDecksButton();
    initLogoutButton();

    addElements();
}

}}