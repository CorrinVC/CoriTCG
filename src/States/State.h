#pragma once

#include "../UI/UIElement.h"
#include "../UI/UIButton.h"
#include "../UI/UIDropdown.h"
#include "../UI/UIImage.h"
#include "../UI/UITextbox.h"
#include <SFML/Graphics.hpp>
#include <vector>

namespace Cori {

class State {
protected:
    std::vector<UIElement*> mUIElements {};
public:    
    ~State();

    void update();
    void draw(sf::RenderWindow& window);

    void addUIElement(UIElement* e);
};

// Global Current State Ptr
extern State* gCurrentState;
void gSetState(State& state);

namespace MainMenu { // Main Menu State
extern State gMenuState;
extern void initMenuState();
}

namespace SetViewer { // Individual Card View State
extern State gSetViewerState;
extern void initSetViewerState();

extern int currentCardID;
extern int currentExpansionIndex;
extern void changeCardInfo();
// UI Elements
extern UIImage* mainCardDisplay;
extern UITextbox* currentCardTextbox;
extern UIDropdown* expansionDropdown;

extern UIButton* incrementButton;
extern UIButton* decrementButton;
}

namespace SetFullView { // Full Expansion View State
extern State gSetFullViewState;
extern void initFullViewState();
}

}