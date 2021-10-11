#include <random>
#include <iostream>
#include <vector>
#include <ctime>

#include <SFML/Graphics.hpp>

#include "Triangle.h"

#define RANDOM_GENERATING true // (true/false)

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600


void set_current_number_of_dots_text_settings(sf::Text & current_number_of_dots_text,
    const sf::Font & font) {

    current_number_of_dots_text.setFont(font);
    current_number_of_dots_text.setCharacterSize(35);
    current_number_of_dots_text.setFillColor(sf::Color::Black);
    current_number_of_dots_text.setPosition(20, 10);
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

    Triangle triangle(Size(WINDOW_WIDTH, WINDOW_HEIGHT));

    sf::Font font; // Font for text
    font.loadFromFile("./fonts/font.ttf");

    sf::Text current_number_of_dots_text;
    set_current_number_of_dots_text_settings(current_number_of_dots_text, font);

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

        current_number_of_dots_text.setString("N: " + std::to_string(triangle.get_current_number_of_dots()));        
        window.draw(current_number_of_dots_text);

        window.display();

        sf::sleep(sf::milliseconds(10));
    }
    return 0;
}