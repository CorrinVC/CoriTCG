#pragma once

#include "../UI/UIElement.h"
#include <SFML/Graphics.hpp>
#include <vector>

namespace Cori {

class State {
protected:
    std::vector<UIElement*> mUIElements {};
public:    
    void update();
    void draw(sf::RenderWindow& window);

    void addUIElement(UIElement* e);
};

extern State* gCurrentState;
void gSetState(State& state);

namespace MainMenu {
extern State gMenuState;
extern void initMenuState();
}

namespace SetViewer {
extern State gSetViewerState;
extern void initSetViewerState();
}

}