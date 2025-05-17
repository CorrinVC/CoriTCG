#include "State.h"
#include "../Window.h"
#include "../Profile/Profile.h"
#include "../UI/UIButton.h"
#include "../UI/UITextbox.h"
#include "../UI/UITextField.h"

namespace Cori { namespace Login {

State gLoginState {};

// UI Elements

UITextbox* instructText;
UITextField* usernameField;
UITextField* passwordField;
UIButton* confirmButton;

UIButton* backButton;

// Reference Variables;

bool isSigningUp { true };

void switchSignUp() {
    instructText->setText("Create a Username and Password");
    instructText->centerText();

    confirmButton->setText("Sign Up");
    confirmButton->centerButtonText();
}

void switchLogin() {
    instructText->setText("Enter your Login Info");
    instructText->centerText();

    confirmButton->setText("Log In");
    confirmButton->centerButtonText();
}

void initTextFields() {
    passwordField = new UITextField(gWindowWidth / 2.0f - 75.0f, gWindowHeight / 2.0f - 25.0f, 150.0f, 50.0f);
    
    usernameField = new UITextField(passwordField->getX(), passwordField->getY() - 75.0f, 150.0f, 50.0f);
}

void loginFailed()  {
    usernameField->flushTextInput();
    passwordField->flushTextInput();
    instructText->setText("Incorrect Username or Password");
    instructText->centerText();
}

void validateLogin() {
    for(Profile profile : gProfileDB) {
        if(usernameField->getTextInput() == profile.username
            && passwordField->getTextInput() == profile.password) {
                gLoadProfile(profile);
                gSetState(ProfileView::gProfileViewState, false);
        } else loginFailed();
    }
}

void initConfirmButton() {
    confirmButton = new UIButton(100.0f, 50.0f);
    confirmButton->setPositionRelativeTo(UIElement::ScreenCenter, 0.0f, 75.0f);

    confirmButton->createClickFunction([=]() {
        if(isSigningUp) {
            gLoadProfile({ usernameField->flushTextInput(), passwordField->flushTextInput() });
            gProfileDB.push_back({gCurrentProfile});
            isSigningUp = false;
            gSetState(ProfileView::gProfileViewState, false);
        }
        else validateLogin();
    });
}

void addElements() {
    gLoginState.addUIElement(usernameField);
    gLoginState.addUIElement(passwordField);
    gLoginState.addUIElement(confirmButton);
    gLoginState.addUIElement(backButton);
}

void initLoginState() {
    gLoginState.setOnSwitch([=]() {
        if(isSigningUp) switchSignUp();
        else switchLogin();
    });

    instructText = new UITextbox(gWindowWidth / 2.0f - 75.0f, gWindowHeight / 2.0f - 100.0f, 150.0f, 50.0f, "", true);
    initTextFields();
    initConfirmButton();
    backButton = new BackButton(25.0f, 25.0f, 50.0f, 50.0f);

    addElements();
}

}}