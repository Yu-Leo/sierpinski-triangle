#include <SFML/Graphics.hpp>

#include "Point.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Sierpinsky triangle");
    
    Point p(100, 100);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::CircleShape shape(5.0f);
        shape.setFillColor(sf::Color::Blue);
        shape.setPosition(sf::Vector2f(float(p.getX()), float(p.getY())));


        window.clear(sf::Color::White);
        window.draw(shape);
        window.display();
    }

    return 0;
}