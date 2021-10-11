#pragma once

#include <vector>

#include "Dot.h"

#include "Size.h"

class Triangle {
public:

    Triangle(const Size &window_size) {
        this->window_size = window_size;
        vertexes = this->generate_3_vertexes();
        dots_list.push_back(Dot(rand() % this->window_size.width,
            rand() % this->window_size.height));
    }

    bool are_all_dots_generated();

    void add_dot();

    const void draw(sf::RenderWindow& window);

    const int get_current_number_of_dots();

private:
    const int MAXIMUM_NUMBER_OF_POINTS = 1000;
    Size window_size;
    std::vector<Dot> vertexes;
    std::vector<Dot> dots_list;
    
    const std::vector<Dot> generate_3_vertexes();

    const void draw_dots_from_list(sf::RenderWindow& window, const std::vector<Dot>& dots_list);
};

