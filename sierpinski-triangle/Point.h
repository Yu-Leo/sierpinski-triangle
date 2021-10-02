#pragma once
class Point {
public:
	
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}

	const int getX() {
		return this->x;
	}

	const int getY() {
		return this->y;
	}

private:
	int x = 0;
	int y = 0;
};

