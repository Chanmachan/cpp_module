//
// Created by 本間優之介 on 2023/02/20.
//

#include "Bureaucrat.h"
#include "Intern.h"

//__attribute__((destructor))
//static void destructor() {
//	system("leaks -q exe");
//}

int main() {
	srand((unsigned int) time(NULL));
	Bureaucrat test("test", 60);
	Intern intern;
	std::cout << "------------------------------------------------------" << std::endl;
	{
		AForm *sc = intern.makeForm("shrubbery creation", "test_sc");
		test.signForm(*sc);
		test.executeForm(*sc);
		delete sc;
	}
	std::cout << "------------------------------------------------------" << std::endl;
	{
		AForm *rr = intern.makeForm("robotomy request", "test_rr");
		test.signForm(*rr);
		test.executeForm(*rr);
		delete rr;
	}
	std::cout << "------------------------------------------------------" << std::endl;
	{
		AForm* pp = intern.makeForm("presidential pardon", "test_pp");
		test.signForm(*pp);
		test.executeForm(*pp);
		delete pp;
	}
	std::cout << "------------------------------------------------------" << std::endl;
	{
		AForm *error = NULL;
		try{
			error = intern.makeForm("a", "b");
		}
		catch (std::invalid_argument& e){
			std:: cout << e.what() << std:: endl;
			return 1;
		}
		// std::    cout << "test1!!"  << std::endl;
		test.signForm(*error);
		test.executeForm(*error);
	}
}