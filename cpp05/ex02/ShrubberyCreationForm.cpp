//
// Created by 本間優之介 on 2023/02/25.
//

#include "ShrubberyCreationForm.h"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("no_name_shrubbery",
			required_grade_to_sign,
			required_grade_to_exec) {

}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm(target + "_shruberry",
			required_grade_to_sign,
			required_grade_to_exec) {

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src): AForm(src) {

}

ShrubberyCreationForm::~ShrubberyCreationForm() {

}