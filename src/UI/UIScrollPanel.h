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
    float mInnerBorder {};
public:
    UIScrollPanel(float width, float height, float scrollerWidth, float scrollerHeight);
    UIScrollPanel(float x, float y, float width, float height, float scrollerWidth, float scrollerHeight);

    void offsetElements(float xOffset, float yOffset);
    
    void update();
    void draw(sf::RenderWindow& window);

    void updateScrollOffset();
    void calculateContentHeight();

    void setInnerBorder(float border);
};

}