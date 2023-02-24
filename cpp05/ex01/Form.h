//
// Created by 本間優之介 on 2023/02/23.
//

#ifndef CPP05EX01_FORM_H
#define CPP05EX01_FORM_H

#include <iostream>

class Bureaucrat;

class Form {
private:
	const std::string name_;
	bool signed_flag_;
	const int grade_to_sign_;
	const int grade_to_exec_;
	Form();
public:
	Form(const Form& src);
	Form(const std::string& name, int grade_to_sign, int grade_to_exec);
	~Form();

	Form& operator=(const Form& src);

	const std::string& getName() const;
	int getSignedFlag() const;
	int getGradeToSign() const;
	int getGradeToExec() const;

	void beSigned(const Bureaucrat& Bureaucrat);

	class GradeTooHighException: public std::out_of_range {
	private:
		GradeTooHighException& operator=(const GradeTooHighException& src);
	public:
		GradeTooHighException();
		GradeTooHighException(const Form::GradeTooHighException& src);
		~GradeTooHighException() _NOEXCEPT;
	};

	class GradeTooLowException: public std::out_of_range {
	private:
		GradeTooLowException& operator=(const GradeTooLowException& src);
	public:
		GradeTooLowException();
		GradeTooLowException(const Form::GradeTooLowException& src);
		~GradeTooLowException() _NOEXCEPT;
	};
};

std::ostream& operator<<(std::ostream& ostream, const Form& Form);


#endif //CPP05EX01_FORM_H
