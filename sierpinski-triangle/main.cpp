#include <random>
#include <iostream>
#include <vector>
#include <ctime>

#include <SFML/Graphics.hpp>

#include "Dot.h"

#define RANDOM_GENERATING true // (true/false)

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

const int MAXIMUM_NUMBER_OF_POINTS = 10000;

std::vector<Dot> generate_3_vertexes() {
    std::vector<Dot> vertexes;
    /*
        Field:
        --------------------
        |   |    1    |    |
        |   |         |    |
        --------------------
        |    2   |    3    |
        |        |         |
        --------------------
        Points generates in this three zones.
    */
    
    Dot p1(WINDOW_WIDTH / 4 + rand() % (WINDOW_WIDTH / 2),
        rand() % (WINDOW_HEIGHT / 2), Dot::Type::VERTEX);

    Dot p2(rand() % (WINDOW_WIDTH / 2),
        (WINDOW_HEIGHT / 2) + rand() % (WINDOW_HEIGHT / 2), Dot::Type::VERTEX);

    Dot p3(WINDOW_WIDTH / 2 + rand() % (WINDOW_WIDTH / 2),
        (WINDOW_HEIGHT / 2) + rand() % (WINDOW_HEIGHT / 2), Dot::Type::VERTEX);

    vertexes.push_back(p1);
    vertexes.push_back(p2);
    vertexes.push_back(p3);

    return vertexes;
}

void draw_points_from_list(sf::RenderWindow& window, const std::vector<Dot>& points_list) {
    for (Dot p : points_list) {
        p.draw(window);
    }
}

void draw_zone_lines(sf::RenderWindow& window) {
    // Draw test lines for visualization zones.
    sf::Color color = sf::Color::Green;
    int thickness = 2;

    sf::RectangleShape line1(sf::Vector2f(WINDOW_WIDTH, thickness));
    line1.setPosition(0, WINDOW_HEIGHT / 2);
    line1.setFillColor(color);
    window.draw(line1);

    sf::RectangleShape line2(sf::Vector2f(WINDOW_HEIGHT / 2, thickness));
    line2.rotate(90);
    line2.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
    line2.setFillColor(color);
    window.draw(line2);

    sf::RectangleShape line3(sf::Vector2f(WINDOW_HEIGHT / 2, thickness));
    line3.rotate(90);
    line3.setPosition(WINDOW_WIDTH / 4, 0);
    line3.setFillColor(color);
    window.draw(line3);

    sf::RectangleShape line4(sf::Vector2f(WINDOW_HEIGHT / 2, thickness));
    line4.rotate(90);
    line4.setPosition(3 * WINDOW_WIDTH / 4, 0);
    line4.setFillColor(color);
    window.draw(line4);

}

int main() {
#if RANDOM_GENERATING
    srand(int(std::time(NULL))); // Set current time as seed for png
#else
    srand(0); // Set seed for pseudorandom number generator
#endif

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Sierpinsky triangle");
    window.clear(sf::Color::White);
    window.display();

    std::vector<Dot> vertexes = generate_3_vertexes();
    std::vector<Dot> dots_list;
    dots_list.push_back(Dot(rand() % WINDOW_WIDTH, rand() % WINDOW_HEIGHT));

    int number_of_points = 0;
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (number_of_points < MAXIMUM_NUMBER_OF_POINTS) {
            int n = rand() % 3;

            int x = (vertexes[n].getX() + dots_list.back().getX()) / 2;
            int y = (vertexes[n].getY() + dots_list.back().getY()) / 2;

            dots_list.push_back(Dot(x, y));

            number_of_points++;
        }

        window.clear(sf::Color::White);
       
        draw_zone_lines(window);

        draw_points_from_list(window, dots_list);
        draw_points_from_list(window, vertexes);

        window.display();

        sf::sleep(sf::milliseconds(1));
    }
    return 0;
}