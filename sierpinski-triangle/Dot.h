#pragma once

#include <SFML/Graphics.hpp>

class Dot {
public:
	
	enum class Type {
		VERTEX,
		SIMPLE
	};

	Dot(int x, int y, Type type) {
		this->x = x;
		this->y = y;
		this->type = type;
	}

	Dot(int x, int y) : Dot(x, y, Type::SIMPLE) {}

	Dot() : Dot(0, 0) {}

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

