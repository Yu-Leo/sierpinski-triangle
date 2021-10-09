#include "Dot.h"

const void Dot::draw(sf::RenderWindow& window) {
    
    sf::Color color;
    float size = 10.0f;
    switch (this->type) {
    case Type::VERTEX:
        color = sf::Color::Red;
        size = 5.0f;
        break;
    case Type::SIMPLE:
        color = sf::Color::Blue;
        size = 2.0f;
        break;
    }
    sf::CircleShape shape(size);
    shape.setFillColor(color);
    shape.setPosition(sf::Vector2f(float(this->getX()), float(this->getY())));
    window.draw(shape);
}