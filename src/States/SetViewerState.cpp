#include "State.h"
#include "../UI/UIDropdown.h"

namespace Cori {

State gSetViewerState {};

void initSetViewerState() {
    UIDropdown* element = new UIDropdown(100.0f, 100.0f, 250.0f, 40.0f, "Select Expansion", 
        { "Base Set", "Jungle", "Fossil" });
    gSetViewerState.addUIElement(element);
}

}