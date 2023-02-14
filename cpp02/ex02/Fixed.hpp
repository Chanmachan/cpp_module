//
// Created by 本間優之介 on 2022/12/21.
//

#ifndef CPP_MODULE_FIXED_HPP
#define CPP_MODULE_FIXED_HPP

#include <iostream>

class Fixed {
private:
	int	fixed_num;
public:
	static const int fractional_bits = 8;
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	~Fixed();
	Fixed(const Fixed& source);

	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;
	static Fixed& min(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);

	bool is_overflow(const Fixed& a) const;
	Fixed& operator=(const Fixed& source);
	Fixed operator+(const Fixed& a) const;
	Fixed operator-(const Fixed& a) const;
	Fixed operator*(const Fixed& a) const;
	Fixed operator/(const Fixed& a) const;
	bool operator>(const Fixed& target) const;
	bool operator<(const Fixed& target) const;
	bool operator>=(const Fixed& target) const;
	bool operator<=(const Fixed& target) const;
	bool operator==(const Fixed& target) const;
	bool operator!=(const Fixed& target) const;
	// prefix
	Fixed& operator++();
	Fixed& operator--();
	// postfix
	Fixed operator++(int);
	Fixed operator--(int);
};

std::ostream& operator<<(std::ostream &ostream, const Fixed& Fixed);

#endif //CPP_MODULE_FIXED_HPP
