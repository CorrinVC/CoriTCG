#include "State.h"
#include "../UI/UIDropdown.h"
#include "../UI/UIReferenceTextbox.h"

namespace Cori {

State gSetViewerState {};

void initSetViewerState() {
    UIDropdown* expansionDropdown = new UIDropdown(100.0f, 100.0f, 250.0f, 40.0f, "Select Expansion", 
        { "Base Set", "Jungle", "Fossil" });
    gSetViewerState.addUIElement(expansionDropdown);

    UIReferenceTextbox* expansionTextbox = new UIReferenceTextbox(200.0f, 40.0f, 
            &(expansionDropdown->getSelectedText()));
    expansionTextbox->centerText();
    gSetViewerState.addUIElement(expansionTextbox);
}

}