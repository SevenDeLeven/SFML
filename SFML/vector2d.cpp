#include "vector2d.h"

vector2d::vector2d() {
	x = 0;
	y = 0;
}

vector2d::vector2d(double _x, double _y) {
	x = _x;
	y = _y;
}

vector2d& vector2d::operator=(const vector2d &vect) {
	x = vect.x;
	y = vect.y;
	return *this;
}
vector2d& vector2d::operator=(const int mag) {
	setMag(mag);
	return *this;
}

vector2d& vector2d::operator+=(const vector2d &vect) {
	x += vect.x;
	y += vect.y;
	return *this;
}
vector2d& vector2d::operator-=(const vector2d &vect) {
	x -= vect.x;
	y -= vect.y;
	return *this;
}
vector2d& vector2d::operator*=(const vector2d &vect) {
	x *= vect.x;
	y *= vect.y;
	return *this;
}
vector2d& vector2d::operator/=(const vector2d &vect) {
	if (vect.x != 0) x /= vect.x;
	if (vect.y != 0) x /= vect.y;
	return *this;
}
vector2d& vector2d::operator+=(int add) {
	setMag(getMag() + add);
	return *this;
}
vector2d& vector2d::operator-=(int sub) {
	setMag(getMag() - sub);
	return *this;
}
vector2d& vector2d::operator*=(int mult) {
	x *= mult;
	y *= mult;
	return *this;
}
vector2d& vector2d::operator/=(int div) {
	if (div == 0) {
		return *this;
	}
	x /= div;
	y /= div;
	return *this;
}
vector2d vector2d::operator+(const vector2d &vect) {
	return vector2d(x + vect.x, y + vect.y);
}
vector2d vector2d::operator+(int add) {
	double mag = getMag();
	return vector2d(x + (add*x / mag), y + (add*y / mag));
}
vector2d vector2d::operator+(double add) {
	double mag = getMag();
	return vector2d(x + (add*x / mag), y + (add*y / mag));
}
vector2d vector2d::operator-(const vector2d &vect) {
	return vector2d(x - vect.x, y - vect.y);
}
vector2d vector2d::operator-(int sub) {
	double mag = getMag();
	return vector2d(x - (sub*x / mag), y - (sub*y / mag));
}
vector2d vector2d::operator-(double sub) {
	double mag = getMag();
	return vector2d(x - (sub*x / mag), y - (sub*y / mag));
}
vector2d vector2d::operator*(const vector2d &vect) {
	return vector2d(x*vect.x, y*vect.y);
}
vector2d vector2d::operator*(int mul) {
	return vector2d(x*mul, y*mul);
}
vector2d vector2d::operator*(double mul) {
	return vector2d(x*mul, y*mul);
}
vector2d vector2d::operator/(const vector2d &vect) {
	return vector2d(x / vect.x, y / vect.y);
}
vector2d vector2d::operator/(int div) {
	if (div == 0) return vector2d(0, 0);
	return vector2d(x / div, y / div);
}
vector2d vector2d::operator/(double div) {
	if (div == 0) return vector2d(0, 0);
	return vector2d(x / div, y / div);
}
vector2d& vector2d::setMag(double mag) {
	double curMag = getMag();
	if (curMag == 0) {
		return *this;
	}
	x = x / curMag * mag;
	y = y / curMag * mag;
	return *this;
}

void vector2d::setX(double _x) {
	x = _x;
}
void vector2d::setY(double _y) {
	y = _y;
}
double vector2d::getX() {
	return x;
}
double vector2d::getY() {
	return y;
}
double vector2d::getMag() {
	return sqrt((x*x) + (y*y));
}
double vector2d::asAngle() {
	return asin(y / getMag());
}