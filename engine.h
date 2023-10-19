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
    Engine() : window(sf::VideoMode(800, 600), "Silnik 2D") {}

    void run() {
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                // Obsługa klawiatury i myszy
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
};
