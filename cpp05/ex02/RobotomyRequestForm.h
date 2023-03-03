//
// Created by 本間優之介 on 2023/02/25.
//

#ifndef CPP05EX02_ROBOTOMYREQUESTFORM_H
#define CPP05EX02_ROBOTOMYREQUESTFORM_H

#include "AForm.h"
//#include <ctime>

class RobotomyRequestForm: public AForm{
private:
	const std::string target_;
	const static int required_grade_to_sign = 72;
	const static int required_grade_to_exec = 45;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& src);
	~RobotomyRequestForm();

	RobotomyRequestForm& operator=(const RobotomyRequestForm& src);

	void execute(Bureaucrat const & executor) const;
};


#endif //CPP05EX02_ROBOTOMYREQUESTFORM_H
