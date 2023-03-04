//
// Created by 本間優之介 on 2023/03/03.
//

#include "Intern.h"

Intern::Intern()
		: ShrubberyCreation_("shrubbery creation"),
		RobotomyRequest_("robotomy request"),
		PresidentialPardon_("presidential pardon")
		{
	std::cout << "Intern Constructor called" << std::endl;
}

Intern::~Intern() {
	std::cout << "Intern Destructor called" << std::endl;
}

AForm* Intern::makeForm(std::string form_name, std::string target) {
	AForm *Form = NULL;
	switch (checkWhichForm(form_name)) {
		case 0:
			Form = new ShrubberyCreationForm(target);
			break;
		case 1:
			Form = new RobotomyRequestForm(target);
			break;
		case 2:
			Form = new PresidentialPardonForm(target);
			break;
		default:
			std::cout << "Target of the form is incorrect" << std::endl;
			return Form;
	}
	std::cout << form_name << " " << Form->getName() << " is created" << std::endl;
	return Form;
}

int Intern::checkWhichForm(std::string form_name) {
	std::string Forms[3] = {
			ShrubberyCreation_,
			RobotomyRequest_,
			PresidentialPardon_
	};
	int i = 0;
	for (; i < 3 && Forms[i] != form_name; i++) {}
	return i;
}