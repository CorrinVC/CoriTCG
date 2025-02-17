#pragma once

#include "UIElement.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

namespace Cori {

class UIDropdown: public UIElement {
private:
    //List of values in dropdown
    sf::Text mDownArrowText { gUIFont };
    void initDownArrow();

    std::vector<std::string> mTextValues;
public:
    UIDropdown(float width, float height, std::vector<std::string> values);
    UIDropdown(float x, float y, float width, float height, std::vector<std::string> values);

    void onClick() override;
    void update();
    void draw(sf::RenderWindow& window);
};

}