#pragma once

#include "UIElement.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

namespace Cori {

extern std::string gDefaultString;

class UIDropdown: public UIElement {
private:
    sf::Color mTextColor;
    bool mDroppedDown { false };

    bool inBounds(const sf::Vector2i& position);

    //Default dropdown text
    sf::Text mBaseText { gUIFont };
    sf::Text mDownArrowText { gUIFont };
    void initBaseText(const std::string& text);
    void initDownArrow();
    
    //List of values in dropdown
    std::vector<std::string> mTextValues {};
    //List of sf::Text objects to draw text values
    std::vector<sf::Text> mSFTexts {};

    void initTextValues(const std::vector<std::string>& values);
    int mSelectedIndex {}; // Dropdown selected index

    std::vector<sf::RectangleShape> mDropdownRectangles {};
    void initDropdownRectangles(const std::vector<std::string>& values);

public:
    UIDropdown(float width, float height, const std::string& baseText, 
        const std::vector<std::string>& values, const sf::Color& color = sf::Color::Red);
    UIDropdown(float x, float y, float width, float height, 
        const std::string& baseText, const std::vector<std::string>& values, 
        const sf::Color& color = sf::Color::Red);

    std::string* mSelectedText { &gDefaultString };
    
    void onClick() override;
    void update();
    void draw(sf::RenderWindow& window);

    int getSelectedIndex();
    std::string* getSelectedText();
};

}