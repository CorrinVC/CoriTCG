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

bool isSigningUp {};

void clearFields() {
    usernameField->flushTextInput();
    passwordField->flushTextInput();
}

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
    instructText->setText("Incorrect Username or Password");
    instructText->centerText();
}

void validateLogin() {
    std::size_t index { gFindProfileIndex({ usernameField->getTextInput(), passwordField->getTextInput() }) };
    if(index != gProfileDB.size()) {
        gLoadProfile(gProfileDB[index]);
        gSetState(ProfileView::gProfileViewState, false);
    } else loginFailed();

    clearFields();
}

void initConfirmButton() {
    confirmButton = new UIButton(100.0f, 50.0f);
    confirmButton->setPositionRelativeTo(UIElement::ScreenCenter, 0.0f, 75.0f);

    confirmButton->createClickFunction([=]() {
        if(isSigningUp) {
            gLoadProfile({ usernameField->flushTextInput(), passwordField->flushTextInput() });
            isSigningUp = false;
            gProfileDB.push_back({gCurrentProfile});
            gSetState(PFPSelection::gPFPSelectionState, false);
        }
        else validateLogin();
    });
}

void addElements() {
    gLoginState.addUIElement(instructText);
    gLoginState.addUIElement(usernameField);
    gLoginState.addUIElement(passwordField);
    gLoginState.addUIElement(confirmButton);
    gLoginState.addUIElement(backButton);
}

void initLoginState() {
    isSigningUp = gProfileDB.empty();

    gLoginState.setOnSwitch([=]() {
        clearFields();
        if(isSigningUp) switchSignUp();
        else switchLogin();
    });

    instructText = new UITextbox(gWindowWidth / 2.0f - 75.0f, gWindowHeight / 2.0f - 175.0f, 150.0f, 50.0f, "", true);
    initTextFields();
    initConfirmButton();
    backButton = new BackButton(25.0f, 25.0f, 50.0f, 50.0f);

    addElements();
}

}}