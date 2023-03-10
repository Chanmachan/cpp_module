//
// Created by 本間優之介 on 2023/03/11.
//

#include <iostream>
#include <ctime>
#include "A.h"
#include "B.h"
#include "C.h"
#include "color.h"

Base* generate(void) {
	Base *rtn;
	switch (std::rand() % 3) {
		case 1:
			rtn = new A();
			break;
		case 2:
			rtn = new B();
			break;
		default:
			rtn = new C();
	}
	return rtn;
}

// dynamic_castが失敗した場合はNULLが帰ってくる
void identify(Base* p) {
	if (dynamic_cast<A*>(p)) {
		std::cout << "A";
	} else if (dynamic_cast<B*>(p)) {
		std::cout << "B";
	} else if (dynamic_cast<C*>(p)) {
		std::cout << "C";
	}
}

// dynamic_castした戻り値がunused -> static_cast<void>()でvoidにキャスト
void identify(Base& p) {
	try {
		static_cast<void>(dynamic_cast<A&>(p));
		std::cout << "A";
	} catch (std::bad_cast& e) {

	}
	try {
		static_cast<void>(dynamic_cast<B&>(p));
		std::cout << "B";
	} catch (std::bad_cast& e) {

	}
	try {
		static_cast<void>(dynamic_cast<C&>(p));
		std::cout << "C";
	} catch (std::bad_cast& e) {

	}
}
#include <unistd.h>
int main() {
	srand((unsigned int) time(NULL));

	std::cout << CYAN << "[TEST1]" << RESET << std::endl;
	{
		// create Class
		Base *test1 = generate();
		std::cout << "test1 type: ";
		// identify (pointer)
		identify(test1);
		std::cout << std::endl;
		delete test1;
	}

	std::cout << CYAN << "[TEST2]" << RESET << std::endl;
	{
		Base *test2 = generate();
		std::cout << "test1 type: ";
		// identify (reference)
		identify(*test2);
		std::cout << std::endl;
		delete test2;
	}
}