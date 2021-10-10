#include <random>
#include <iostream>
#include <vector>
#include <ctime>

#include <SFML/Graphics.hpp>

#include "Triangle.h"

#define RANDOM_GENERATING true // (true/false)

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int main() {
#if RANDOM_GENERATING
    srand(int(std::time(NULL))); // Set current time as seed for png
#else
    srand(0); // Set seed for pseudorandom number generator
#endif

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Sierpinsky triangle");
    window.clear(sf::Color::White);
    window.display();

    Triangle triangle(Size(WINDOW_WIDTH, WINDOW_HEIGHT));

    sf::Font font; // Font for titles
    sf::Text score_text;

    font.loadFromFile("./fonts/font.ttf");

    score_text.setFont(font);
    score_text.setCharacterSize(35);
    score_text.setFillColor(sf::Color::Black);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (!triangle.are_all_dots_generated()) {
            triangle.add_dot();
        }
        

        window.clear(sf::Color::White);
        triangle.draw(window);

        score_text.setString("N: ");
        score_text.setPosition(
            WINDOW_WIDTH - score_text.getLocalBounds().width - 20, 7);
        window.draw(score_text);


        window.display();


        sf::sleep(sf::milliseconds(1));
    }
    return 0;
}