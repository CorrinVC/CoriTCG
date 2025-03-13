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
    void popUIElement();

    std::vector<UIElement*> getElements();
};

// Global Current State Ptr
extern State* gCurrentState;
void gSetState(State& state);
sf::Vector2f centeredCardPosition();

namespace MainMenu { // Main Menu State
extern State gMenuState;
extern void initMenuState();
}

namespace SetViewer { // Individual Card View State
extern State gSetViewerState;
extern void initSetViewerState();

extern void setSelectedCard(int cardID, int expansionID = 0);
}

namespace SetFullView { // Full Expansion View State
extern State gSetFullViewState;
extern void initFullViewState();
}

namespace PackSimulator {
extern State gPackSimulatorState;
extern void initPackSimState();
}

}