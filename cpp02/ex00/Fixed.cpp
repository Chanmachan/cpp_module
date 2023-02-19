//
// Created by 本間優之介 on 2022/12/21.
//

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(): fixed_num(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& source){
	std::cout << "Copy constructor called" << std::endl;
	this->fixed_num = source.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& source){
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixed_num = source.getRawBits();
	return *this;
}

int Fixed::getRawBits( void ) const{
	std::cout << "getRawBits member function called" << std::endl;
	return fixed_num;
}

void Fixed::setRawBits(const int raw) {
	fixed_num = raw;
}