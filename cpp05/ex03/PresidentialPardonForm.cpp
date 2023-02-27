//
// Created by 本間優之介 on 2023/02/25.
//

#include "PresidentialPardonForm.h"

PresidentialPardonForm::PresidentialPardonForm()
		: AForm("no_name",
				required_grade_to_sign,
				required_grade_to_exec),
		  target_("no_name"){

}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
		: AForm(target,
				required_grade_to_sign,
				required_grade_to_exec),
		  target_(target){

}

// AFormの引数にsrcを渡してうまくいくの面白い
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src): AForm(src), target_(src.target_) {

}

PresidentialPardonForm::~PresidentialPardonForm() {

}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &src) {
	this->AForm::operator=(src);
	const_cast<std::string&>(this->target_) = src.target_;
	return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	AForm::isExecutable(executor);
	std::cout << target_ << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}