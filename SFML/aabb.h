#ifndef AABB_H
#define AABB_H

class aabb;

#include "vector2d.h"

class aabb {
private:
	vector2d p1, p2, origin;
public:
	aabb(double x1, double y1, double x2, double y2, double ox, double oy);

	aabb(vector2d p1, vector2d p2, vector2d p3);

	double getArea();
	double getBottom();
	double getTop();
	double getLeft();
	double getRight();
};

#endif