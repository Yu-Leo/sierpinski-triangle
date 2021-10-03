#include "Point.h"

const void Point::draw(sf::RenderWindow& window) {
    sf::CircleShape shape(5.0f);
    shape.setFillColor(sf::Color::Blue);
    shape.setPosition(sf::Vector2f(float(this->getX()), float(this->getY())));
    window.draw(shape);
}