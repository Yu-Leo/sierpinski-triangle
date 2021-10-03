#include <random>
#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>

#include "Point.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int main() {
    
    std::srand(0);
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Sierpinsky triangle");
    window.clear(sf::Color::White);
    window.display();

    std::vector<Point> vertexes;
    for (int i = 0; i < 3; i++) {
        vertexes.push_back(Point(rand() % WINDOW_WIDTH, rand() % WINDOW_HEIGHT));
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        for (auto p : vertexes) {
            sf::CircleShape shape(5.0f);
            shape.setFillColor(sf::Color::Blue);
            shape.setPosition(sf::Vector2f(float(p.getX()), float(p.getY())));
            window.draw(shape);
        }
        window.display();

        sf::sleep(sf::milliseconds(80));
    }
    return 0;
}