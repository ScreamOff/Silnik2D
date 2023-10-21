#include <SFML/Graphics.hpp>
#include <vector>

class Point2D {
public:
    float x;
    float y;
};

class Primitive {
public:
    virtual void draw(sf::RenderWindow& window) = 0;
    virtual void fill(sf::Color color) = 0;
    virtual void transform() = 0;
};

class Rectangle : public Primitive {
public:
    Point2D position;
    float width;
    float height;
    sf::RectangleShape shape;

    Rectangle(float x, float y, float w, float h) : position({x, y}), width(w), height(h) {
        shape.setPosition(sf::Vector2f(x, y));
        shape.setSize(sf::Vector2f(w, h));
    }

    void draw(sf::RenderWindow& window) override {
        window.draw(shape);
    }

    void fill(sf::Color color) override {
        shape.setFillColor(color);
    }

    void transform() override {
        // Implementacja przekształceń geometrycznych prostokąta
    }
};

class Circle : public Primitive {
public:
    Point2D center;
    float radius;
    sf::CircleShape shape;

    Circle(float x, float y, float r) : center({x, y}), radius(r) {
        shape.setPosition(sf::Vector2f(x - r, y - r));
        shape.setRadius(r);
    }

    void draw(sf::RenderWindow& window) override {
        window.draw(shape);
    }

    void fill(sf::Color color) override {
        shape.setFillColor(color);
    }

    void transform() override {
        // Implementacja przekształceń geometrycznych okręgu
    }
};

class Line : public Primitive {
public:
    Point2D start;
    Point2D end;
    sf::RectangleShape shape;

    Line(float x1, float y1, float x2, float y2) : start({ x1, y1 }), end({ x2, y2 }) {
        float length = std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
        float angle = std::atan2(y2 - y1, x2 - x1) * 180 / 3.14159265;

        shape.setPosition(x1, y1);
        shape.setSize(sf::Vector2f(length, 2)); // Grubość linii to 2 piksele
        shape.setRotation(angle);
    }

    void draw(sf::RenderWindow& window) override {
        window.draw(shape);
    }

    void fill(sf::Color color) override {
        shape.setFillColor(color);
    }

    void transform() override {
        // Nie jest wymagane w przypadku rysowania linii
    }
};


class Bitmap {
public:
    sf::Texture texture;
    sf::Sprite sprite;

    Bitmap() {
        // Inicjalizacja bitmapy
    }

    void loadFromFile(const std::string& filename) {
        if (texture.loadFromFile(filename)) {
            sprite.setTexture(texture);
        }
    }

    void animate() {
        // Implementacja animowania bitmapy
    }
};

class Engine {
public:
    Engine() : window(sf::VideoMode(800, 600), "Silnik 2D") {
        mouseX = 0;
        mouseY = 0;
        font.loadFromFile("arial.ttf"); // Załaduj odpowiednią czcionkę
        text.setFont(font);
        text.setCharacterSize(16);
        text.setFillColor(sf::Color::White);
    }

    void run() {
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }

                // Obsługa klawiatury i myszy
                if (event.type == sf::Event::MouseMoved) {
                    mouseX = event.mouseMove.x;
                    mouseY = event.mouseMove.y;
                }
            }

            window.clear();

            // Rysowanie i aktualizacja obiektów
            for (auto primitive : primitives) {
                primitive->fill(sf::Color::Blue);
                primitive->transform();
                primitive->draw(window);
            }

            bitmap.animate();
            window.draw(bitmap.sprite);

            // Wyświetl koordynaty myszki w rogu okna
            std::string mouseCoordinates = "Mouse X: " + std::to_string(mouseX) + " Y: " + std::to_string(mouseY);
            text.setString(mouseCoordinates);
            window.draw(text);

            window.display();
        }
    }

    void addPrimitive(Primitive* primitive) {
        primitives.push_back(primitive);
    }

    void loadBitmap(const std::string& filename) {
        bitmap.loadFromFile(filename);
    }

private:
    sf::RenderWindow window;
    std::vector<Primitive*> primitives;
    Bitmap bitmap;
    int mouseX;
    int mouseY;
    sf::Font font;
    sf::Text text;
};

