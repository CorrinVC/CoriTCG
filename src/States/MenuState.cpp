#include "MenuState.h"
#include <iostream>

namespace Cori {

void MenuState::init() {
    mButton.createClickFunction(
        []() {
            std::cout << "Penis\n";
        }
    );
}

}