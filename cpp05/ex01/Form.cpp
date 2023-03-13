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
	assertGradeIsInRange(grade_to_sign);
	assertGradeIsInRange(grade_to_exec);
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
	if (this != &src) {
		const_cast<std::string &>(name_) = src.name_;
		signed_flag_ = src.signed_flag_;
		const_cast<int &>(grade_to_sign_) = src.grade_to_sign_;
		const_cast<int &>(grade_to_exec_) = src.grade_to_exec_;
		std::cout << "Form " << name_ << " is copied (by =operator)" << std::endl;
	}
	return *this;
}

const std::string& Form::getName() const {
	return name_;
}

bool Form::getSignedFlag() const {
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

void Form::assertGradeIsInRange(int grade) const {
	if (grade < highest_grade_) {
		throw GradeTooHighException();
	} else if (grade > lowest_grade_) {
		throw GradeTooLowException();
	}
}

// GradeTooHighException
Form::GradeTooHighException::GradeTooHighException(): std::out_of_range("Grade is too high!") {

}

// GradeTooLowException
Form::GradeTooLowException::GradeTooLowException(): std::out_of_range("Grade is too low!") {

}

std::ostream& operator<<(std::ostream &ostream, const Form& Form) {
	return ostream << "Form_name: " << Form.getName() << "\n"
			<< "signed_flag: " << std::boolalpha << Form.getSignedFlag() << std::noboolalpha << "\n"
			<< "Grade_to_sign: " << Form.getGradeToSign() << "\n"
			<< "Grade_to_sign: " << Form.getGradeToExec();
}