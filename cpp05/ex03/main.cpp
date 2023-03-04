//
// Created by 本間優之介 on 2023/02/20.
//

#include "Bureaucrat.h"
#include "Intern.h"

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"

int main() {
	Bureaucrat test("test", 60);
	Intern intern;
	std::cout << "------------------------------------------------------" << std::endl;
	{
		AForm *sc = intern.makeForm("shrubbery creation", "test_sc");
		test.signForm(*sc);
		test.executeForm(*sc);
	}
	std::cout << "------------------------------------------------------" << std::endl;
	{
		AForm *rr = intern.makeForm("robotomy request", "test_rr");
		test.signForm(*rr);
		test.executeForm(*rr);
	}
	std::cout << "------------------------------------------------------" << std::endl;
	{
		AForm* pp = intern.makeForm("presidential pardon", "test_pp");
		test.signForm(*pp);
		test.executeForm(*pp);
	}
	std::cout << "------------------------------------------------------" << std::endl;
}