#include "Window.h"
//#include <SFML/Graphics.hpp>

int main() {
    //sf::RenderWindow window(sf::VideoMode({1200,900}), "CoriTCG");
    Cori::Window window("CoriTCG", Cori::gWindowWidth, Cori::gWindowHeight);

    while(window.isOpen()) {

        window.update();
        window.draw();

    }

} 