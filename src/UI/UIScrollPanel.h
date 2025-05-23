#pragma once

#include "UIPanel.h"
#include "UIScrollBar.h"
#include <SFML/Graphics.hpp>

namespace Cori {

class UIScrollPanel : public UIPanel {
private:
    UIScrollBar mScrollBar;

    double mContentHeight {};
    int mScrollOffset {};

    bool mScrollbarHidden { true };
public:
    UIScrollPanel(float width, float height, float scrollerWidth = 20.0f, float scrollerHeight = 50.0f);
    UIScrollPanel(float x, float y, float width, float height, float scrollerWidth, float scrollerHeight);

    void offsetElements(float xOffset, float yOffset);
    
    void update();
    void draw(sf::RenderWindow& window);

    void updateScrollOffset();
    void calculateContentHeight();

    void addElement(UIElement* element) override;

    void setScrollOffset(float offsetPosition);
    void setScrollbarHidden(bool hidden);
    void resetScrollbar();

    float getWidthMinusScrollbar();
    UIScrollBar& getScrollbar();
};

}