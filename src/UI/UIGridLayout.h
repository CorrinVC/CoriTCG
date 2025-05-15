#pragma once

#include "UIElement.h"
#include "../Window.h"
#include <SFML/Graphics.hpp>

namespace Cori {

enum Direction {
    Top,
    Bottom,
    Left,
    Right,
};

class UIGridLayout: public UIElement {
protected:
    std::vector<UIElement*> mGridElements {};
    //float mViewHeight;

    //float mBorderPadding;
    float mTopPadding {};
    float mBottomPadding {};
    float mLeftPadding {};
    float mRightPadding {};

    float mMaxVertPadding {};
    float mMaxHorizPadding {};

    float mVerticalInnerPadding {};
    float mHorizontalInnerPadding {};
    //float mInnerPadding;

    float mScaleFactor { 1.0f };
    int mElementsPerLine { 1 };

    void setupPadding(float borderPadding, float innerPadding);

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
    UIGridLayout(float borderPadding = 0, float innerPadding = 0, float width = gWindowWidth, float height = 10.0f);
    ~UIGridLayout();

    void offsetFromOrigin(float xOffset, float yOffset) override;
    void update();
    void draw(sf::RenderWindow& window);

    void addElement(UIElement* element);
    void clearElements();
    void clearElements(int quantity);

    void setScale(float scaleFactor);
    void setSize(const sf::Vector2f& size) override;
    void adjustElementSizes();

    void setBorderPadding(Direction direction, float value);
    // Bool Vertical Automatically True
    void setInnerPadding(float value, bool vertical = true);

    std::vector<UIElement*>& getElements();
    float getScaleFactor();

    float getBorderPadding(Direction direction);
    float getInnerPadding(bool vertical);

};

}