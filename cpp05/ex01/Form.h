//
// Created by 本間優之介 on 2023/02/23.
//

#ifndef CPP05EX01_FORM_H
#define CPP05EX01_FORM_H

#include <iostream>

class Form {
private:
	const std::string name_;
	bool signed_flag_;
	const unsigned int grade_to_sign_;
	const unsigned int grade_to_exec_;
	Form();
public:
	Form(const Form& src);
	~Form();

	Form& operator=(const Form& src);

	void beSigned();

	class GradeTooHighException: public std::out_of_range {
	private:
		GradeTooHighException(const GradeTooHighException& src);
		GradeTooHighException& operator=(const GradeTooHighException& src);
	public:
		GradeTooHighException();
		~GradeTooHighException() _NOEXCEPT;
	};

	class GradeTooLowException: public std::out_of_range {
	private:
		GradeTooLowException(const GradeTooLowException& src);
		GradeTooLowException& operator=(const GradeTooLowException& src);
	public:
		GradeTooLowException();
		~GradeTooLowException() _NOEXCEPT;
	};
};

std::ostream& operator<<(std::ostream& ostream, const Form& Form);


#endif //CPP05EX01_FORM_H
