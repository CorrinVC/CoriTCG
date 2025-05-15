//#define DEBUG

#ifdef DEBUG

#pragma once

#include "../Input/KeyboardManager.h"
#include <iostream>

namespace Cori {

namespace Debug {

struct DebugCommand {
    std::string name;

    std::function<void(std::string[])> function;

    void execute(std::string params[]) {
        function(params);
    }
};

void executeCommand(DebugCommand command, std::string_view params) {

}

void parseCommand(std::string_view input) {
    size_t splitIndex { input.find(' ') };
    std::string mainCommand { input.substr(0, splitIndex) };

    DebugCommand command {};

    if(mainCommand == "say")
        return;

    executeCommand(command, input.substr(splitIndex + 1));
}

void update() {
    if(gKeyboardManager.keyReleased(sf::Keyboard::Key::Slash)) {
        std::cout << '/';
        std::string command {};
        std::getline(std::cin >> std::ws, command);
        parseCommand(command);
    }
}

}

}

#endif