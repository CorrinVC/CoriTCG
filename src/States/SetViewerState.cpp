#include "State.h"
#include "../UI/UIDropdown.h"
#include "../UI/UITextbox.h"
#include <iostream>

namespace Cori {

State gSetViewerState {};

void initSetViewerState() {
    UIDropdown* expansionDropdown = new UIDropdown(100.0f, 100.0f, 250.0f, 40.0f, "Select Expansion", 
        { "Base Set", "Jungle", "Fossil" });
    gSetViewerState.addUIElement(expansionDropdown);

    std::cout << expansionDropdown->mSelectedText << '\n';

    UITextbox* expansionTextbox = new UITextbox(200.0f, 40.0f, &(expansionDropdown->mSelectedText));
    gSetViewerState.addUIElement(expansionTextbox);
}

}