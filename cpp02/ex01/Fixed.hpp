//
// Created by 本間優之介 on 2022/12/21.
//

#ifndef CPP_MODULE_FIXED_HPP
#define CPP_MODULE_FIXED_HPP

#include <iostream>

class Fixed {
private:
	int	fixed_num;
	static const int fractional_bits = 8;
public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	~Fixed();
	Fixed(const Fixed& source);

	Fixed& operator=(const Fixed& source);

	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream& operator<<(std::ostream &ostream, const Fixed& Fixed);

#endif //CPP_MODULE_FIXED_HPP
