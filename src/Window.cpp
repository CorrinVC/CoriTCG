#include "Window.h"
#include "Input/MouseManager.h"
#include "States/State.h"
#include <optional>

namespace Cori {

Window::Window(std::string_view title, int width, int height) 
: mTitle  { title }
, mWidth  { width }
, mHeight { height } 
, mWindow { sf::VideoMode({static_cast<unsigned int>(width), static_cast<unsigned int>(height)}), mTitle }
{
    // Initialize mouse manager
    gMouseManager.setWindow(mWindow);
}

void Window::update() {
    gMouseManager.update(); // Reset Mouse Input Flags

    // Poll Events
    while(const std::optional event = mWindow.pollEvent()) {
        // Window Closed Event
        if(event->is<sf::Event::Closed>())
            mWindow.close(); //Close Window
        // Mouse Pressed Event
        else if(const auto* buttonPressed = event->getIf<sf::Event::MouseButtonPressed>())
        {
            // Set Mouse Pressed Flag
            gMouseManager.setMouseButtonPressed(buttonPressed->button);
        }
        // Mouse Released Event
        else if(const auto* buttonReleased = event->getIf<sf::Event::MouseButtonReleased>())
        {
            // Set Mouse Left Released Flag
            gMouseManager.setMouseButtonReleased(buttonReleased->button);
        }
    }

    if(gCurrentState)
        gCurrentState->update();
}

void Window::draw() {
    mWindow.clear(sf::Color(60, 60, 60));

    if(gCurrentState)
        gCurrentState->draw(mWindow);

    mWindow.display();
}

// Getters
bool Window::isOpen() const { return mWindow.isOpen(); }
sf::RenderWindow& Window::getRenderWindow() { return mWindow; }

}