#include "UIGridLayout.h"

namespace Cori {

UIGridLayout::UIGridLayout(float borderPadding, float innerPadding, float width, float height)
: UIElement(width, height)
//, mViewHeight { height }
, mBorderPadding { borderPadding }
, mMaxInnerPadding { innerPadding }
{
    setBackgroundColor(sf::Color::Transparent);
}

UIGridLayout::~UIGridLayout() {
    for(UIElement* element : mGridElements) {
        delete element;
        element = NULL;
    }
}

bool UIGridLayout::inBounds(const sf::Vector2f& position) {
    return {
        (position.x >= getX() && position.x <= getX() + mWidth)
        && (position.y >= mOriginY && position.y <= mOriginY + mRect.getSize().y)
    };
}

void UIGridLayout::offsetFromOrigin(float xOffset, float yOffset) {
    for(UIElement* element : mGridElements)
        element->offsetFromOrigin(xOffset, yOffset);
}

void UIGridLayout::update() {
    for(UIElement* element : mGridElements)
        element->update();
}

void UIGridLayout::draw(sf::RenderWindow& window) {
    window.draw(mRect);

    for(UIElement* element : mGridElements) {
        if(inBounds({ element->getX(), element->getY() }) // Checks if Element Top Left is inBounds
            // Checks if Element Bottom Right is inBounds
            || inBounds({ element->getX() + (element->getWidth() / mScaleFactor) - 1, 
                          element->getY() + (element->getHeight() / mScaleFactor) - 1 })) {
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
    //std::cout << widest->getWidth() << std::endl;
    return widest;
}

UIElement* UIGridLayout::tallestElement() {
    UIElement* tallest { mGridElements[0] };
    for(UIElement* element : mGridElements) {
        if(element->getHeight() > tallest->getHeight())
            tallest = element;
    }
    //std::cout << tallest->getHeight() << std::endl;
    return tallest;
}

float UIGridLayout::elementSpacing(bool vertical) {
    float elementSize { vertical ? tallestElement()->getHeight() : widestElement()->getWidth() };
    //std::cout << elementSize << std::endl;
    return ((elementSize / mScaleFactor) + mInnerPadding);
}

sf::Vector2f UIGridLayout::getIndexedPosition(int index) {
    //int index { int(mGridElements.size()) };
    
    float xPosition { ((mWidth - elementSpacing() * mElementsPerLine + mInnerPadding) / 2)
        + (index % mElementsPerLine) * elementSpacing() };
    float yPosition { mBorderPadding + (index / mElementsPerLine) 
        * elementSpacing(true) };
    if(mGridElements.size() == 102) {
        //std::cout << "((" << gWindowWidth << '-' << elementSpacing() << '*' << mElementsPerLine << '+' << mInnerPadding << ")/2)+(" << index << '%' << mElementsPerLine << ")*" << elementSpacing() << " = " << xPosition << std::endl;
        //std::cout << mBorderPadding << "+(" << index << '/' << mElementsPerLine << ")*" << elementSpacing(true) << " = " << yPosition << '\n' << std::endl;
    }
    return { xPosition, yPosition };
}

void UIGridLayout::updateElementPositions() {
    for(int i { 0 }; i < int(mGridElements.size()); ++i)
        mGridElements[i]->setPosition(getIndexedPosition(i).x, getIndexedPosition(i).y);
}

void UIGridLayout::updateElementsPerLine() {
    mElementsPerLine = int((mWidth - mBorderPadding * 2) / elementSpacing());
    
    updateElementPositions();
}

void UIGridLayout::updateLayoutHeight() {
    if(mGridElements.empty())
        mHeight = mRect.getSize().y;
    else
        mHeight = mGridElements.back()->getOriginY() + (mGridElements.back()->getHeight() / mScaleFactor) + mBorderPadding;
}

void UIGridLayout::updateScale() {
    mInnerPadding = std::max(1.0f, mMaxInnerPadding - mScaleFactor);
    for(UIElement* element: mGridElements)
        element->setScale(1.0f / mScaleFactor);
        
    updateElementsPerLine();
    updateLayoutHeight();
}

void UIGridLayout::addElement(UIElement* element) {
    mGridElements.push_back(element);
    updateScale();
}

void UIGridLayout::clearElements() {
    clearElements(int(mGridElements.size()));
}

void UIGridLayout::clearElements(int quantity) {
    assert(quantity <= int(mGridElements.size()) && "Clearing Too Many Elements from Grid Layout!");
    for(int i { 0 }; i < quantity; ++i) {
        delete mGridElements.back();
        mGridElements.pop_back();
    }
    updateLayoutHeight();
}

void UIGridLayout::setScale(float scaleFactor) {
    mScaleFactor = scaleFactor;
    if(mGridElements.size() > 0)
        updateScale();
}

void UIGridLayout::setSize(const sf::Vector2f& size) {
    UIElement::setSize(size);
    if(mGridElements.size() > 0) {
        updateElementsPerLine();
        updateLayoutHeight();
    }
}

std::vector<UIElement*>& UIGridLayout::getElements() {
    return mGridElements;
}

}