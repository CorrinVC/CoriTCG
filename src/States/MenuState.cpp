#include "State.h"
#include "../UI/UIButton.h"
#include <iostream>

namespace Cori {


State gMenuState {};

void initMenuState() {
    UIButton* testButton = new UIButton(100.0f, 100.f, 100.0f, 60.0f);
    testButton->createClickFunction(
        []() {
            std::cout << "Penis" << std::endl;
        }
    );
    testButton->setBackgroundColor(sf::Color::Cyan);
    testButton->setText("Play");
    testButton->setTextColor(sf::Color::Red);
    testButton->centerText();

    gMenuState.addUIElement(testButton);
}
    
/*void MenuState::init() {
    //TEMPORARY
    mButton.createClickFunction(
        []() {
            std::cout << "Penis\n";
        }
    );
}*/

}