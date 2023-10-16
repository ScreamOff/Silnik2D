#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <fstream>
#include <iostream>
#include <string>

class Engine {
public:
    Engine(int width, int height, const std::string& title, int frameRate, bool enableMouse, bool enableKeyboard)
        : enableMouse(enableMouse), enableKeyboard(enableKeyboard) {
        window.create(sf::VideoMode(width, height), title);
        window.setFramerateLimit(frameRate);
        running = true;
    }

    void run() {
        sf::Clock clock;

        while (running) {
            sf::Event event;
            while (window.pollEvent(event)) {
                handleEvent(event);
            }

            float deltaTime = clock.restart().asSeconds();

            update(deltaTime);

            window.clear(sf::Color::Black);
            render();

            window.display();
        }
    }

    void handleEvent(sf::Event& event) {
        if (event.type == sf::Event::Closed) {
            running = false;
        }

        if (enableKeyboard) {
            // Obsługa klawiatury
        }

        if (enableMouse) {
            // Obsługa myszki
        }
    }

    void update(float deltaTime) {
        // Aktualizacja logiki gry
    }

    void render() {
        // Rysowanie elementów gry
    }

    void saveToLog(const std::string& message) {
        std::ofstream logFile("log.txt", std::ios::app);
        if (logFile.is_open()) {
            logFile << message << std::endl;
            logFile.close();
        }
    }

    void handleErrors(const std::string& errorMessage) {
        std::cerr << errorMessage << std::endl;
        saveToLog(errorMessage);
    }

private:
    sf::RenderWindow window;
    bool running;
    bool enableMouse;
    bool enableKeyboard;
};
