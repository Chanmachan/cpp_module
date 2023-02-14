//
// Created by 本間優之介 on 2023/02/14.
//

#ifndef CPP03EX02_POINT_H
#define CPP03EX02_POINT_H

#include "Fixed.hpp"

class Point {
private:
	const Fixed x;
	const Fixed y;
public:
	Point();
	Point(const float a, const float b);
	Point(const Fixed& a, const Fixed& b);
	Point(const Point& source);
	~Point();
	Point& operator=(const Point& source);

	Fixed get_x();
	Fixed get_y();
};

#endif //CPP03EX02_POINT_H
