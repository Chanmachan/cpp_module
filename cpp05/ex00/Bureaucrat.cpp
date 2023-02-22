//
// Created by 本間優之介 on 2023/02/20.
//

#include "Bureaucrat.h"

Bureaucrat::Bureaucrat(): name_("Jorn Doe"), grade_(150) {
	std::cout << "Hi! I'm " << name_ << ", grade " << grade_ << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade): name_(name) {
	if (grade < highest_grade_) {
		throw GradeTooHighException();
	} else if (grade > lowest_grade_) {
		throw GradeTooLowException();
	} else {
		this->grade_ = grade;
	}
	std::cout << "Hi! I'm " << name_ << ", grade " << grade_ << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src): name_(src.name_), grade_(src.grade_) {
	std::cout << "Copy Constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat() {

}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &src) {
	const_cast<std::string&>(this->name_) = src.name_;
	// thisとsrcのアドレスが同じだったときの処理を書いた方が安全
	this->grade_ = src.grade_;
	return *this;
}

const std::string& Bureaucrat::getName() const {
	return this->name_;
}

int Bureaucrat::getGrade() const {
	return this->grade_;
}

void Bureaucrat::incrementGrade() {
	if (grade_ - 1 < highest_grade_) {
		throw Bureaucrat::GradeTooLowException();
	}
	grade_ -= 1;
}

void Bureaucrat::decrementGrade() {
	if (grade_ + 1 > lowest_grade_) {
		throw Bureaucrat::GradeTooLowException();
	}
	grade_ += 1;
}

// GradeTooHighException
Bureaucrat::GradeTooHighException::GradeTooHighException(): std::out_of_range("Grade is too high!") {

}

Bureaucrat::GradeTooHighException::~GradeTooHighException() _NOEXCEPT {

}

// GradeTooLowException
Bureaucrat::GradeTooLowException::GradeTooLowException(): std::out_of_range("Grade is too low!") {

}

Bureaucrat::GradeTooLowException::~GradeTooLowException() _NOEXCEPT {

}

std::ostream& operator<<(std::ostream &ostream, const Bureaucrat& Bureaucrat) {
	return ostream << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade();
}