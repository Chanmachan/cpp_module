//
// Created by 本間優之介 on 2023/02/20.
//

#include "Bureaucrat.h"

int main() {
	Bureaucrat a;
	Bureaucrat b("hoge", 150);
	std::cout << "-----------------------------------" << std::endl;
	for (size_t i = 0; i < 150; i++) {
		try {
			b.incrementGrade();
		} catch (std::out_of_range& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << b << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	for (size_t i = 0; i < 150; i++) {
		try {
			b.decrementGrade();
		} catch (std::out_of_range& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << b << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << "getName: " << a.getName() << std::endl;
	std::cout << "getGrade" << a.getGrade() << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	{

		Bureaucrat c("piyo", 1);
		Bureaucrat d;
		Bureaucrat e(c);
		try {
			Bureaucrat f("error", 100000);
		} catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		d = c;
		std::cout << "d: " << d.getName() << ", " << d.getGrade() << std::endl;
		std::cout << "e: " << e.getName() << ", " << e.getGrade() << std::endl;
	}
	/*
	try {
		std::cout << "here" << std::endl;
		throw Bureaucrat::GradeTooHighException();
	} catch (std::out_of_range& e) {
		std::cout << "here2" << std::endl;
		std::cout << e.what() << std::endl;
	}
	*/
}