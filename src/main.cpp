#include "Window.h"
#include "States/State.h"

int main() {
    // Initialize States
    Cori::MainMenu::initMenuState();
    Cori::SetViewer::initSetViewerState();
    Cori::SetFullView::initFullViewState();
    Cori::PackSimulator::initPackSimState();
    Cori::CollectionView::initCollectionViewState();
    Cori::DeckBuilder::initDeckBuilderState();

    Cori::gSetState(Cori::MainMenu::gMenuState);
    
    // Initialize Window
    Cori::Window window("CoriTCG", Cori::gWindowWidth, Cori::gWindowHeight);

    // "Game Loop"
    while(window.isOpen()) {

        window.update();
        window.draw();

    }

} 