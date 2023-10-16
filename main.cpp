#include <SFML/Graphics.hpp>
#include <iostream>
#include "engine.h"

int main() {
    int screenWidth = 800;
    int screenHeight = 600;
    std::string windowTitle = "Moja Gra";
    int frameRate = 60;
    bool enableMouse = true;
    bool enableKeyboard = true;

    Engine engine(screenWidth, screenHeight, windowTitle, frameRate, enableMouse, enableKeyboard);

    try {
        engine.run();
    } catch (std::exception& e) {
        engine.handleErrors(e.what());
    }

    return 0;
}
