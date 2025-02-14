#include "MenuState.h"
#include <iostream>

namespace Cori {

void MenuState::init() {
    //TEMPORARY
    mButton.createClickFunction(
        []() {
            std::cout << "Penis\n";
        }
    );
}

}