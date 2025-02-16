#pragma once

#include <SFML/Graphics.hpp>

namespace Cori {

class MouseManager {
private:
    sf::RenderWindow* sWindow {};

    // Mouse Input Flags
    bool mMouseLeftReleased { false };
    void resetFlags();

public:
    void update();

    // Sets Window for relative mouse position
    void setWindow(sf::RenderWindow& window);
    void setMouseButtonReleased(sf::Mouse::Button button);

    // Input Getters
    sf::Vector2i getMousePosition();
    bool getMouseButtonReleased(sf::Mouse::Button button);
};

// Global Mouse Manager
extern MouseManager gMouseManager;

}