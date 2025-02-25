#pragma once

#include "UIElement.h"
#include <SFML/Graphics.hpp>
#include <vector>

namespace Cori {

class UIPanel: public UIElement {
protected:
    sf::View mPanelView;
    std::vector<UIElement*> mPanelElements {};

public:
    UIPanel(float width, float height);
    UIPanel(float x, float y, float width, float height);

    void update();
    void draw(sf::RenderWindow& window);

    void addElement(UIElement* element);

    sf::View& getView();
};

}