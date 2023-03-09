//
// Created by 本間優之介 on 2023/03/04.
//

#ifndef EXE_CONVERT_H
#define EXE_CONVERT_H

#include <iostream>
#include <sstream>
#include <string>

typedef enum e_type {
	E_CHAR,
	E_INT,
	E_FLOAT,
	E_DOUBLE,
}			t_type;

class Convert {
private:
	const std::string literal_;
	std::string output_;
	int int_num_;
	size_t digit_int_;
public:
	Convert();
	explicit Convert(const std::string& literal);
	Convert(const Convert& src);
	~Convert();
	Convert& operator=(const Convert& src);

	bool getValidNumbers();
	void setIntNum();
	bool isOverflow() const;
	const std::string& getLiteral() const;
	int getIntNum() const;
	size_t getDigitInt() const;
	void inputConvertedType(t_type type);
	std::string& adjustFractionalDigit(std::string& output);
	const std::string& getOutput() const;
};

//std::ostream& operator<<(std::ostream& ostream, const Convert& out);

#endif //EXE_CONVERT_H