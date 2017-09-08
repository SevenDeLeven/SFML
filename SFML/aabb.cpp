#include "aabb.h"

aabb::aabb(double x1, double y1, double x2, double y2, double ox, double oy) {
	p1 = vector2d((x1 < x2 ? x1 : x2) - ox, (y1 < y2 ? y1 : y2) - oy);
	p2 = vector2d((x2 > x1 ? x2 : x1) - ox, (y2 > y1 ? y2 : y1) - oy);
	origin = vector2d(ox, oy);
}

aabb::aabb(vector2d p1, vector2d p2, vector2d p3) : aabb(p1.getX(), p1.getY(), p2.getX(), p2.getY(), p3.getX(), p3.getY()) {}

double aabb::getArea() {
	return (p2.getX() - p1.getX())*(p2.getY() - p1.getY());
}
double aabb::getBottom() {
	return p2.getY();
}
double aabb::getTop() {
	return p1.getY();
}
double aabb::getLeft() {
	return p1.getX();
}
double aabb::getRight() {
	return p2.getX();
}