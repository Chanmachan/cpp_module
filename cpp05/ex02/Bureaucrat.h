//
// Created by 本間優之介 on 2023/02/20.
//

#ifndef CPP05EX00_BUREAUCRAT_H
#define CPP05EX00_BUREAUCRAT_H

#include <iostream>
#include <stdexcept>

class AForm;

class Bureaucrat {
private:
	const std::string name_;
	int grade_;

public:
	static const int highest_grade_ = 1;
	static const int lowest_grade_ = 150;
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& src);
	~Bureaucrat();

	Bureaucrat& operator=(const Bureaucrat& src);

	const std::string& getName() const;
	int getGrade() const;

	void incrementGrade();
	void decrementGrade();

	void signForm(AForm& Form) const;

	// 例外クラスを継承することで自分が拾いたい例外が発生したときに処理を足したりできる
	// 定義された範囲を超えてアクセスされたことを通知
	class GradeTooHighException: public std::out_of_range {
	private:// privateだからコンパイルエラー
		GradeTooHighException& operator=(const GradeTooHighException& src);
	public:
		// std::out_of_rangeクラスはデフォルトコンストラクタ必須(ないとコンパイルエラー)
		// 初期化の段階でエラーメッセージを入力しておく->whatのオーバーライドは必要ない
		GradeTooHighException();
		GradeTooHighException(const GradeTooHighException& src);
		// 例外を投げないことを保証するのを明示的に書く
		~GradeTooHighException() _NOEXCEPT; //_NOEXCEPTはないとコンパイルエラー
		// #  define _NOEXCEPT throw() -> throw()の引数なしだから何もthrowしないの意味
	};

	class GradeTooLowException: public std::out_of_range {
	private:
		GradeTooLowException& operator=(const GradeTooLowException& src);
	public:
		GradeTooLowException();
		GradeTooLowException(const GradeTooLowException& src);
		~GradeTooLowException() _NOEXCEPT;
	};
};

std::ostream& operator<<(std::ostream &ostream, const Bureaucrat& Bureaucrat);

#endif //CPP05EX00_BUREAUCRAT_H
