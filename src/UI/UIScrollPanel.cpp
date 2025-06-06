#include "UIScrollPanel.h"
#include "../Input/MouseManager.h"
#include <cmath>

namespace Cori {

UIScrollPanel::UIScrollPanel(float width, float height, float scrollerWidth, float scrollerHeight)
: UIScrollPanel(0.0f, 0.0f, width, height, scrollerWidth, scrollerHeight)
{}

UIScrollPanel::UIScrollPanel(float x, float y, float width, float height, float scrollerWidth, float scrollerHeight)
: UIPanel(x, y, width, height)
, mScrollBar { x + width - scrollerWidth, y, scrollerWidth, scrollerHeight, height }
{
    //mScrollBar.createClickFunction([](){});
}

void UIScrollPanel::offsetElements(float xOffset, float yOffset) {
    for(auto* element : mPanelElements)
        element->offsetFromOrigin(xOffset, yOffset);
}
void UIScrollPanel::updateScrollOffset() {
    if(mScrollOffset != mScrollBar.getY()) {
        mScrollOffset = mScrollBar.getY();
        // Scale Scroll Offset by Content Height
        offsetElements(0.0f, -mScrollOffset / (mHeight / mContentHeight));
    }
}

// Check if Mouse Clicked Outside of Panel
void mouseCheck(bool clickedOut, bool onOff) {
    if(clickedOut)
        gMouseManager.setMouseButtonReleased(sf::Mouse::Button::Left, onOff);
}

void UIScrollPanel::update() {
    gMouseManager.setInView(mPanelView);
    bool mouseClickOutOfPanel {
        gMouseManager.getMouseButtonReleased(sf::Mouse::Button::Left) &&
        !inBounds(gMouseManager.getMousePosition())
    };
    mouseCheck(mouseClickOutOfPanel, false); // Turn Off Mouse Click

    updateElements();

    if(!mScrollbarHidden) {
        mScrollBar.update();
        updateScrollOffset();
    }

    mouseCheck(mouseClickOutOfPanel, true); // Turn Mouse Click Back On
    
    gMouseManager.setInView(false);
}

void UIScrollPanel::draw(sf::RenderWindow& window) {
    window.setView(mPanelView);

    drawElements(window);
    if(!mScrollbarHidden)
        mScrollBar.draw(window); // Draw ScrollBar within view, on top of all elements

    window.setView(window.getDefaultView());
}

void UIScrollPanel::calculateContentHeight() {
    double previousContentHeight = mContentHeight;

    float lowestElementPos {};
    for(UIElement* element : mPanelElements) {
        float elementBottom { element->getOriginY() + element->getHeight() };
        if(elementBottom > lowestElementPos)
            lowestElementPos = elementBottom;
    }
    mContentHeight = lowestElementPos;

    if(mContentHeight > mHeight && mScrollbarHidden)
        setScrollbarHidden(false);

    if(mContentHeight > previousContentHeight)
        mScrollBar.setPosition(mScrollBar.getX(), mScrollBar.getY() * (previousContentHeight / mContentHeight));
    mScrollBar.setBarHeight(mHeight * std::min(mHeight / mContentHeight, 1.0));

    if(mScrollBar.getY() + mScrollBar.getHeight() > mHeight)
        mScrollBar.setPosition(mScrollBar.getX(), mHeight - mScrollBar.getHeight());
}

void UIScrollPanel::addElement(UIElement* element) {
    UIPanel::addElement(element);
    calculateContentHeight();
}

void UIScrollPanel::setScrollOffset(float offsetPosition) {
    mScrollBar.setPosition(mScrollBar.getX(), std::min(ceil(offsetPosition * (mHeight / mContentHeight)), double(mHeight - mScrollBar.getHeight()))); 
    updateScrollOffset();
}

void UIScrollPanel::setScrollbarHidden(bool hidden) {
    mScrollbarHidden = hidden;
}

void UIScrollPanel::resetScrollbar() {
    setScrollOffset(0.0f);
}

float UIScrollPanel::getWidthMinusScrollbar() {
    float width {
        mScrollbarHidden ? mWidth
        : mWidth - mScrollBar.getWidth()
    };
    return width;
}

UIScrollBar& UIScrollPanel::getScrollbar() {
    return mScrollBar;
}

}