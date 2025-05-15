#include "Window.h"
#include "Debug/Debug.h"
#include "Input/KeyboardManager.h"
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

void pollEvent(const std::optional<sf::Event> event, sf::RenderWindow& window) {
    // Window Close Event
    if(event->is<sf::Event::Closed>())
        window.close();
    
    // Mouse Pressed Event
    else if(const auto* buttonPressed = event->getIf<sf::Event::MouseButtonPressed>())
        gMouseManager.setMouseButtonPressed(buttonPressed->button);
    
    // Mouse Released Event
    else if(const auto* buttonReleased = event->getIf<sf::Event::MouseButtonReleased>())
        gMouseManager.setMouseButtonReleased(buttonReleased->button);

    else if(const auto* textEntered = event->getIf<sf::Event::TextEntered>())
        if(gKeyboardManager.acceptingTextInput()) gKeyboardManager.appendInput(textEntered->unicode); else return;

    else if(const auto* keyReleased = event->getIf<sf::Event::KeyReleased>())
        gKeyboardManager.setKeyReleased(keyReleased->code);
}

void Window::update() {
    gMouseManager.update(); // Reset Mouse Input Flags
    gKeyboardManager.update();

    // Poll Events
    while(const std::optional event = mWindow.pollEvent()) {
        pollEvent(event, mWindow);
    }
#ifdef DEBUG
    Debug::update();
#endif

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