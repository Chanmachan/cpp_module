//
// Created by 本間優之介 on 2022/12/21.
//

#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include <cfloat>
#include <stdio.h>

Fixed::Fixed(): fixed_num(0) {
	std::cout << "Default constructor called" << std::endl;
}

// int,floatの1とfixedの1は認識が違う(小数点の位置が違うイメージ)
// int,float->1.00000000 fixed->0.00000001なので揃えてあげる
Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	int shifted_value = value << fractional_bits;
	int overflow_check_var = shifted_value >> fractional_bits;
	if (value != overflow_check_var) {
		if (value > 0) {
			std::cout << "float value is out of range -> adjusted" << std::endl;
			this->fixed_num = INT_MAX;
		} else {
			std::cout << "float value is out of range -> adjusted" << std::endl;
			this->fixed_num = INT_MIN;
		}
	} else {
		this->fixed_num = shifted_value;
	}
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	float binary_fb = 1 << fractional_bits;
	if (value < INT_MIN / binary_fb || INT_MAX / binary_fb < value) {
		std::cout << "float value is out of range -> adjusted" << std::endl;
		this->fixed_num = INT_MIN;
	} else if (INT_MAX / binary_fb < value) {
		std::cout << "float value is out of range -> adjusted" << std::endl;
		this->fixed_num = INT_MAX;
	} else {
		this->fixed_num = roundf(value * binary_fb);
	}
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& source){
	std::cout << "Copy constructor called" << std::endl;
	this->fixed_num = source.fixed_num;
}

Fixed& Fixed::operator=(const Fixed& source){
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixed_num = source.fixed_num;
	return *this;
}

int Fixed::getRawBits( void ) const{
	std::cout << "getRawBits member function called" << std::endl;
	return fixed_num;
}

void Fixed::setRawBits(const int raw) {
	fixed_num = raw;
}

float Fixed::toFloat() const {
	return (float)fixed_num / (1 << fractional_bits);
}

int Fixed::toInt() const {
	return fixed_num / (1 << fractional_bits);
}

std::ostream& operator<<(std::ostream &ostream, const Fixed& Fixed) {
	return ostream << Fixed.toFloat();
}