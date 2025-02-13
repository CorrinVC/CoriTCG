//#include "Window.h"
#include "Window.h"

namespace Cori {

Window::Window(std::string_view title, int width, int height) 
: mTitle  { title }
, mWidth  { width }
, mHeight { height } 
, mWindow { sf::VideoMode({static_cast<unsigned int>(width), static_cast<unsigned int>(height)}), mTitle }
{ 
    Cori::MouseManager::setWindow(mWindow);
    menuState.init();
    setState(&menuState);
}

void Window::update() {
    // Poll Events
    while (const std::optional event = mWindow.pollEvent()) {
        if (event->is<sf::Event::Closed>())
            mWindow.close();
    }

    if(mCurrentState)
        mCurrentState->update();
}

void Window::draw() {
    mWindow.clear();

    if(mCurrentState) {
        mCurrentState->draw(mWindow);
        //std::cout << "Penis\n";
    }

    mWindow.display();
}

}