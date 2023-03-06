//
// Created by 本間優之介 on 2023/02/23.
//

#include "Form.h"
#include "Bureaucrat.h"

Form::Form(const std::string& name,
		   int grade_to_sign,
		   int grade_to_exec)
		   : name_(name),
		   signed_flag_(false),
		   grade_to_sign_(lowest_grade_),
		   grade_to_exec_(lowest_grade_) {
	if (grade_to_sign < highest_grade_) {
		throw Form::GradeTooHighException();
	} else if (grade_to_sign > lowest_grade_) {
		throw Form::GradeTooLowException();
	} else if (grade_to_exec < highest_grade_) {
		throw Form::GradeTooHighException();
	} else if (grade_to_exec > lowest_grade_) {
		throw Form::GradeTooLowException();
	}
	const_cast<int&>(grade_to_sign_) = grade_to_sign;
	const_cast<int&>(grade_to_exec_) = grade_to_exec;
	std::cout << "Form " << name_ << " was created" << std::endl;
}

Form::Form(const Form &src)
			: name_(src.name_),
			signed_flag_(src.signed_flag_),
			grade_to_sign_(src.grade_to_sign_),
			grade_to_exec_(src.grade_to_exec_) {
	std::cout << "Form " << name_ << " was copied" << std::endl;
}

Form::~Form() {
	std::cout << "Form " << name_ << " was shredded" << std::endl;
}

Form& Form::operator=(const Form& src) {
	const_cast<std::string&>(name_) = src.name_;
	signed_flag_ = src.signed_flag_;
	const_cast<int&>(grade_to_sign_) = src.grade_to_sign_;
	const_cast<int&>(grade_to_exec_) = src.grade_to_exec_;
	std::cout << "Form " << name_ << " is copied (by =operator)" << std::endl;
	return *this;
}

const std::string& Form::getName() const {
	return name_;
}

int Form::getSignedFlag() const {
	return signed_flag_;
}

int Form::getGradeToSign() const {
	return grade_to_sign_;
}

int Form::getGradeToExec() const {
	return grade_to_exec_;
}

void Form::beSigned(const Bureaucrat& Bureaucrat) {
	// grade100 > grade_to_sign20 -> throw
	if (Bureaucrat.getGrade() > grade_to_sign_) {
		throw Form::GradeTooLowException();
	}
	signed_flag_ = true;
}

// GradeTooHighException
Form::GradeTooHighException::GradeTooHighException(): std::out_of_range("Grade is too high!") {

}

Form::GradeTooHighException::GradeTooHighException(const Form::GradeTooHighException &src): std::out_of_range(src.what()) {

}

Form::GradeTooHighException::~GradeTooHighException() _NOEXCEPT {

}

// GradeTooLowException
Form::GradeTooLowException::GradeTooLowException(): std::out_of_range("Grade is too low!") {

}

Form::GradeTooLowException::GradeTooLowException(const Form::GradeTooLowException &src): std::out_of_range(src.what()) {

}

Form::GradeTooLowException::~GradeTooLowException() _NOEXCEPT {

}

std::ostream& operator<<(std::ostream &ostream, const Form& Form) {
	return ostream << "Form_name: " << Form.getName() << std::endl
			<< "signed_flag: " << Form.getSignedFlag() << std::endl
			<< "Grade_to_sign: " << Form.getGradeToSign() << std::endl
			<< "Grade_to_sign: " << Form.getGradeToExec() << std::endl;
}