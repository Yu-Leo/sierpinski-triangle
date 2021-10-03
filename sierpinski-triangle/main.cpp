#include <random>
#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>

#include "Point.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

const int MAXIMUM_NUMBER_OF_POINTS = 1000;

std::vector<Point> generate_3_vertexes() {
    std::vector<Point> vertexes;
    for (int i = 0; i < 3; i++) {
        Point p(rand() % WINDOW_WIDTH, rand() % WINDOW_HEIGHT, Point::Type::VERTEX);
        vertexes.push_back(p);
    }
    return vertexes;
}

void draw_points_from_list(sf::RenderWindow& window, const std::vector<Point>& points_list) {
    for (Point p : points_list) {
        p.draw(window);
    }
}

int main() {
    std::srand(0);
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Sierpinsky triangle");
    window.clear(sf::Color::White);
    window.display();

    std::vector<Point> vertexes = generate_3_vertexes();
    std::vector<Point> points_list;

    int number_of_points = 0;
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (number_of_points < MAXIMUM_NUMBER_OF_POINTS) {
            points_list.push_back(Point(rand() % WINDOW_WIDTH, rand() % WINDOW_HEIGHT));
            number_of_points++;
        }

        window.clear(sf::Color::White);
        draw_points_from_list(window, vertexes);
        draw_points_from_list(window, points_list);

        window.display();

        sf::sleep(sf::milliseconds(10));
    }
    return 0;
}