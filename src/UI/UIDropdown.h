#pragma once

#include "UIElement.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

namespace Cori {

// Defined in UIDropdown.cpp as ""
extern std::string gDefaultString;

class UIDropdown: public UIElement {
private:
    sf::Color mTextColor;
    bool mDroppedDown { false };

    bool inBounds(const sf::Vector2f& position) override;

    //Default dropdown text
    sf::Text mBaseText { gUIFont };
    std::string mBaseString;
    void initBaseText();

    //Dropdown arrow
    sf::Text mDownArrowText { gUIFont };
    void initDownArrow();
    
    //List of values in dropdown
    std::vector<std::string> mTextValues {};
    //List of sf::Text objects to draw text values
    std::vector<sf::Text> mSFTexts {};
    bool mTextCentered { false };

    void initTextValues(const std::vector<std::string>& values);
    int mSelectedIndex {}; // Dropdown selected index
    std::string mSelectedText { gDefaultString }; // Dropdown selected text

    // Drawable Boxes for Dropped Down Values
    std::vector<sf::RectangleShape> mDropdownRectangles {};
    void initDropdownRectangles(const std::vector<std::string>& values);

    void alignTextRects();
    void alignDropdownRects();

public:
    UIDropdown(float width, float height, const std::string& baseText,
        const std::vector<std::string>& values, const sf::Color& color = sf::Color::Red);
    UIDropdown(float x, float y, float width, float height, 
        const std::string& baseText, const std::vector<std::string>& values, 
        const sf::Color& color = sf::Color::Red);

    void onClick() override;
    void update();
    void draw(sf::RenderWindow& window);

    int getSelectedIndex();
    std::string& getSelectedText();

    void setSelectedIndex(int index);

    void alignText();
    void centerBaseText();
    void centerText();
};

}