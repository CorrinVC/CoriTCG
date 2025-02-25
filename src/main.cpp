#include "Window.h"
#include "States/State.h"
//#include <SFML/Graphics.hpp>

int main() {
    //Initialize States
    Cori::MainMenu::initMenuState();
    Cori::SetViewer::initSetViewerState();
    Cori::SetFullView::initFullViewState();

    Cori::gSetState(Cori::MainMenu::gMenuState);
    //sf::RenderWindow window(sf::VideoMode({1200,900}), "CoriTCG");
    Cori::Window window("CoriTCG", Cori::gWindowWidth, Cori::gWindowHeight);

    while(window.isOpen()) {

        window.update();
        window.draw();

    }

} 