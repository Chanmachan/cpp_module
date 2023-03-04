//
// Created by 本間優之介 on 2023/03/03.
//

#ifndef CPP05EX03_INTERN_H
#define CPP05EX03_INTERN_H

#include "AForm.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"

class Intern {
private:
	Intern(const Intern& src);
	Intern& operator=(const Intern& src);
	const std::string ShrubberyCreation_;
	const std::string RobotomyRequest_;
	const std::string PresidentialPardon_;
	int checkWhichForm(std::string form_name);
public:
	Intern();
	~Intern();

	AForm* makeForm(std::string form_name, std::string target);
};


#endif //CPP05EX03_INTERN_H
