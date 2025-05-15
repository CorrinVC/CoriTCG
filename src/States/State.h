#pragma once

#include "../Profile/QuantityCard.h"
#include "../UI/UIElement.h"
#include <SFML/Graphics.hpp>
#include <stack>
#include <vector>

namespace Cori {

class State {
protected:
    std::vector<UIElement*> mUIElements {};
    std::function<void()> mOnSwitch { nullptr };
    std::function<void()> mOffSwitch { nullptr };
public:    
    ~State();

    void onSwitch();
    void offSwitch();

    void update();
    void draw(sf::RenderWindow& window);

    void addUIElement(UIElement* e);
    void popUIElement();

    void setOnSwitch(std::function<void()> func);
    void setOffSwitch(std::function<void()> func);

    std::vector<UIElement*> getElements();
};

// Global Current State Ptr
extern State* gCurrentState;
extern std::stack<State*> gPreviousStates;

void gSetState(State& state, bool addToPrevStack = true);
sf::Vector2f centeredCardPosition();

namespace MainMenu { // Main Menu State
extern State gMenuState;
extern void initMenuState();
}

namespace ProfileView { // Profile View State
extern State gProfileViewState;
extern void initProfileViewState();
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

namespace SavedDecks {
extern State gSavedDecksState;
extern void initSavedDecksState();
extern void updateDeckList();
}

namespace DeckViewer {
extern State gDeckViewerState;
extern void initDeckViewerState();
extern void setViewingDeck(int deckIndex);
}

namespace DeckBuilder { // Deck Builder State
extern State gDeckBuilderState;
extern void initDeckBuilderState();    
extern void addToDeck(QuantityCard& card);
extern void editDeck(int deckIndex);
}

}