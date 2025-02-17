#pragma once

#include "UIElement.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

namespace Cori {

class UIDropdown: public UIElement {
private:
    sf::Color mTextColor;

    //Default dropdown text
    sf::Text mBaseText { gUIFont };
    sf::Text mDownArrowText { gUIFont };
    void initBaseText(const std::string& text);
    void initDownArrow();

    bool mDroppedDown { false };
    
    //List of values in dropdown
    std::vector<sf::Text> mTextValues {};
    void initTextValues(const std::vector<std::string>& values);
public:
    UIDropdown(float width, float height, const std::string& baseText, 
        const std::vector<std::string>& values, const sf::Color& color = sf::Color::Red);
    UIDropdown(float x, float y, float width, float height, 
        const std::string& baseText, const std::vector<std::string>& values, 
        const sf::Color& color = sf::Color::Red);

    void onClick() override;
    void update();
    void draw(sf::RenderWindow& window);
};

}