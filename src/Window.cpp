#include "Window.h"
#include "Input/MouseManager.h"
#include <optional>

namespace Cori {

Window::Window(std::string_view title, int width, int height) 
: mTitle  { title }
, mWidth  { width }
, mHeight { height } 
, mWindow { sf::VideoMode({static_cast<unsigned int>(width), static_cast<unsigned int>(height)}), mTitle }
{
    //Initialize menu state 
    MouseManager::setWindow(mWindow);
    menuState.init();
    setState(&menuState);
}

void Window::update() {
    MouseManager::update();

    // Poll Events
    while (const std::optional event = mWindow.pollEvent()) {
        // Window Closed Event
        if (event->is<sf::Event::Closed>())
            mWindow.close();
        // Mouse Released Event
        else if (const auto* buttonReleased = event->getIf<sf::Event::MouseButtonReleased>())
        {
            if(buttonReleased->button == sf::Mouse::Button::Left) 
                MouseManager::mouseLeftReleased = true;
        }
    }

    if(mCurrentState)
        mCurrentState->update();
}

void Window::draw() {
    mWindow.clear();

    if(mCurrentState)
        mCurrentState->draw(mWindow);

    mWindow.display();
}

int Window::getWidth() const { return mWidth; }
int Window::getHeight() const { return mHeight; }
bool Window::isOpen() const { return mWindow.isOpen(); }
sf::RenderWindow& Window::getRenderWindow() { return mWindow; }

}