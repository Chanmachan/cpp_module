//
// Created by 本間優之介 on 2023/02/14.
//

#include "Point.h"

Point::Point() {

}

Point::Point(const float a, const float b): x(a), y(b){

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