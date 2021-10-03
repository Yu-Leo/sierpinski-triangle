#include "Point.h"

const void Point::draw(sf::RenderWindow& window) {
    sf::CircleShape shape(POINT_SIZE);
    sf::Color color;
    switch (this->type) {
    case Type::VERTEX:
        color = sf::Color::Red;
        break;
    case Type::SIMPLE:
        color = sf::Color::Blue;
        break;
    }

    shape.setFillColor(color);
    shape.setPosition(sf::Vector2f(float(this->getX()), float(this->getY())));
    window.draw(shape);
}