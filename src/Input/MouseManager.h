#pragma once

#include "../UI/UIElement.h"
#include <SFML/Graphics.hpp>
#include <iostream>

namespace Cori {

class MouseManager {
private:
    sf::RenderWindow* mWindow {};

    bool mInView { false };
    sf::View* mView {};

    UIElement* mPressedSlot { nullptr };

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

    // Pressed Slot
    void fillPressedSlot(UIElement* slot);
    void clearPressedSlot();
    bool pressSlotCleared();
    bool checkPressedSlot(UIElement* checked);

    // Input Setters
    void setMouseButtonPressed(sf::Mouse::Button button, bool pressed = true);
    void setMouseButtonReleased(sf::Mouse::Button button, bool released = true);

    // Input Getters
    sf::Vector2f getMousePosition();
    bool getMouseButtonPressed(sf::Mouse::Button button);
    bool getMouseButtonReleased(sf::Mouse::Button button);
};

// Global Mouse Manager
extern MouseManager gMouseManager;

}