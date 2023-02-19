//
// Created by 本間優之介 on 2022/12/21.
//

#include "Point.h"
#include <iostream>

bool bsp( Point const& a, Point const& b, Point const& c, Point const& point);

int main( void ) {
	/* 1 */
	{
		Point p1(0.0, 0.0);
		Point p2(2.0, 0.0);
		Point p3(1.0, 2.0);
		Point point(1.0, 1.0);
		bool input_bool = bsp(p1, p2, p3, point);
		// true
		std::cout << "[1] " << std::boolalpha << input_bool << std::endl;
	}

	/* 2 */
	{
		Point p1(10.0, 5.0);
		Point p2(1.0, 1.0);
		Point p3(7.0, 10.0);
		Point point(6.0, 6.0);
		bool input_bool = bsp(p1, p2, p3, point);
		// true
		std::cout << "[2] " << std::boolalpha << input_bool << std::endl;
	}

	/* 3 */
	{
		Point p1(2.0, 2.0);
		Point p2(2.0, 0.0);
		Point p3(0.0, 2.0);
		Point point(1.0, 1.0);
		bool input_bool = bsp(p1, p2, p3, point);
		// false
		std::cout << "[3] " << std::boolalpha << input_bool << std::endl;
	}

	/* 4 */
	{
		Point p1(2.0, 2.0);
		Point p2(2.0, 0.0);
		Point p3(0.0, 2.0);
		Point point(1.9, 1.9);
		bool input_bool = bsp(p1, p2, p3, point);
		// true
		std::cout << "[4] " << std::boolalpha << input_bool << std::endl;
	}

	/* 5 */
	{
		Point p1(0.0, 0.0);
		Point p2(10.0, 0.0);
		Point p3(5.0, 5.0);
		Point point(2.0, 0.0);
		bool input_bool = bsp(p1, p2, p3, point);
		// false
		std::cout << "[5] " << std::boolalpha << input_bool << std::endl;
	}
}