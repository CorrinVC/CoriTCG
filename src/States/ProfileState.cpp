#include "State.h"
#include "../Window.h"
#include "../Profile/Profile.h"
#include "../UI/UIButton.h"
#include "../UI/UIImage.h"
#include "../UI/UITextbox.h"

namespace Cori { namespace ProfileView {

State gProfileViewState {};

// UI Elements

UITextbox* usernameBox;
UIImage* profilePicture;

UIButton* backButton;
UIButton* collectionButton;
UIButton* decksButton;

void initUsernameBox() {
    usernameBox = new UITextbox(
        gWindowWidth / 2.0f - 150.0f, 100.0f, 300.0f, 75.0f,
        gCurrentProfile.username, true);
    usernameBox->centerText();
}

void initProfilePicture() {
    profilePicture = new UIImage(gWindowWidth / 2.0f - 100.0f, 200.0f, gCurrentProfile.profilePicture);
    profilePicture->setSubImage(gCardWidth / 2.0f - 100.0f, 100.0f, 200.0f, 200.0f);
}

void initCollectionButton() {
    collectionButton = new UIButton(gWindowWidth / 2.0f - 125.0f, gWindowHeight / 2.0f, 100.0f, 50.0f);
    collectionButton->setText("Collection");
    collectionButton->centerButtonText();

    collectionButton->createClickFunction([]() {
        gSetState(CollectionView::gCollectionViewState);
    });
}

void initDecksButton() {
    decksButton = new UIButton(gWindowWidth / 2.0f + 25.0f, gWindowHeight / 2.0f, 100.0f, 50.0f);
    decksButton->setText("Decks");
    decksButton->centerButtonText();

    decksButton->createClickFunction([]() {
        gSetState(SavedDecks::gSavedDecksState);
    });
}

void addElements() {
    gProfileViewState.addUIElement(usernameBox);
    gProfileViewState.addUIElement(profilePicture);
    gProfileViewState.addUIElement(backButton);
    gProfileViewState.addUIElement(collectionButton);
    gProfileViewState.addUIElement(decksButton);
}

void initProfileViewState() {
    gProfileViewState.setOnSwitch([=](){
        usernameBox->setText(gCurrentProfile.username);
        profilePicture->changeTexture(gCurrentProfile.profilePicture);
        profilePicture->setSubImage(gCardWidth / 2.0f - 100.0f, 100.0f, 200.0f, 200.0f);
    });
    
    initUsernameBox();
    initProfilePicture();

    backButton = new BackButton(50.0f, 50.0f, 50.0f, 50.0f);
    initCollectionButton();
    initDecksButton();

    addElements();
}

}}