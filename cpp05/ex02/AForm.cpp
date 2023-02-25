//
// Created by 本間優之介 on 2023/02/23.
//

#include "AForm.h"
#include "Bureaucrat.h"

// Formのコンストラクタは1~150の境界線は指定がなかったので無視
AForm::AForm(const std::string& name,
		   int grade_to_sign,
		   int grade_to_exec)
		   : name_(name),
		   signed_flag_(false),
		   grade_to_sign_(grade_to_sign),
		   grade_to_exec_(grade_to_exec) {
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
	const_cast<std::string&>(name_) = src.name_;
	signed_flag_ = src.signed_flag_;
	const_cast<int&>(grade_to_sign_) = src.grade_to_sign_;
	const_cast<int&>(grade_to_exec_) = src.grade_to_exec_;
	std::cout << "AForm " << name_ << " is copied (by =operator)" << std::endl;
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

// GradeTooHighException
AForm::GradeTooHighException::GradeTooHighException(): std::out_of_range("Grade is too high!") {

}

AForm::GradeTooHighException::GradeTooHighException(const AForm::GradeTooHighException &src): std::out_of_range(src.what()) {

}

AForm::GradeTooHighException::~GradeTooHighException() _NOEXCEPT {

}

// GradeTooLowException
AForm::GradeTooLowException::GradeTooLowException(): std::out_of_range("Grade is too low!") {

}

AForm::GradeTooLowException::GradeTooLowException(const AForm::GradeTooLowException &src): std::out_of_range(src.what()) {

}

AForm::GradeTooLowException::~GradeTooLowException() _NOEXCEPT {

}

std::ostream& operator<<(std::ostream &ostream, const AForm& AForm) {
	return ostream << "Form_name: " << AForm.getName() << std::endl
			<< "signed_flag: " << AForm.getSignedFlag() << std::endl
			<< "Grade_to_sign: " << AForm.getGradeToSign() << std::endl
			<< "Grade_to_sign: " << AForm.getGradeToExec() << std::endl;
}