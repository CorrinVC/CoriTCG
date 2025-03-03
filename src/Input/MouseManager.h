#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

namespace Cori {

class MouseManager {
private:
    sf::RenderWindow* mWindow {};

    bool mInView { false };
    sf::View* mView {};

    // Mouse Input Flags
    bool mMouseLeftPressed { false };
    bool mMouseLeftReleased { false };
    void resetFlags();

public:
    void update();

    // Sets Window for relative mouse position
    void setWindow(sf::RenderWindow& window);

    // View Control
    void setInView(bool inView = true);
    void setInView(sf::View& view);

    // Input Setters
    void setMouseButtonPressed(sf::Mouse::Button button);
    void setMouseButtonReleased(sf::Mouse::Button button);

    // Input Getters
    sf::Vector2f getMousePosition();
    bool getMouseButtonPressed(sf::Mouse::Button button);
    bool getMouseButtonReleased(sf::Mouse::Button button);
};

// Global Mouse Manager
extern MouseManager gMouseManager;

}