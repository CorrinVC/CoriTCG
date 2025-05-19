#include "State.h"
#include "../Cards/Expansions/BaseSet.h"
#include "../Cards/Expansions/Jungle.h"
#include "../Profile/Profile.h"
#include "../UI/UIGridLayout.h"
#include "../UI/UIProfilePicture.h"
#include "../UI/UIScrollPanel.h"
#include "../UI/UITextbox.h"
#include <SFML/Graphics.hpp>

namespace Cori { namespace PFPSelection {

State gPFPSelectionState {};

// UIElements

UIScrollPanel* picPanel;
UIGridLayout* picGrid;
UITextbox* instructText;

// Reference Variables
std::vector<const sf::Texture*> profilePictures {
    &Expansions::BaseSet::_070ClefairyDoll->mTexture,
    &Expansions::BaseSet::_091Bill->mTexture,
    &Expansions::Jungle::_064PokéBall->mTexture,
    &Expansions::BaseSet::_088ProfessorOak->mTexture,
    &Expansions::BaseSet::_075Lass->mTexture,
    &Expansions::BaseSet::_073ImposterProfessorOak->mTexture
};

void initPicPanel() {
    picPanel = new UIScrollPanel(gWindowWidth, gWindowHeight - 80.0f);
    picPanel->setViewport(0.0f, 80.0f, 1.0f, gWindowHeight - 80.0f);
}

void initGridElements() {
    for(const sf::Texture* texture : profilePictures) {
        UIProfilePicture* pic = new UIProfilePicture(texture);
        pic->createClickFunction([=]() {
            gUpdatePFP(*texture);
            gSetState(ProfileView::gProfileViewState, false);
        });
        picGrid->addElement(pic);
    }
}

void initPicGrid() {
    picGrid = new UIGridLayout(10.0f, 10.0f);
    initGridElements();
    picPanel->addElement(picGrid);
}

void initInstructText() {
    instructText = new UITextbox(300.0f, 50.0f, "Select a Profile Picture", true);
    instructText->setPositionRelativeTo(UIElement::ScreenTop, 0.0f, 15.0f);
    instructText->centerText();
}

void addElements() {
    gPFPSelectionState.addUIElement(picPanel);
    gPFPSelectionState.addUIElement(instructText);
}

void initPFPSelectionState() {
    initPicPanel();
    initPicGrid();
    initInstructText();

    addElements();
}

}}