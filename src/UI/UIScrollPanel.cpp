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

// Check if Mouse Clicked Outside of Panel
void mouseCheck(bool clickedOut, bool onOff) {
    if(clickedOut)
        gMouseManager.setMouseButtonReleased(sf::Mouse::Button::Left, onOff);
}
void UIScrollPanel::updateScrollOffset() {
    if(mScrollOffset != mScrollBar.getY()) {
        mScrollOffset = mScrollBar.getY();
        // Scale Scroll Offset by Content Height
        offsetElements(0.0f, -mScrollOffset / (mHeight / mContentHeight));
    }
}

void UIScrollPanel::update() {
    gMouseManager.setInView(mPanelView);
    bool mouseClickOutOfPanel {
        gMouseManager.getMouseButtonReleased(sf::Mouse::Button::Left) &&
        !inBounds(gMouseManager.getMousePosition())
    };
    mouseCheck(mouseClickOutOfPanel, false); // Turn Off Mouse Click

    mScrollBar.update();
    updateScrollOffset();

    updateElements();

    mouseCheck(mouseClickOutOfPanel, true); // Turn Mouse Click Back On
    gMouseManager.setInView(false);
}

void UIScrollPanel::draw(sf::RenderWindow& window) {
    window.setView(mPanelView);

    drawElements(window);
    mScrollBar.draw(window); // Draw ScrollBar within view, on top of all elements

    window.setView(window.getDefaultView());
}

void UIScrollPanel::calculateContentHeight() {
    double previousContentHeight = mContentHeight;

    mContentHeight = 
        mPanelElements.back()->getOriginY() +
        mPanelElements.back()->getHeight() +
        mInnerBorder;

    if(mContentHeight > previousContentHeight)
        mScrollBar.setPosition(mScrollBar.getX(), mScrollBar.getY() * (previousContentHeight / mContentHeight));
    mScrollBar.setBarHeight(mHeight * std::min(mHeight / mContentHeight, 1.0));

    if(mScrollBar.getY() + mScrollBar.getHeight() > mHeight)
        mScrollBar.setPosition(mScrollBar.getX(), mHeight - mScrollBar.getHeight());
}

void UIScrollPanel::setInnerBorder(float border) {
    mInnerBorder = border;
}

}