//
// Created by 本間優之介 on 2023/02/25.
//

#include "RobotomyRequestForm.h"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("no_name",
			required_grade_to_sign,
			required_grade_to_exec),
			target_("no_name") {

}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm(target,
			required_grade_to_sign,
			required_grade_to_exec),
			target_(target) {

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src): AForm(src), target_(src.target_) {

}

RobotomyRequestForm::~RobotomyRequestForm() {

}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &src) {
	this->AForm::operator=(src);
	const_cast<std::string&>(this->target_) = src.target_;
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	AForm::isExecutable(executor);
	if (std::rand() % 2 == 0) {
		std::cout << target_ << " has been robotomized successfully" << std::endl;
	} else {
		std::cout << "The " << target_ << " robotomy failed" << std::endl;
	}
}