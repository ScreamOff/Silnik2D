#include <SFML/Graphics.hpp>
#include <iostream>
#include "engine.h"

int main() {
    Engine engine;

    Rectangle* rect = new Rectangle(100, 100, 200, 100);
    Circle* circle = new Circle(300, 300, 50);

    engine.addPrimitive(rect);
    engine.addPrimitive(circle);

    engine.loadBitmap("image.png");

    engine.run();

    return 0;
}
