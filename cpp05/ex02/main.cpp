//
// Created by 本間優之介 on 2023/02/20.
//

#include "Bureaucrat.h"
#include "AForm.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"

int main() {
	{
		ShrubberyCreationForm a("test1");
		ShrubberyCreationForm b(a);
		ShrubberyCreationForm c;
		Bureaucrat d("Kishida", 10);

		c = a;

		d.signForm(c);
		try {
			c.execute(d);
		} catch (std::exception& e) {
			std::cout << "exception: " << e.what() << std::endl;
			std::cout << d.getName() << " (" << d.getGrade() << ")" << " has not reached " << c.getGradeToExec() << " grade_to_exec" << std::endl;
		}
	}
	std::cout << std::endl << "------------------------------------------------------" << std::endl << std::endl;
//	{
//		RobotomyRequestForm a("hoge");
//		RobotomyRequestForm b(a);
//		RobotomyRequestForm c;
//		Bureaucrat d("Kishida", 10);
//
//		c = a;

//		d.signForm(c);
//		try {
//			c.execute(d);
//		} catch (std::exception& e) {
//			std::cout << "hogexception\n";
//			std::cout << e.what() << std::endl;
//		}
//	}
//	std::cout << std::endl << "------------------------------------------------------" << std::endl << std::endl;
	{
		PresidentialPardonForm a("test3");
		PresidentialPardonForm b(a);
		PresidentialPardonForm c;
		Bureaucrat d("Kishida", 4);

		c = a;

		d.signForm(c);
		try {
			c.execute(d);
		} catch (std::exception& e) {
			std::cout << "exception: " << e.what() << std::endl;
			std::cout << d.getName() << " (" << d.getGrade() << ")" << " has not reached " << c.getGradeToExec() << " grade_to_exec" << std::endl;
		}
	}
}