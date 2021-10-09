#include "Triangle.h"

const std::vector<Dot> Triangle::generate_3_vertexes() {
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

    Dot d1(this->window_size.width / 4 + rand() % (this->window_size.width / 2),
        rand() % (this->window_size.height / 2), Dot::Type::VERTEX);

    Dot d2(rand() % (this->window_size.width / 2),
        (this->window_size.height / 2) + rand() % (this->window_size.height / 2), Dot::Type::VERTEX);

    Dot d3(this->window_size.width / 2 + rand() % (this->window_size.height / 2),
        (this->window_size.height / 2) + rand() % (this->window_size.height / 2), Dot::Type::VERTEX);

    vertexes.push_back(d1);
    vertexes.push_back(d2);
    vertexes.push_back(d3);

    return vertexes;
}

bool Triangle::are_all_dots_generated() {
    return dots_list.size() == this->MAXIMUM_NUMBER_OF_POINTS;
}

void Triangle::add_dot() {
    int n = rand() % 3;

    int x = (vertexes[n].getX() + dots_list.back().getX()) / 2;
    int y = (vertexes[n].getY() + dots_list.back().getY()) / 2;

    dots_list.push_back(Dot(x, y));
}

const void Triangle::draw(sf::RenderWindow& window) {
    this->draw_dots_from_list(window, dots_list);
    this->draw_dots_from_list(window, vertexes);
}

const void Triangle::draw_dots_from_list(sf::RenderWindow& window,
    const std::vector<Dot>& dots_list) {

    for (Dot d : dots_list) {
        d.draw(window);
    }
}