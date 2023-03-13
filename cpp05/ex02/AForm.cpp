//
// Created by 本間優之介 on 2023/02/23.
//

#include "AForm.h"

AForm::AForm(const std::string& name,
		   int grade_to_sign,
		   int grade_to_exec)
		   : name_(name),
		   signed_flag_(false),
		   grade_to_sign_(lowest_grade_),
		   grade_to_exec_(lowest_grade_) {
	assertGradeIsInRange(grade_to_sign);
	assertGradeIsInRange(grade_to_exec);
	const_cast<int&>(grade_to_sign_) = grade_to_sign;
	const_cast<int&>(grade_to_exec_) = grade_to_exec;
	std::cout << "AForm " << name_ << " was created" << std::endl;
}

AForm::AForm(const AForm &src)
			: name_(src.name_),
			signed_flag_(src.signed_flag_),
			grade_to_sign_(src.grade_to_sign_),
			grade_to_exec_(src.grade_to_exec_) {
	std::cout << "AForm " << name_ << " was copied" << std::endl;
}

AForm::~AForm() {
	std::cout << "AForm " << name_ << " was shredded" << std::endl;
}

AForm& AForm::operator=(const AForm& src) {
	if (this != &src) {
		const_cast<std::string &>(name_) = src.name_;
		signed_flag_ = src.signed_flag_;
		const_cast<int &>(grade_to_sign_) = src.grade_to_sign_;
		const_cast<int &>(grade_to_exec_) = src.grade_to_exec_;
		std::cout << "Form " << name_ << " is copied (by =operator)" << std::endl;
	}
	return *this;
}

const std::string& AForm::getName() const {
	return name_;
}

int AForm::getSignedFlag() const {
	return signed_flag_;
}

int AForm::getGradeToSign() const {
	return grade_to_sign_;
}

int AForm::getGradeToExec() const {
	return grade_to_exec_;
}

void AForm::beSigned(const Bureaucrat& Bureaucrat) {
	// grade100 > grade_to_sign20 -> throw
	if (Bureaucrat.getGrade() > grade_to_sign_) {
		throw AForm::GradeTooLowException();
	}
	signed_flag_ = true;
}

void AForm::assertGradeIsInRange(int grade) {
	if (grade < highest_grade_) {
		throw GradeTooHighException();
	} else if (grade > lowest_grade_) {
		throw GradeTooLowException();
	}
}

void AForm::isExecutable(const Bureaucrat& executor) const {
	if (!getSignedFlag()) {
		throw std::logic_error("Form is not signed");
	} else if (executor.getGrade() > grade_to_exec_) {
		throw AForm::GradeTooLowException();
	}
}

// GradeTooHighException
AForm::GradeTooHighException::GradeTooHighException(): std::out_of_range("Grade is too high!") {

}

// GradeTooLowException
AForm::GradeTooLowException::GradeTooLowException(): std::out_of_range("Grade is too low!") {

}

std::ostream& operator<<(std::ostream &ostream, const AForm& AForm) {
	return ostream << "Form_name: " << AForm.getName() << "\n"
				   << "signed_flag: " << std::boolalpha << AForm.getSignedFlag() << std::noboolalpha << "\n"
				   << "Grade_to_sign: " << AForm.getGradeToSign() << "\n"
				   << "Grade_to_sign: " << AForm.getGradeToExec();
}