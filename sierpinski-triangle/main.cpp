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
        Dots generates in this three zones.
    */
    
    Dot d1(WINDOW_WIDTH / 4 + rand() % (WINDOW_WIDTH / 2),
        rand() % (WINDOW_HEIGHT / 2), Dot::Type::VERTEX);

    Dot d2(rand() % (WINDOW_WIDTH / 2),
        (WINDOW_HEIGHT / 2) + rand() % (WINDOW_HEIGHT / 2), Dot::Type::VERTEX);

    Dot d3(WINDOW_WIDTH / 2 + rand() % (WINDOW_WIDTH / 2),
        (WINDOW_HEIGHT / 2) + rand() % (WINDOW_HEIGHT / 2), Dot::Type::VERTEX);

    vertexes.push_back(d1);
    vertexes.push_back(d2);
    vertexes.push_back(d3);

    return vertexes;
}

void draw_dots_from_list(sf::RenderWindow& window, const std::vector<Dot>& dots_list) {
    for (Dot d : dots_list) {
        d.draw(window);
    }
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

    int number_of_dots = 0;
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (number_of_dots < MAXIMUM_NUMBER_OF_POINTS) {
            int n = rand() % 3;

            int x = (vertexes[n].getX() + dots_list.back().getX()) / 2;
            int y = (vertexes[n].getY() + dots_list.back().getY()) / 2;

            dots_list.push_back(Dot(x, y));

            number_of_dots++;
        }

        window.clear(sf::Color::White);

        draw_dots_from_list(window, dots_list);
        draw_dots_from_list(window, vertexes);

        window.display();

        sf::sleep(sf::milliseconds(1));
    }
    return 0;
}