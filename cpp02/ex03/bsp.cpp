//
// Created by 本間優之介 on 2023/02/15.
//

#include "Point.h"

// ベクトルの外積の計算
Fixed outer_product(Point p1, Point p2, Point p3) {
	return (p1.get_x() - p3.get_x()) * (p2.get_y() - p3.get_y()) \
			- (p2.get_x() - p3.get_x()) * (p1.get_y() - p3.get_y());
}

// 外積の符号の一致を判定する
bool bsp( Point const& a, Point const& b, Point const& c, Point const& point) {
	Fixed p1, p2, p3;

	p1 = outer_product(point, a, b);
	p2 = outer_product(point, b, c);
	p3 = outer_product(point, c, a);
	if ((p1 > 0 && p2 > 0 && p3 > 0) || (p1 < 0 && p2 < 0 && p3 < 0))
		return true;
	return false;
}