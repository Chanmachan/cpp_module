//
// Created by 本間優之介 on 2023/02/25.
//

#ifndef CPP05EX03_PRESIDENTIALPARDONFORM_H
#define CPP05EX03_PRESIDENTIALPARDONFORM_H

#include "AForm.h"

class PresidentialPardonForm: public AForm {
	private:
		const std::string target_;
		const static int required_grade_to_sign = 25;
		const static int required_grade_to_exec = 5;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &src);
		~PresidentialPardonForm();

		PresidentialPardonForm &operator=(const PresidentialPardonForm &src);

	void execute(Bureaucrat const & executor) const;
};


#endif //CPP05EX03_PRESIDENTIALPARDONFORM_H
