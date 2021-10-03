#pragma once

#include <SFML/Graphics.hpp>

class Point {
public:
	
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}

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
};

