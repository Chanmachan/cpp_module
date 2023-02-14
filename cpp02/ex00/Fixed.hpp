//
// Created by 本間優之介 on 2022/12/21.
//

#ifndef CPP_MODULE_FIXED_HPP
#define CPP_MODULE_FIXED_HPP


class Fixed {
private:
	int	fixed_num;
	//fractional_bits -> 小数点以下の桁数
	static const int fractional_bits = 8;
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed& source);
	Fixed& operator=(const Fixed& source);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif //CPP_MODULE_FIXED_HPP
