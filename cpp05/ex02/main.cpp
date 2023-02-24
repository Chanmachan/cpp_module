//
// Created by 本間優之介 on 2023/02/20.
//

#include "Bureaucrat.h"
#include "AForm.h"

int main() {
	// grade must be over 1, under 150
	Bureaucrat a("Kishida", 100);
	AForm b("test", 20, 100);
	/*
	{
		Bureaucrat b;
		b = a;
		std::cout << b << std::endl;
	}
	*/
	std::cout << std::endl;

	std::cout << "-----------------------TEST-----------------------" << std::endl;

	std::cout << "Before increment: "  << a << std::endl;
	for (size_t i = 0; i < 100; i++) {
		try {
			a.incrementGrade();
		} catch (std::out_of_range& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "After increment: "  << a << std::endl;
	std::cout << std::endl;
	std::cout << "Before decrement: " << a << std::endl;
	for (size_t i = 0; i < 150; i++) {
		try {
			a.decrementGrade();
		} catch (std::out_of_range& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "After decrement: " << a << std::endl;

	std::cout << "--------------------------------------------------" << std::endl;

	std::cout << b << std::endl;
	std::cout << a << std::endl;
	a.signForm(b);
	for (size_t i = 0; i < 140; i++) {
		a.incrementGrade();
	}
	std::cout << std::endl;
	std::cout << a << std::endl;
	a.signForm(b);

	std::cout << "--------------------------------------------------" << std::endl;


	std::cout << std::endl;

}