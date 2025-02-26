#include "UIScrollPanel.h"

namespace Cori {

UIScrollPanel::UIScrollPanel(float width, float height, UIScrollBar scrollBar)
: UIScrollPanel(0.0f, 0.0f, width, height, scrollBar)
{}

UIScrollPanel::UIScrollPanel(float x, float y, float width, float height, UIScrollBar scrollBar)
: UIPanel(x, y, width, height)
, mScrollBar { scrollBar }
{
    //addElement(mScrollBar);
}

void UIScrollPanel::offsetElements(float xOffset, float yOffset) {
    for(auto* element : mPanelElements)
        element->move(xOffset, yOffset);
}

void UIScrollPanel::draw(sf::RenderWindow& window) {
    window.setView(mPanelView);

    drawElements(window);
    mScrollBar.draw(window);

    window.setView(window.getDefaultView());
}

}