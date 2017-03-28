#include "vector2.h"

Vector2::Vector2() {

}

Vector2::Vector2(int x_, int y_) {
	x = x_;
	y + y_;
}

Vector2::~Vector2() {

}

void Vector2::add(Vector2 vec) {
	x += vec.x;
	y += vec.y;
}

void Vector2::sub(Vector2 vec) {
	x += vec.x;
	y -= vec.y;
}

void Vector2::mult(Vector2 vec) {
	x = x * vec.x;
	y = y * vec.y;
}

void Vector2::div(Vector2 vec) {
	x = x / vec.x;
	y = y / vec.y;
}

void Vector2::normalize() {
	int i = mag();
	if (i != 0) {
		y = y / i;
		x = x / i;
	}
}

int Vector2::mag() {
	return sqrt(x*x + y*y);
}
