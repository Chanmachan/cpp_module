//
// Created by 本間優之介 on 2022/12/21.
//

#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include <cfloat>
#include <stdio.h>

Fixed::Fixed(): _fixed_num(0) {
	std::cout << "Default constructor called" << std::endl;
}

// int,floatの1とfixedの1は認識が違う(小数点の位置が違うイメージ)
// int,float->1.00000000 fixed->0.00000001なので揃えてあげる
Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	int binary_fb = 1 << _fractional_bits;
	if (value < INT_MIN / binary_fb || INT_MAX / binary_fb < value) {
		std::cout << "value is out of range -> 0" << std::endl;
		this->_fixed_num = 0;
	}
	else {
		this->_fixed_num = value * binary_fb;
	}
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	int binary_fb = 1 << _fractional_bits;
	if (value < FLT_MIN / binary_fb || FLT_MAX / binary_fb < value) {
		std::cout << "value is out of range -> 0" << std::endl;
		this->_fixed_num = 0;
	}
	else {
		this->_fixed_num = roundf(value * binary_fb);
	}
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& source){
	std::cout << "Copy constructor called" << std::endl;
	this->_fixed_num = source._fixed_num;
	*this = source;
}

Fixed& Fixed::operator=(const Fixed& source){
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixed_num = source._fixed_num;
	return *this;
}

int Fixed::getRawBits( void ) const{
	std::cout << "getRawBits member function called" << std::endl;
	return _fixed_num;
}

void Fixed::setRawBits(const int raw) {
	_fixed_num = raw;
}

float Fixed::toFloat() const {
	return (float)_fixed_num / (1 << _fractional_bits);
}

int Fixed::toInt() const {
	return _fixed_num / (1 << _fractional_bits);
}

std::ostream& operator<<(std::ostream &ostream, const Fixed& Fixed) {
	return ostream << Fixed.toFloat();
}