#include "UIScrollPanel.h"
#include "../Input/MouseManager.h"

namespace Cori {

UIScrollPanel::UIScrollPanel(float width, float height, float scrollerWidth, float scrollerHeight)
: UIScrollPanel(0.0f, 0.0f, width, height, scrollerWidth, scrollerHeight)
{}

UIScrollPanel::UIScrollPanel(float x, float y, float width, float height, float scrollerWidth, float scrollerHeight)
: UIPanel(x, y, width, height)
, mScrollBar { scrollerWidth, scrollerHeight, height }
{}

void UIScrollPanel::offsetElements(float xOffset, float yOffset) {
    for(auto* element : mPanelElements)
        element->offsetFromOrigin(xOffset, yOffset);
}

void UIScrollPanel::update() {
    gMouseManager.setInView(mPanelView);

    mScrollBar.update();
    if(mScrollOffset != mScrollBar.getY()) {
        mScrollOffset = mScrollBar.getY();
        // Scale Scroll Offset by Content Height
        offsetElements(0.0f, -mScrollOffset / (mHeight / mContentHeight));
    }

    updateElements();
    gMouseManager.setInView(false);
}

void UIScrollPanel::draw(sf::RenderWindow& window) {
    window.setView(mPanelView);

    drawElements(window);
    mScrollBar.draw(window); // Draw ScrollBar within view, on top of all elements

    window.setView(window.getDefaultView());
}

void UIScrollPanel::calculateContentHeight() {
    mContentHeight = 
        mPanelElements.back()->getOriginY() +
        mPanelElements.back()->getHeight() +
        mInnerBorder;

    mScrollBar.setBarHeight(mHeight * std::min(mHeight / mContentHeight, 1.0));

    if(mScrollBar.getY() + mScrollBar.getHeight() > mHeight)
        mScrollBar.setPosition(mScrollBar.getX(), mHeight - mScrollBar.getHeight());
}

void UIScrollPanel::setInnerBorder(float border) {
    mInnerBorder = border;
}

}