#include <random>
#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>

#include "Point.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

const int N = 1000;

int main() {
    
    std::srand(0);
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Sierpinsky triangle");
    window.clear(sf::Color::White);
    window.display();

    std::vector<Point> vertexes;
    for (int i = 0; i < 3; i++) {
        vertexes.push_back(Point(rand() % WINDOW_WIDTH, rand() % WINDOW_HEIGHT));
    }

    std::vector<Point> points_list;

    int k = 0;
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (k < N) {
            points_list.push_back(Point(rand() % WINDOW_WIDTH, rand() % WINDOW_HEIGHT));
            k++;
        }

        window.clear(sf::Color::White);

        for (Point p : vertexes) {
            p.draw(window);
        }

        for (Point p : points_list) {
            p.draw(window);
        }

        window.display();

        sf::sleep(sf::milliseconds(80));
    }
    return 0;
}