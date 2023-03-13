//
// Created by 本間優之介 on 2023/02/20.
//

#include "Bureaucrat.h"
#include "Form.h"

int main() {
	{
		// grade must be over 1, under 150
		Bureaucrat a("Kishida", 100);
		try {
			Form b("test", 15, 100000);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		Form b("test", 20, 100);
		std::cout << std::endl;

		std::cout << "-----------------------TEST-----------------------" << std::endl;

		std::cout << "Before increment: " << a << std::endl;
		for (size_t i = 0; i < 100; i++) {
			try {
				a.incrementGrade();
			} catch (std::out_of_range &e) {
				std::cout << e.what() << std::endl;
			}
		}
		std::cout << "After increment: " << a << std::endl;
		std::cout << std::endl;
		std::cout << "Before decrement: " << a << std::endl;
		for (size_t i = 0; i < 150; i++) {
			try {
				a.decrementGrade();
			} catch (std::out_of_range &e) {
				std::cout << e.what() << std::endl;
			}
		}
		std::cout << "After decrement: " << a << std::endl;

		std::cout << "--------------------------------------------------" << std::endl;

		std::cout << a << std::endl;
		std::cout << "\n" << b << std::endl;
		a.signForm(b);
		for (size_t i = 0; i < 140; i++) {
			a.incrementGrade();
		}
		std::cout << std::endl;
		std::cout << a << std::endl;
		std::cout << "\n" << b << "\n" << std::endl;
		a.signForm(b);
	}
	std::cout << "--------------------------------------------------" << std::endl;
	{
		// error
		try {
			Form a("error", 100, 10000);
		} catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		try {
			Form a("error", -1, 100);
		} catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}

		Form b("be_copied", 100, 10);
		std::cout << b << std::endl;
		Form c("src", 40, 30);
		std::cout << c << std::endl;
		Form d(c);
		std::cout << d << std::endl;
		b = c;
		std::cout << b << std::endl;
	}

}