//
// Created by 本間優之介 on 2022/12/21.
//

#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include <cfloat>

Fixed::Fixed(): fixed_num(0) {
	// std::cout << "Default constructor called" << std::endl;
}

// int,floatの1とfixedの1は認識が違う(小数点の位置が違うイメージ)
// int,float->1.00000000 fixed->0.00000001なので揃えてあげる
Fixed::Fixed(const int value) {
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
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& source){
	// std::cout << "Copy constructor called" << std::endl;
	this->fixed_num = source.fixed_num;
}

int Fixed::getRawBits( void ) const {
	// std::cout << "getRawBits member function called" << std::endl;
	return fixed_num;
}

void Fixed::setRawBits(const int raw) {
	fixed_num = raw;
}

float Fixed::toFloat() const {
	return (float)fixed_num / (1 << fractional_bits);
}

int Fixed::toInt() const {
	return fixed_num << fractional_bits;
}

Fixed& Fixed::min(Fixed& a, Fixed& b){
	if (a.getRawBits() < b.getRawBits())
		return a;
	else
		return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b){
	if (a.getRawBits() < b.getRawBits())
		return a;
	else
		return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b){
	if (a.getRawBits() > b.getRawBits())
		return a;
	else
		return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b){
	if (a.getRawBits() > b.getRawBits())
		return a;
	else
		return b;
}

std::ostream& operator<<(std::ostream &ostream, const Fixed& Fixed) {
	return ostream << Fixed.toFloat();
}

Fixed& Fixed::operator=(const Fixed& source){
	this->fixed_num = source.fixed_num;
	return *this;
}

bool Fixed::is_overflow_plus(const Fixed& a) const {
	int i_a = a.getRawBits();

	if (0 < i_a && 0 < fixed_num && i_a > INT_MAX - fixed_num) {
		return true;
	} else if (i_a < 0 && fixed_num < 0 && i_a < INT_MIN - fixed_num) {
		return true;
	}
	return false;
}

//
bool Fixed::is_overflow_minus(const Fixed &a) const {
	int i_a = a.getRawBits();

	// -10 - (a) < INT_MIN
	if (fixed_num < 0 && 0 < i_a && fixed_num < INT_MIN + i_a) {
		return true;
		// 10 - (-a) > INT_MAX
	} else if (0 < fixed_num && i_a < 0 && fixed_num > INT_MAX + i_a) {
		return true;
	}
	return false;
}

// arithmetic operators
Fixed Fixed::operator+(const Fixed& a) const {
	Fixed ret;

	if (is_overflow_plus(a)) {
		if (0 < fixed_num) {
			std::cout << "value is overflow -> adjust to INT_MAX" << std::endl;
			ret.setRawBits(INT_MAX);
		} else {
			std::cout << "value is overflow -> adjust to INT_MIN" << std::endl;
			ret.setRawBits(INT_MIN);
		}
	} else {
		ret.setRawBits(fixed_num + a.getRawBits());
	}
	return ret;
}

Fixed Fixed::operator-(const Fixed& a) const {
	Fixed ret;

	if (is_overflow_minus(a)) {
		if (0 > fixed_num) {
			std::cout << "value is overflow -> adjust to INT_MIN" << std::endl;
			ret.setRawBits(INT_MIN);
		} else {
			std::cout << "value is overflow -> adjust to INT_MAX" << std::endl;
			ret.setRawBits(INT_MAX);
		}
	} else {
		ret.setRawBits(fixed_num - a.getRawBits());
	}
	return ret;
}

// エラーチェック？
// 0.1みたいな数を２で割った時に先にビットをずらしておくことで問答無用で0になっちゃのを防ぐ
Fixed Fixed::operator*(const Fixed& a) const {
	Fixed ret;

	ret.setRawBits(this->fixed_num * a.getRawBits() >> fractional_bits);
	return ret;
}

Fixed Fixed::operator/(const Fixed& a) const {
	Fixed ret;
	if (a.getRawBits() == 0) {
		throw std::invalid_argument("Floating point exception");
	}
	ret.setRawBits((this->fixed_num << fractional_bits) / a.getRawBits());
	return ret;
}

// comparison operators
bool Fixed::operator>(const Fixed &target) const {
	return this->fixed_num > target.getRawBits();
}

bool Fixed::operator<(const Fixed &target) const {
	return this->fixed_num < target.getRawBits();
}

bool Fixed::operator>=(const Fixed &target) const {
	return this->fixed_num >= target.getRawBits();
}

bool Fixed::operator<=(const Fixed &target) const {
	return this->fixed_num <= target.getRawBits();
}

bool Fixed::operator==(const Fixed& target) const {
	return this->fixed_num == target.getRawBits();
}

bool Fixed::operator!=(const Fixed& target) const {
	return this->fixed_num != target.getRawBits();
}

// prefix
Fixed& Fixed::operator++() {
	this->fixed_num++;
	return (*this);
}

Fixed& Fixed::operator--() {
	this->fixed_num--;
	return *this;
}

// postfix
Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	this->fixed_num++;
	return tmp;
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	this->fixed_num--;
	return tmp;
}