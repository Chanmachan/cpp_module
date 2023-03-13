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
	static const int highest_grade_ = 1;
	static const int lowest_grade_ = 150;
	Form();
	static void assertGradeIsInRange(int grade) ;
public:
	Form(const Form& src);
	Form(const std::string& name, int grade_to_sign, int grade_to_exec);
	~Form();

	Form& operator=(const Form& src);

	const std::string& getName() const;
	bool getSignedFlag() const;
	int getGradeToSign() const;
	int getGradeToExec() const;

	void beSigned(const Bureaucrat& Bureaucrat);

	class GradeTooHighException: public std::out_of_range {
	public:
		GradeTooHighException();
	};

	class GradeTooLowException: public std::out_of_range {
	public:
		GradeTooLowException();
	};
};

std::ostream& operator<<(std::ostream& ostream, const Form& Form);


#endif //CPP05EX01_FORM_H
