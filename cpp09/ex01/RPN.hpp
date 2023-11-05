//
// Created by chanma on 2023/10/16.
//

#ifndef EXE_RPN_HPP
#define EXE_RPN_HPP

#include <stack>
#include <string>

class RPN {
private:
	std::stack<int> nums;

	//bool validateArg(char *arg) const;
	bool calculate(std::string::iterator& it);
	bool isArithmeticOperator(std::string::iterator it) const;
	void skipSpace(std::string::iterator& it);
public:
	RPN();
	~RPN();

	RPN(const RPN& src);
	RPN& operator=(const RPN& rhs);
	bool processRpn(const char *arg);
};


#endif //EXE_RPN_HPP
