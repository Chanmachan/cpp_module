//
// Created by 本間優之介 on 2023/02/20.
//

#include "Bureaucrat.h"

int main() {
	Bureaucrat a;
	Bureaucrat b("hoge", 150);
	for (size_t i = 0; i < 5; i++) {
		try {
			b.incrementGrade();
		} catch (std::out_of_range& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << b << std::endl;
	for (size_t i = 0; i < 6; i++) {
		try {
			b.decrementGrade();
		} catch (std::out_of_range& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << b << std::endl;

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