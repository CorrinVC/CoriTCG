#pragma once

#include "../UI/UIElement.h"
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
}

namespace SetFullView { // Full Expansion View State
extern State gSetFullViewState;
extern void initFullViewState();
}

}