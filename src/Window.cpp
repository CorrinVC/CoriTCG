#include "Window.h"

namespace Cori {

Window::Window(std::string_view title, unsigned int width, unsigned int height) 
: mTitle  { title }
, mWidth  { width }
, mHeight { height } 

{
    //mTitle = title;
    //mWidth = width;
    //mHeight = height;
    mWindow = { sf::VideoMode({mWidth, mHeight}), mTitle };
}

void Window::update() {
    // Poll Events
    while (const std::optional event = mWindow.pollEvent()) {
        if (event->is<sf::Event::Closed>())
            mWindow.close();
    }


}

void Window::draw() {
    mWindow.clear();


    mWindow.display();
}

unsigned int Window::getWidth() const { return mWidth; }
unsigned int Window::getHeight() const { return mHeight; }

bool Window::isOpen() { return mWindow.isOpen(); }

}