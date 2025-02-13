#pragma once

#include "../Input/MouseManager.h"
#include <functional>

namespace Cori {

class UIElement {
protected:
    float mX {}, mY {};
    float mWidth {}, mHeight {};

    sf::RectangleShape mRect {};

    std::function<void(void)> mClickFunc {};

    bool inBounds(const sf::Vector2i& position) {
        return (position.x >= mX && position.x <= mX + mWidth)
            && (position.y >= mY && position.y <= mY + mHeight);
    }

public:
    UIElement(float x, float y, float width, float height);

    void createClickFunction(std::function<void(void)> func) {
        mClickFunc = func;
    }
    void onClick() {
        if(mClickFunc) mClickFunc();
    }

    void update();
    void draw(sf::RenderWindow& window);
};

}