//
// Created by 本間優之介 on 2023/02/23.
//

#ifndef CPP05EX03_FORM_H
#define CPP05EX03_FORM_H

#include "Bureaucrat.h"
#include <iostream>

class Bureaucrat;

class AForm {
private:
	const std::string name_;
	bool signed_flag_;
	const int grade_to_sign_;
	const int grade_to_exec_;
	AForm();
public:
	AForm(const AForm& src);
	AForm(const std::string& name, int grade_to_sign, int grade_to_exec);
	virtual ~AForm();

	AForm& operator=(const AForm& src);

	const std::string& getName() const;
	int getSignedFlag() const;
	int getGradeToSign() const;
	int getGradeToExec() const;

	void beSigned(const Bureaucrat& Bureaucrat);
	// 派生クラスで上書き
	void isExecutable(const Bureaucrat& executor) const;
	virtual void execute(Bureaucrat const & executor) const = 0;

	class GradeTooHighException: public std::out_of_range {
	private:
		GradeTooHighException& operator=(const GradeTooHighException& src);
	public:
		GradeTooHighException();
		GradeTooHighException(const AForm::GradeTooHighException& src);
		~GradeTooHighException() _NOEXCEPT;
	};

	class GradeTooLowException: public std::out_of_range {
	private:
		GradeTooLowException& operator=(const GradeTooLowException& src);
	public:
		GradeTooLowException();
		GradeTooLowException(const AForm::GradeTooLowException& src);
		~GradeTooLowException() _NOEXCEPT;
	};
};

std::ostream& operator<<(std::ostream& ostream, const AForm& Form);


#endif //CPP05EX03_FORM_H
