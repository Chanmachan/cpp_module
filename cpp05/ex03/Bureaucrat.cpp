//
// Created by 本間優之介 on 2023/02/20.
//

#include "Bureaucrat.h"

Bureaucrat::Bureaucrat(): name_("Jorn Doe"), grade_(150) {
	std::cout << "Hi! I'm " << name_ << ", grade " << grade_ << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade): name_(name) {
	if (grade < highest_grade_) {
		throw Bureaucrat::GradeTooHighException();
	} else if (grade > lowest_grade_) {
		throw Bureaucrat::GradeTooLowException();
	} else {
		this->grade_ = grade;
	}
	std::cout << "Hi! I'm " << name_ << ", grade " << grade_ << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src): name_(src.name_), grade_(src.grade_) {
	std::cout << name_ << " Copy Constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat " << name_ << " byebye ٩( ᐛ )و" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &src) {
	if (this != &src) {
		const_cast<std::string &>(this->name_) = src.name_;
		// thisとsrcのアドレスが同じだったときの処理を書いた方が安全
		this->grade_ = src.grade_;
		std::cout << name_ << " Copy assignment operator called" << std::endl;
	}
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
		throw Bureaucrat::GradeTooHighException();
	}
	grade_ -= 1;
}

void Bureaucrat::decrementGrade() {
	if (grade_ + 1 > lowest_grade_) {
		throw Bureaucrat::GradeTooLowException();
	}
	grade_ += 1;
}

void Bureaucrat::signForm(AForm& AForm) const {
	try {
		AForm.beSigned(*this);
		std::cout << name_ << " signed " << AForm.getName() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << name_ << " couldn't sign " << AForm.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm &AForm) const {
	try {
		AForm.execute(*this);
		std::cout << name_ << " executed " << AForm.getName() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Cannot execute: " << e.what() << std::endl;
	}
}

// GradeTooHighException
Bureaucrat::GradeTooHighException::GradeTooHighException(): std::out_of_range("Grade is too high!") {

}

// GradeTooLowException
Bureaucrat::GradeTooLowException::GradeTooLowException(): std::out_of_range("Grade is too low!") {

}

std::ostream& operator<<(std::ostream &ostream, const Bureaucrat& Bureaucrat) {
	return ostream << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade();
}