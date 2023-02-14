//
// Created by 本間優之介 on 2023/02/14.
//

#include "Point.h"

Point::Point(): x(Fixed(0)), y(Fixed(0)) {

}

Point::Point(const float a, const float b): x(Fixed(a)), y(Fixed(b)){

}

Point::Point(const Fixed &a, const Fixed &b): x(Fixed(a)), y(Fixed(b)) {

}

Point::Point(const Point &source): x(Fixed(source.x)), y(Fixed(source.y)) {

}

Point::~Point() {

}

Point& Point::operator=(const Point &source) {
	const_cast<Fixed&>(this->x) = source.x;
	const_cast<Fixed&>(this->y) = source.y;
	return *this;
}

Fixed Point::get_x() {
	return x;
}

Fixed Point::get_y() {
	return y;
}