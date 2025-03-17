#pragma once

#include "UIElement.h"
#include "../Window.h"
#include <SFML/Graphics.hpp>

namespace Cori {

class UIGridLayout: public UIElement {
private:
    std::vector<UIElement*> mGridElements {};

    float mBorderPadding;
    float mMaxInnerPadding;
    float mInnerPadding { mMaxInnerPadding };


    float mScaleFactor { 1.0f };
    int mElementsPerLine { 1 };

    bool mHasElements { false };

    UIElement* widestElement();
    UIElement* tallestElement();
    float elementSpacing(bool vertical = false);
    sf::Vector2f getIndexedPosition();

    void updateElementsPerLine();
    void updateElementPositions();
    void updateScale();
public:
    UIGridLayout(float borderPadding = 0, float innerPadding = 0, float width = gWindowWidth, float height = gWindowHeight);
    ~UIGridLayout();

    void update();
    void draw(sf::RenderWindow& window);

    void addElement(UIElement* element);
    void clearElements();
    void clearElements(int quantity);

    void setScale(float scaleFactor);

    std::vector<UIElement*>& getElements();

};

}