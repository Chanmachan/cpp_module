//
// Created by 本間優之介 on 2022/12/21.
//

#include "Fixed.hpp"
#include <iostream>

int main( void ) {
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	Fixed const e( 100 );
	Fixed const f( -100 );
	Fixed const g( 0 );
	a = Fixed( 1234.4321f );
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "d is " << e << std::endl;
	std::cout << "d is " << f << std::endl;
	std::cout << "d is " << g << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	std::cout << "d is " << e.toInt() << " as integer" << std::endl;
	std::cout << "d is " << f.toInt() << " as integer" << std::endl;
	std::cout << "d is " << g.toInt() << " as integer" << std::endl;
	return 0;
}