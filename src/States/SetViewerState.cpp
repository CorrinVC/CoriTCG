#include "State.h"
#include "../Window.h"
#include "../Cards/Card.h"
#include "../UI/UIDropdown.h"
#include "../UI/UIImage.h"
#include "../UI/UIReferenceTextbox.h"
#include <format>

namespace Cori {

namespace SetViewer {

State gSetViewerState {};

constexpr sf::Vector2f centeredCardPosition() {
    return { 
        gWindowWidth / 2.0f - gCardWidth / 2.0f,
        gWindowHeight / 2.0f - gCardHeight / 2.0f
    };
}

int currentCardID { 0 }; //default to Card Back

void initSetViewerState() {
    UIImage* image = new UIImage(centeredCardPosition().x, centeredCardPosition().y, currentCardID > 0 ? std::format("res/cards/BS/bs{}.png", currentCardID) : "res/card-back.png");
    //image->setSize({ gCardWidth, gCardHeight });
    gSetViewerState.addUIElement(image);

    UIDropdown* expansionDropdown = new UIDropdown(centeredCardPosition().x, centeredCardPosition().y - 50.0f, 250.0f, 40.0f, "Select Expansion", 
        { "Base Set", "Jungle", "Fossil" });
    gSetViewerState.addUIElement(expansionDropdown);

    UIReferenceTextbox* expansionTextbox = new UIReferenceTextbox(200.0f, 40.0f, 
            &(expansionDropdown->getSelectedText()));
    expansionTextbox->centerText();
    gSetViewerState.addUIElement(expansionTextbox);
}

}

}