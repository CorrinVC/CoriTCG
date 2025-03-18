#pragma once

#include "UIElement.h"
#include <SFML/Graphics.hpp>
#include <vector>

namespace Cori {

class UIPanel: public UIElement {
protected:
    sf::View mPanelView;
    std::vector<UIElement*> mPanelElements {};

    // Helper Function For Subclasses
    void updateElements();
    void drawElements(sf::RenderWindow& window);
public:
    UIPanel(float width, float height);
    UIPanel(float x, float y, float width, float height);
    virtual ~UIPanel();

    virtual void update();
    virtual void draw(sf::RenderWindow& window);

    virtual void addElement(UIElement* element);

    sf::View& getView();
    std::vector<UIElement*>& getElements();
};

}