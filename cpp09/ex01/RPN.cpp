//
// Created by chanma on 2023/10/16.
//

#include "RPN.hpp"
#include <iostream>

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &src): nums(src.nums) {}

RPN& RPN::operator=(const RPN &rhs) {
	if (this != &rhs) {
		this->nums = rhs.nums;
	}
	return *this;
}

bool RPN::processRpn(const char *arg) {
//	if (!validateArg(arg)) {
//		return false;
//	}
	// 前から1文字ずつ計算していって、数字とオペレーター以外がきたらfalseにする
	std::string tokens = std::string(arg);
	for (std::string::iterator it = tokens.begin(); it != tokens.end(); ++it) {
		skipSpace(it);
		// 数値ならpush, 演算子ならpop
		if (std::isdigit(*it)) {
			std::cout << "isdigit-> " << *it << std::endl;
			nums.push(*it - '0');
		} else if (isArithmeticOperator(it)) {
			std::cout << "演算子-> " << *it << std::endl;
			if (!calculate(it)) {
				throw std::runtime_error("insufficient numbers");
			}
		} else {
			if (it == tokens.end()) {
				break;
			}
			throw std::runtime_error("invalid token");
		}
	}
	if (nums.size() != 1) {
		throw std::runtime_error("numbers left yet");
	}
	std::cout << "result: " << nums.top() << std::endl;
	return true;
}

bool RPN::calculate(std::string::iterator& it) {
	if (nums.size() < 2) {
		return false;
	}

	int num1 = nums.top();
	nums.pop();
	int num2 = nums.top();
	nums.pop();

	switch (*it) {
		case '+':
			nums.push(num1 + num2);
			break;
		case '-':
			nums.push(num2 - num1);
			break;
		case '*':
			nums.push(num1 * num2);
			break;
		case '/':
			if (num1 == 0) {
				throw std::runtime_error("Error: zero division");
			}
			nums.push(num2 / num1);
			break;
	}
	return true;
}

bool RPN::isArithmeticOperator(std::string::iterator it) const {
	return *it == '+' || *it == '-' || *it == '*' || *it == '/';
}

void RPN::skipSpace(std::string::iterator& it) {
	while (*it == ' ') {
		it++;
	}
}

// いらんかも
//bool RPN::validateArg(char *arg) const {
//
//	return true;
//}