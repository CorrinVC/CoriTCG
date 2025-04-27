#pragma once

#include "../Profile/Collection.h"
#include "../UI/UIElement.h"
#include <SFML/Graphics.hpp>
#include <vector>

namespace Cori {

class State {
protected:
    std::vector<UIElement*> mUIElements {};
    std::function<void()> mOnSwitch { nullptr };
public:    
    ~State();

    void onSwitch();
    void update();
    void draw(sf::RenderWindow& window);

    void addUIElement(UIElement* e);
    void popUIElement();

    void setOnSwitch(std::function<void()> func);

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

namespace PackSimulator { // Pack Opening Simulator State
extern State gPackSimulatorState;
extern void initPackSimState();
}

namespace CollectionView { // Collection Showcase State
extern State gCollectionViewState;
extern void initCollectionViewState();
//extern void updateCollection();
}

namespace SavedDecksView { // TODO - Saved Decks, to have "New Deck" Button
extern State gSavedDecksState;
extern void initSavedDecksState();
}

namespace DeckBuilder { // Deck Builder State
extern State gDeckBuilderState;
extern void initDeckBuilderState();    
}

}