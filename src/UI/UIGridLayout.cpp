#include "UIGridLayout.h"
#include "../DeletionProtection.h"

namespace Cori {

void UIGridLayout::setupPadding(float borderPadding, float innerPadding) {
    //mInnerPadding = innerPadding;
    mTopPadding = borderPadding;
    mBottomPadding = borderPadding;
    mLeftPadding = borderPadding;
    mRightPadding = borderPadding;

    mMaxVertPadding = innerPadding;
    mMaxHorizPadding = innerPadding;

    mVerticalInnerPadding = mMaxVertPadding;
    mHorizontalInnerPadding = mMaxHorizPadding;
}

UIGridLayout::UIGridLayout(float borderPadding, float innerPadding, float width, float height)
: UIElement(width, height)
//, mViewHeight { height }
//, mBorderPadding { borderPadding }
//, mMaxInnerPadding { innerPadding }
{
    setBackgroundColor(sf::Color::Transparent);
    setupPadding(borderPadding, innerPadding);
}

UIGridLayout::~UIGridLayout() {
    for(UIElement* element : mGridElements) {
        if(deletionProtectionContains(element)) continue;
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
    float padding { vertical ? mVerticalInnerPadding : mHorizontalInnerPadding };
    return ((elementSize / mScaleFactor) + padding);
}

sf::Vector2f UIGridLayout::getIndexedPosition(int index) {
    //int index { int(mGridElements.size()) };
    
    float xPosition { ((mWidth - elementSpacing() * mElementsPerLine + mHorizontalInnerPadding) / 2)
        + (index % mElementsPerLine) * elementSpacing() };
    float yPosition { mTopPadding + (index / mElementsPerLine) 
        * elementSpacing(true) };
    return { xPosition, yPosition };
}

void UIGridLayout::updateElementPositions() {
    for(int i { 0 }; i < int(mGridElements.size()); ++i)
        mGridElements[i]->setPosition(getIndexedPosition(i).x, getIndexedPosition(i).y);
}

void UIGridLayout::updateElementsPerLine() {
    mElementsPerLine = std::max(1, int((mWidth - mLeftPadding - mRightPadding) / elementSpacing()));
    
    updateElementPositions();
}

void UIGridLayout::updateLayoutHeight() {
    if(mGridElements.empty())
        mHeight = mRect.getSize().y;
    else
        mHeight = mGridElements.back()->getOriginY() + (mGridElements.back()->getHeight() / mScaleFactor) + mBottomPadding;
    mRect.setSize({ mWidth, mHeight });
}

void UIGridLayout::updateScale() {
    mVerticalInnerPadding = std::max(1.0f, mMaxVertPadding - (mScaleFactor - 1));
    mHorizontalInnerPadding = std::max(1.0f, mMaxHorizPadding - (mScaleFactor - 1));

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
        adjustElementSizes();
        updateElementsPerLine();
        updateLayoutHeight();
    }
}

void UIGridLayout::adjustElementSizes() {
    for(UIElement* element : mGridElements) {
        if(element->getWidth() > mWidth)
            element->setSize({ mWidth, element->getHeight() });
    }
}

void UIGridLayout::setBorderPadding(Direction direction, float value) {
    switch(direction) {
    case Top:
        mTopPadding = value;
        break;
    case Bottom:
        mBottomPadding = value;
        break;
    case Left:
        mLeftPadding = value;
        break;
    case Right:
        mRightPadding = value;
        break;
    default: break;
    }
}

void UIGridLayout::setInnerPadding(float value, bool vertical) {
    if(vertical) mMaxVertPadding = value;
    else mMaxHorizPadding = value;
}

std::vector<UIElement*>& UIGridLayout::getElements() {
    return mGridElements;
}

float UIGridLayout::getScaleFactor() {
    return mScaleFactor;
}

float UIGridLayout::getBorderPadding(Direction direction) {
    switch(direction) {
    case Top: return mTopPadding;
    case Bottom: return mBottomPadding;
    case Left: return mLeftPadding;
    case Right: return mRightPadding;
    default:break;
    }
    return 0.0f;
}

float UIGridLayout::getInnerPadding(bool vertical) {
    if(vertical)
        return mVerticalInnerPadding;
    else
        return mHorizontalInnerPadding;
}

}