//#include "Window.h"
#include "States/State.h"

namespace Cori {

Window::Window(std::string_view title, int width, int height) 
: mTitle  { title }
, mWidth  { width }
, mHeight { height } 
, mWindow { sf::VideoMode({static_cast<unsigned int>(width), static_cast<unsigned int>(height)}), mTitle }
{ 
    Cori::MouseManager::setWindow(*this);
}

void Window::update() {
    // Poll Events
    while (const std::optional event = mWindow.pollEvent()) {
        if (event->is<sf::Event::Closed>())
            mWindow.close();
    }

    State::getState().update();
}

void Window::draw() {
    mWindow.clear();

    State::getState().draw(mWindow);

    mWindow.display();
}

}