//
// Created by 本間優之介 on 2023/02/25.
//

#ifndef CPP05EX01_SHRUBBERYCREATIONFORM_H
#define CPP05EX01_SHRUBBERYCREATIONFORM_H

#include "AForm.h"

class ShrubberyCreationForm: public AForm {
private:
	const static int required_grade_to_sign = 145;
	const static int required_grade_to_exec = 137;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& src);
	~ShrubberyCreationForm();

	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& src);
};


#endif //CPP05EX01_SHRUBBERYCREATIONFORM_H
