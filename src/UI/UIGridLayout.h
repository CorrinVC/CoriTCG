#pragma once

#include "UIElement.h"
#include "../Window.h"
#include <SFML/Graphics.hpp>

namespace Cori {

class UIGridLayout: public UIElement {
protected:
    std::vector<UIElement*> mGridElements {};
    //float mViewHeight;

    float mBorderPadding;
    float mMaxInnerPadding;
    float mInnerPadding { mMaxInnerPadding };

    float mScaleFactor { 1.0f };
    int mElementsPerLine { 1 };

    UIElement* widestElement();
    UIElement* tallestElement();

    bool inBounds(const sf::Vector2f& position) override;
    float elementSpacing(bool vertical = false);
    sf::Vector2f getIndexedPosition(int index);

    void updateElementsPerLine();
    void updateElementPositions();
    void updateScale();
    void updateLayoutHeight();

public:
    UIGridLayout(float borderPadding = 0, float innerPadding = 0, float width = gWindowWidth, float height = gWindowHeight);
    ~UIGridLayout();

    void offsetFromOrigin(float xOffset, float yOffset) override;
    void update();
    void draw(sf::RenderWindow& window);

    void addElement(UIElement* element);
    void clearElements();
    void clearElements(int quantity);

    void setScale(float scaleFactor);

    std::vector<UIElement*>& getElements();

};

}