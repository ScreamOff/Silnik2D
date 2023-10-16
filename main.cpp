#include <SFML/Graphics.hpp>
#include <iostream>
#include "engine.h"

int main()
{
    Engine engine(false, 800, 600, 60);
    engine.run();
    return 0;
}
