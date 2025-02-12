//#include "Window.h"
#include "States/State.h"

namespace Cori {

Window::Window(std::string_view title, int width, int height) 
: mTitle  { title }
, mWidth  { width }
, mHeight { height } 
, mWindow { sf::VideoMode({static_cast<unsigned int>(width), static_cast<unsigned int>(height)}), mTitle }
{ 
    Cori::MouseManager::setWindow(mWindow);
    //Cori::State::setState(Cori::State {});
}

void Window::update() {
    // Poll Events
    while (const std::optional event = mWindow.pollEvent()) {
        if (event->is<sf::Event::Closed>())
            mWindow.close();
    }

    if(State::getState())
        (*State::getState()).update();
}

void Window::draw() {
    mWindow.clear();

    if(State::getState())
        (*State::getState()).draw(mWindow);

    mWindow.display();
}

}