//
// Created by 本間優之介 on 2022/12/21.
//

#include "Fixed.hpp"
#include <iostream>

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << "--------additional-------" << std::endl;
	Fixed const c( Fixed( 5.05f ) / Fixed( 2 ) );
	std::cout << c << std::endl;
	// a(0) > b(10.1016) -> false
	if (a > b)
		std::cout << "a > b: " << "true" << std::endl;
	else
		std::cout << "a > b: " << "false" << std::endl;
	// a(0) < b(10.1016) -> true
	if (a < b)
		std::cout << "a < b: " << "true" << std::endl;
	else
		std::cout << "a < b: " << "false" << std::endl;
	// 	// a(0) == b(10.1016) false
	if (a == b)
		std::cout << "a < b: " << "true" << std::endl;
	else
		std::cout << "a < b: " << "false" << std::endl;
	return 0;


}