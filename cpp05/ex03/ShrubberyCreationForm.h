//
// Created by 本間優之介 on 2023/02/25.
//

#ifndef CPP05EX03_SHRUBBERYCREATIONFORM_H
#define CPP05EX03_SHRUBBERYCREATIONFORM_H

#include "AForm.h"
// ファイルの読み書きが必要
#include <fstream>

class ShrubberyCreationForm: public AForm {
private:
	const std::string target_;
	const static int required_grade_to_sign = 145;
	const static int required_grade_to_exec = 137;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &src);
	~ShrubberyCreationForm();

	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);

	void execute(Bureaucrat const & executor) const;
};


#endif //CPP05EX03_SHRUBBERYCREATIONFORM_H
