#pragma once
#include <SFML/Graphics.hpp>


class Engine {
public:
    Engine(bool fullscreen, int screenWidth, int screenHeight, int frameRateLimit) {
        windowSettings.fullscreen = fullscreen;
        windowSettings.screenWidth = screenWidth;
        windowSettings.screenHeight = screenHeight;
        windowSettings.frameRateLimit = frameRateLimit;
        initialize();
    }

    void initialize() {
        sf::ContextSettings contextSettings;
        contextSettings.antialiasingLevel = 8; // Przyk³adowa ustawienie antyaliasingu

        if (windowSettings.fullscreen) {
            window.create(sf::VideoMode::getFullscreenModes()[0], "Tytu³ Okna", sf::Style::Fullscreen, contextSettings);
        } else {
            window.create(sf::VideoMode(windowSettings.screenWidth, windowSettings.screenHeight), "Tytu³ Okna", sf::Style::Default, contextSettings);
        }

        window.setFramerateLimit(windowSettings.frameRateLimit);
    }

    void run() {
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }

            // G³ówna logika gry i rysowanie

            window.clear();
            // Rysowanie obiektów gry
            window.display();
        }
    }

private:
    struct WindowSettings {
        bool fullscreen;
        int screenWidth;
        int screenHeight;
        int frameRateLimit;
    };

    sf::RenderWindow window;
    WindowSettings windowSettings;
};

