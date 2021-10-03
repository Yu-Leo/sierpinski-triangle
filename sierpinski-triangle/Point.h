#pragma once

#include <SFML/Graphics.hpp>

class Point {
public:
	
	enum class Type {
		VERTEX,
		SIMPLE
	};

	Point(int x, int y, Type type) {
		this->x = x;
		this->y = y;
		this->type = type;
	}

	Point(int x, int y) : Point(x, y, Type::SIMPLE) {}

	Point() : Point(0, 0) {}

	const int getX() {
		return this->x;
	}

	const int getY() {
		return this->y;
	}

	const void draw(sf::RenderWindow& window);

private:
	int x = 0;
	int y = 0;
	Type type = Type::SIMPLE;
};

