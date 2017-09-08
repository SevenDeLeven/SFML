#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <math.h>

class vector2d;

class vector2d {
private:
	double x, y;
public:
	vector2d();
	vector2d(double _x, double _y);

	vector2d& operator=(const vector2d &vect);
	vector2d& operator=(const int mag);
	
	vector2d& operator+=(const vector2d &vect);
	vector2d& operator-=(const vector2d &vect);
	vector2d& operator*=(const vector2d &vect);
	vector2d& operator/=(const vector2d &vect);
	vector2d& operator+=(int add);
	vector2d& operator-=(int sub);
	vector2d& operator*=(int mult);
	vector2d& operator/=(int div);
	vector2d operator+(const vector2d &vect);
	vector2d operator+(int add);
	vector2d operator+(double add);
	vector2d operator-(const vector2d &vect);
	vector2d operator-(int sub);
	vector2d operator-(double sub);
	vector2d operator*(const vector2d &vect);
	vector2d operator*(int mul);
	vector2d operator*(double mul);
	vector2d operator/(const vector2d &vect);
	vector2d operator/(int div);
	vector2d operator/(double div);
	vector2d& setMag(double mag);


	void setX(double _x);
	void setY(double _y);
	double getX();
	double getY();
	double getMag();
	double asAngle();
};

#endif
