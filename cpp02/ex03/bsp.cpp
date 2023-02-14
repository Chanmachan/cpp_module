//
// Created by 本間優之介 on 2023/02/15.
//

#include "Point.h"

// ベクトルの外積の計算
Fixed judge_outer_product_sign(Point p1, Point p2, Point p3) {
	return (p1.get_x() - p3.get_x()) * (p2.get_y() - p3.get_y()) \
			- (p2.get_x() - p3.get_x()) * (p1.get_y() - p3.get_y());
}

// 外積の符号の一致を判定する
bool bsp( Point const a, Point const b, Point const c, Point const point) {
	bool b1, b2, b3;

	b1 = judge_outer_product_sign(point, a, b) < 0;
	b2 = judge_outer_product_sign(point, b, c) < 0;
	b3 = judge_outer_product_sign(point, c, a) < 0;
	return (b1 == b2) && (b2 == b3);
}