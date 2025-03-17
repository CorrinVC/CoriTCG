#include "UIGridLayout.h"

namespace Cori {

UIGridLayout::UIGridLayout(float borderPadding, float innerPadding, float width, float height)
: UIElement(width, height)
, mBorderPadding { borderPadding }
, mMaxInnerPadding { innerPadding }
{}

UIGridLayout::~UIGridLayout() {
    for(UIElement* element : mGridElements)
        delete element;
}

void UIGridLayout::update() {
    for(UIElement* element : mGridElements)
        element->update();
}

void UIGridLayout::draw(sf::RenderWindow& window) {
    for(UIElement* element : mGridElements) {
        if(inBounds({ element->getX(), element->getY() }) // Checks if Element Top Left is inBounds
            // Checks if Element Bottom Right is inBounds
            || inBounds({ element->getX() + element->getWidth() - 1, 
                          element->getY() + element->getHeight() - 1 })) {
            element->draw(window);
        }
    }
}

UIElement* UIGridLayout::widestElement() {
    UIElement* widest { mGridElements[0] };
    for(UIElement* element : mGridElements) {
        if(element->getWidth() > widest->getWidth())
            widest = element;
    }
    return widest;
}

UIElement* UIGridLayout::tallestElement() {
    UIElement* tallest { mGridElements[0] };
    for(UIElement* element : mGridElements) {
        if(element->getHeight() > tallest->getHeight())
            tallest = element;
    }
    return tallest;
}

float UIGridLayout::elementSpacing(bool vertical) {
    if(!mHasElements) return 0.0f;
    float elementSize { tallestElement()->getHeight() ? vertical : widestElement()->getWidth() };
    return (elementSize / mScaleFactor + mInnerPadding);
}

sf::Vector2f UIGridLayout::getIndexedPosition() {
    int index { int(mGridElements.size()) };
    
    float xPosition { ((gWindowWidth - elementSpacing() * mElementsPerLine + mInnerPadding) / 2)
        + (index % mElementsPerLine) * elementSpacing() };
    float yPosition { mBorderPadding + (index / mElementsPerLine) 
        * elementSpacing(true) };
    
    return { xPosition, yPosition };
}

void UIGridLayout::updateElementsPerLine() {
    mElementsPerLine = int((gWindowWidth - mBorderPadding * 2) / elementSpacing());
    updateElementPositions();
}

void UIGridLayout::updateElementPositions() {
    for(UIElement* element : mGridElements)
        element->setPosition(getIndexedPosition().x, getIndexedPosition().y);
}

void UIGridLayout::updateScale() {
    mInnerPadding = std::max(1.0f, mMaxInnerPadding - mScaleFactor);
    updateElementsPerLine();
}

void UIGridLayout::addElement(UIElement* element) {
    if(mHasElements) {
        updateElementsPerLine();
        element->setPosition(getIndexedPosition().x, getIndexedPosition().y);
        element->setScale(1.0f / mScaleFactor);
    } else mHasElements = true;
    mGridElements.push_back(element);
}

void UIGridLayout::clearElements() {
    clearElements(int(mGridElements.size()));
}

void UIGridLayout::clearElements(int quantity) {
    assert(quantity <= int(mGridElements.size()) && "Clearing Too Many Elements from Grid Layout!");
    for(std::vector<UIElement*>::reverse_iterator elements = mGridElements.rbegin();
        elements != mGridElements.rbegin() + quantity ; elements++) {
        delete *(elements);
        mGridElements.pop_back();
    }
}

void UIGridLayout::setScale(float scaleFactor) {
    mScaleFactor = scaleFactor;
    if(mHasElements) updateScale();
}

}