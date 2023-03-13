//
// Created by 本間優之介 on 2023/02/20.
//

#include "Bureaucrat.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"

int main() {
	{
		std::cout << "##################################################################" << std::endl;
		std::cout << "#                   \x1b[36mShrubberyCreationForm TEST\x1b[0m                   #" << std::endl;
		std::cout << "##################################################################" << std::endl;
		{
			std::cout << CYAN << "[TEST1]" << RESET << std::endl;
			ShrubberyCreationForm test1("test1");
			Bureaucrat ng("cannot_sign_exec", 150);
			std::cout << RED;
			ng.signForm(test1);
			ng.executeForm(test1);
			std::cout << RESET;
		}
		std::cout << std::endl;
		{
			std::cout << CYAN << "[TEST2]" << RESET << std::endl;
			ShrubberyCreationForm test2("test2");
			Bureaucrat ng("cannnot_exec", 140);
			std::cout << GREEN;
			ng.signForm(test2);
			std::cout << RED;
			ng.executeForm(test2);
			std::cout << RESET;
		}
		std::cout << std::endl;
		{
			std::cout << CYAN << "[TEST3]" << RESET << std::endl;
			ShrubberyCreationForm test3("test3");
			Bureaucrat ok("ok", 1);
			std::cout << GREEN;
			ok.signForm(test3);
			ok.executeForm(test3);
			std::cout << RESET;
		}
	}
	std::cout << std::endl;
	{
		srand((unsigned int) time(NULL));
		std::cout << "##################################################################" << std::endl;
		std::cout << "#                    \x1b[36mRobotomyRequestForm TEST\x1b[0m                    #" << std::endl;
		std::cout << "##################################################################" << std::endl;
		{
			std::cout << CYAN << "[TEST1]" << RESET << std::endl;
			RobotomyRequestForm test1("test1");
			Bureaucrat ng("cannot_sign_exec", 150);
			std::cout << RED;
			ng.signForm(test1);
			ng.executeForm(test1);
			std::cout << RESET;
		}
		std::cout << std::endl;
		{
			std::cout << CYAN << "[TEST2]" << RESET << std::endl;
			RobotomyRequestForm test2("test2");
			Bureaucrat ng("cannnot_exec", 80);
			std::cout << GREEN;
			ng.signForm(test2);
			std::cout << RED;
			ng.executeForm(test2);
			std::cout << RESET;
		}
		std::cout << std::endl;
		{
			std::cout << CYAN << "[TEST3]" << RESET << std::endl;
			RobotomyRequestForm test3("test3");
			Bureaucrat ok("ok", 1);
			std::cout << GREEN;
			ok.signForm(test3);
			ok.executeForm(test3);
			std::cout << RESET;
		}
	}
	std::cout << std::endl;
	{
		std::cout << "##################################################################" << std::endl;
		std::cout << "#                  \x1b[36mPresidentialPardonForm TEST\x1b[0m                   #" << std::endl;
		std::cout << "##################################################################" << std::endl;
		{
			std::cout << CYAN << "[TEST1]" << RESET << std::endl;
			PresidentialPardonForm test1("test1");
			Bureaucrat ng("cannot_sign_exec", 150);
			std::cout << RED;
			ng.signForm(test1);
			ng.executeForm(test1);
			std::cout << RESET;
		}
		std::cout << std::endl;
		{
			std::cout << CYAN << "[TEST2]" << RESET << std::endl;
			PresidentialPardonForm test2("test2");
			Bureaucrat ng("cannnot_exec", 20);
			std::cout << GREEN;
			ng.signForm(test2);
			std::cout << RED;
			ng.executeForm(test2);
			std::cout << RESET;
		}
		std::cout << std::endl;
		{
			std::cout << CYAN << "[TEST3]" << RESET << std::endl;
			PresidentialPardonForm test3("test3");
			Bureaucrat ok("ok", 1);
			std::cout << GREEN;
			ok.signForm(test3);
			ok.executeForm(test3);
			std::cout << RESET;
		}
	}
}